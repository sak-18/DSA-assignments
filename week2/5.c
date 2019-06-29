#include<stdio.h>
int n,count;
int arr[1000][1000]={};
int factor[1000]={};
int visited[1000]={};

int abs(int a)
{
	return a>0 ? a : -1*a;
}

void make_graph(int t,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(abs(factor[i]-factor[j])>=t)
				arr[i][j]=1;
		}
	}
}

int DFS(int u)
{
	visited[u]=count;
	for(int v=0;v<n;v++)
	{
		if(arr[u][v]==1 && visited[v]==0)
		{			
			DFS(v);
		}
	}
}

int main()
{
	printf("\nEnter n:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("\nEnter factor of vertex %2d",i);
		scanf("%d",&factor[i]);
	}
	
	int threshold;
	printf("\nThreshold:");
	scanf("%d",&threshold);
	
	make_graph(threshold,n);
	count=1;
	for(int i=0;i<n;i++)
	{		
		if(visited[i]==0)
		{
			DFS(i);		
			count++;
		}
	}
	count-=1;
	printf("\nvisited:");
	for(int i=0;i<n;i++)
	{
		printf("%d ",visited[i]);	
	}
	
	printf("\nNO. OF COMPONENTS:%d",count);
	
	for(int k=1;k<=count;k++)
	{
		printf("\n----GROUP %d-----\n",k);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				int x=0;
				if(visited[i] == k && visited[j] == k)
				{
					x=arr[i][j];					
				}
				printf("%d ",x);
			}
			printf("\n");
		}
	}
		
	return 0;
}

#include<stdio.h>
#include<math.h>

float dist[1000][1000];
int  path[1000][1000];
int x,y;
int n;
int  printpath(int u,int v)
{
	int array[1000]={};
	int ptr=0;
	int temp=u;
	printf("\nPath in while:");
	while(temp!=v)
	{
		printf("%d ",temp);
		array[ptr++]=temp;
		temp=path[temp][v];
	}
	printf("%d",temp);
	array[ptr++]=temp;
	
	int flag=0;
	for(int i=0;i<ptr;i++)
	{
		if(array[i]==x && flag==0)
			flag=1;
		else if(array[i]==y && flag==1)
			return 0;
	}
	
	//printf("\nPath:");
	for(int i=0;i<ptr;i++)
	{
		//printf("%d ",array[i]);
	}		
	return 1;
}

void Floyd()
{
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(dist[i][j]>dist[i][k]+dist[k][j])
				{
					dist[i][j]=dist[i][k]+dist[k][j];
					path[i][j]=path[i][k];
				}
			}
		}
	}
}

int main()
{
	
	scanf("%d",&n);

	scanf("%d %d",&x,&y);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j)
			{
				path[i][j]=i;
				dist[i][j]=0.0;
			}
			else
			{
				path[i][j]=-1;
				dist[i][j]=INFINITY;
			}
		}
	}
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		dist[a][b]=dist[b][a]=1.0;		
		path[a][b]=b;
		path[b][a]=a;		
	}
	
	Floyd();
	int count=0;
	for(int u=0;u<n;u++)
	{
		for(int v=0;v<n;v++)
		{
			if(u==v)
				continue;
			if(printpath(u,v))
				count++;
		}
	}
	printf("\n%d",count);
	printf("\npath:\n");

	for(int i=0;i<n;i++)
	{
		printf("\n");
		for(int j=0;j<n;j++)
		{
			printf("%3d",path[i][j]);
		}
	}

	printf("\ngraph:\n");	
	for(int i=0;i<n;i++)
	{
		printf("\n");
		for(int j=0;j<n;j++)
		{
			printf("%10f",dist[i][j]);
		}
	}
	
	return 0;
}

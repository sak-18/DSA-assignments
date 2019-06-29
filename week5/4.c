#include<stdio.h>

int graph_a[1000000][1000000]={};
int graph_d[1000000][1000000]={};

int visited_a[1000000]={};
int visited_d[1000000]={};

int nswaps(char c)
{	
	int sum=0;
	
	for(int i=0;i<1000000;i++)
	{
		if(c=='a'&&visited_a[i]==1)
		{
			int temp=i;
			int done=1;
			visited_a[i]=0;
			int count=0;
			
			while(!done)	
			{
				for(int j=0;j<1000000;j++)
				{	
					if(graph_a[temp][j]==1)
					{
						count++;
						temp=j;
						done=0;
						break;
					}	
				}
			}
			
			sum+=(count-1);			
		}
		if(c=='d'&& visited_d[i]==1)
		{
			int temp=i;
			int done=1;
			visited_d[i]=0;
			int count=0;
			
			while(!done)	
			{
				for(int j=0;j<1000000;j++)
				{	
					if(graph_d[temp][j]==1)
					{
						count++;
						temp=j;
						done=0;
						break;
					}	
				}
			}
			
			sum+=(count-1);			
			
		
		}
	}
	
	
	return sum;
}


void sort(int n,int arr[n],char c)
{
	for(int i=0;i<n;i++)
	{
		int done=1;
		for(int j=0;j<n-1;j++)
		{
			if(arr[j]<arr[j+1] && c=='d')
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				done=0;
			}
			
			else if(arr[j]>arr[j+1] && c=='a')
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				done=0;
			}
		}
				
		if(done)
			break;		
	}
}
void print(int n,int arr[n])
{
	printf("\n******************************\n");
	for(int i=0;i<n;i++)
	{
			printf("%d ",arr[i]);
	}		
	printf("\n******************************\n");
}
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	
	for(int i=0;i<n;i++)	
		scanf("%d",&arr[i]);
	int *asort=arr;
	int *dsort=arr;
	sort(n,asort,'a');
	sort(n,dsort,'d');
	print(n,asort);
	print(n,dsort);
	
	for(int i=0;i<n;i++)
	{
		int a=asort[i];
		int b=dsort[i];
		int c=arr[i];
		graph_a[a][c]=1;
		graph_d[b][c]=1;
		visited_a[a]=1;
		visited_d[b]=1;
	}
	
	int asc=nswaps('a');
	int des=nswaps('d');
	int res;
	asc>des?(res=des):(res=asc);
	printf("\n%d\n",res);
	return 0;
}

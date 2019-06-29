#include<stdio.h>

int flag=0;
int graph[100][100]={};
int coloured[100]={};
int n,m;
void DFS(int a,int colour)
{
	colour==1?(coloured[a]=2):(coloured[a]=1);
	
	for(int i=0;i<n;i++)
	{
		if(coloured[i]==coloured[a] && graph[a][i]==1)
		{
			flag=1;
			break;
		}
	}
	
	
	for(int i=0;i<n && !flag;i++)
	{
		if(coloured[i]==0 && graph[a][i]==1)
		{
			DFS(i,coloured[a]);
		}
	}
	
}

int main()
{
	
	scanf("%d %d",&n,&m);
	
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);		
		graph[a][b]=graph[b][a]=1;		
	}
	for(int i=0;i<n;i++)
	{
		if(coloured[i]==0)
		{
			DFS(i,2);
		}
	}
	
	if(flag)
		printf("\nNOT BIPARTITE");
	
	else
		printf("\nBIPARTITE");
	return 0;
}

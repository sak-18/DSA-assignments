#include<stdio.h>

int n,m;
int graph[1000][1000]={};
int visited[1000]={};
struct connection
{
	int a;
	int b;	
};

int is_connected(int removed)
{
	for(int i=0;i<m;i++)
	{
		if(i!=removed && visited[i]==0)
			return 0;
	}
	return 1;
}

void DFS(int removed,int u)
{
	visited[u]=1;
	for(int v=0;v<m;v++)
	{
		if(graph[u][v]==1 && v!=removed && visited[v]!=1)
		{
			DFS(removed,v);
		}
	}

}

int main()
{
	scanf("%d %d",&n,&m);
	struct connection edge[m];
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&edge[i].a,&edge[i].b);				
	}
	
	for(int i=0;i<m;i++)
	{
		for(int j=i+1;j<m;j++)
		{
			if(edge[i].a == edge[j].a || edge[i].a == edge[j].b || edge[i].b == edge[j].a || edge[i].b == edge[j].b)
				graph[i][j]=graph[j][i]=1;
		}
	}
	
	int flag=0;
	for(int i=0;i<m;i++)
	{
		DFS(i, i+1 % m);				 
		if(!is_connected(i))
		{
			flag=1;
			printf("\nDisconnected if edge %c is removed\n",'a'+i);
			for(int k=0;k<m;k++)
			{
				for(int j=0;j<m;j++)
				{
					int a=0;
					if( graph[k][j]==1 && k!=i && j!=i )
						a=1;
					
					printf("%2d ",a);
				}
				printf("\n");
			}
			
		}
		
	}
	
	if(!flag)
	{
		printf("No such node");
	}
	
	return 0;
}

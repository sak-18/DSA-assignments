#include<stdio.h>

int dist[1000]={};
int source=-1;
int graph[1000][1000]={};

int n;
void DFS(int dis,int vertex,int u)
{
	int temp=dis;
	int visited[1000]={};
	while(temp>0)
	{
		visited[u]=1;
		for(int i=0;i<n;i++)
		{
			if(graph[u][i]==1 && visited[i]!=1)
			{
				u=i;
				break;
			}
		}
		
		temp--;
	}
	graph[u][vertex]=graph[vertex][u]=1;
	
}

int main()
{
	
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&dist[i]);
	}
	
	int count=0;
	int visvertex[1000]={};
	while(count<n)
	{
		for(int i=0;i<n;i++)
		{
			if(count==0 && dist[i]==0)
			{
				source=i;
				break;
			}
			else if(count!=0 && dist[i]==count && visvertex[i]==0)
			{
				visvertex[i]=1;
				DFS(count-1,i,source);
			}	
		}
		count++;
	}
	int done=0;
	
	for(int i=0;i<n;i++)
	{
		if(dist[i]==2)
		{
			graph[source][i]=graph[i][source]=1;
			done=1;
		}
	}
	
	if(!done)
	{
		int u=-1,v=-1;
		for(int i=0;i<n;i++)
		{
			if(u==-1 && graph[source][i]==1)
			{
				u=i;
				continue;
			}
			if(u!=-1 && graph[source][i]==1)
			{
				v=i;
			}
		}
		graph[u][v]=graph[v][u]=1;
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(graph[i][j]==1)
			{
				printf("\n<%2d %2d>\n",i+1,j+1);
			}
		}
	}
	
	
	return 0;
}

#include<stdio.h>
#include<limits.h>

int graph[1000][1000]={};
int n,m;
int dist[1000]={};
int color[1000]={};
int parent[1000]={};
int queue[1000];
int top=-1;
int bot=-1;
int diameter=INT_MIN;
int from=-1,to=-1;
void enqueue(int i)
{
	bot+=1;
	queue[bot]=i;	
}

int dequeue()
{
	top+=1;
	return queue[top];
}

void display(int u)
{
	for(int v=u+1;v<n;v++)
	{
		if(diameter<dist[v])
		{
			diameter=dist[v];
			from=u;
			to=v;
		}
		printf("\nShortest path b/w %d and %d of distance:%d\n",v,u,dist[v]);
		int temp=v;
		while(!(parent[temp]==temp))
		{
			printf("%d->",temp);
			temp=parent[temp];
		}
		printf("%d",temp);
	}		
}

void BFS(int source)
{	
	for(int i=0;i<n;i++)
	{
		parent[i]=-1;
		color[i]=0;
		queue[i]=-1;
		dist[i]=INT_MAX;
	}
	
	enqueue(source);
	dist[source]=0;
	color[source]=1;
	parent[source]=source;
	while(top!=bot)//queue not empty
	{
		int a=dequeue();
		for(int i=0;i<n;i++)
		{
			if(graph[a][i]==1 && color[i]==0)
			{
				enqueue(i);
				color[i]=1;
				parent[i]=a;
				dist[i]=dist[a]+1;				
			}		
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
		BFS(i);
		display(i);
	}
	printf("\nDiameter of graph is %d from vertex %d to vertex %d\n",diameter,from,to);
	return 0;
}

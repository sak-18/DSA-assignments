#include<stdio.h>
#include<limits.h>

int graph[1000][1000];
int path[1000][1000];
int n,m;

void print(int u,int v)
{
	printf(" %d ",u+1);
	int temp=path[u][v];
	while(temp!=v)
	{
		printf("%d ",temp+1);
		temp=path[temp][v];
	}
	printf("%d ",v+1);
	
	temp=path[v][u];
	while(temp!=u)
	{
		printf("%d ",temp+1);
		temp=path[temp][u];
	}
	printf("%d ",u+1);
}

int min(int a,int b,int c)
{
	
	if(a!=INT_MAX && b!=INT_MAX && c!=INT_MAX)
	{
		return a<b+c?a:b+c;
	}
	
	else if(a==INT_MAX && b!=INT_MAX && c!=INT_MAX)
	{
		return b+c;
	}
	
	else if(a==INT_MAX &&( b==INT_MAX || c==INT_MAX))
	{
		return a;
	}
		
}
void Floyd()
{
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				int temp=graph[i][j];
				graph[i][j]=min(graph[i][j],graph[i][k],graph[k][j]);
				if(temp!=graph[i][j])
					path[i][j]=k;			
			}
		}
	}
}

int main()
{
	scanf("%d %d ",&n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			graph[i][j]=INT_MAX;
			path[i][j]=-1;
			if(i==j)
			{
				graph[i][j]=0;
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		graph[a][b]=c;
		path[a][b]=b;
	}
	
	Floyd();

	for(int i=0;i<n;i++)
	{
		printf("\n");
		for(int j=0;j<n;j++)
		{
			printf("%2d ",graph[i][j]);
		}
	}
	printf("\n\n\n");
	
	for(int i=0;i<n;i++)
	{
		printf("\n");
		for(int j=0;j<n;j++)
		{
			printf("%2d ",path[i][j]+1);
		}
	}
	int mini=INT_MAX;
	int u[1000],v[1000];
	int count=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{	
			if(i==j)
				continue;
			if(graph[i][j]==INT_MAX||graph[j][i]==INT_MAX)
				continue;
			else if(mini>graph[i][j]+graph[j][i])
			{	
				count=0;
				u[count]=i;
				v[count++]=j;
				mini=graph[i][j]+graph[j][i];
			}
			else if(mini==graph[i][j]+graph[j][i])
			{
				u[count]=i;
				v[count++]=j;				
			}
		}
	}
	printf("\nmin cycle weight:%d",mini);
	for(int i=0;i<count;i++)
	{
		printf("\nShortest cycle between %d and %d:",u[i]+1,v[i]+1);
		print(u[i],v[i]);
	}	
	printf("\n");
		
}

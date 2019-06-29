#include<stdio.h>
#include<limits.h>

int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

int maximum(int a,int b)
{
	return a>b?a:b;
}

void update(int i,int j,int n,int graph[n][n],int min[n][n],int visited[n][n])
{
	for(int a=0;a<4;a++)
	{
		if(i+dir[a][0]<0||i+dir[a][0]>n-1||j+dir[a][1]<0||j+dir[a][1]>n-1)
			continue;
		else
		{
			if(min[i+dir[a][0]][j+dir[a][1]]>maximum(min[i][j],graph[ i+dir[a][0] ] [ j+dir[a][1] ]))
			{
				min[i+dir[a][0]][j+dir[a][1]]=maximum( min[i][j], graph[ i+dir[a][0] ] [ j+dir[a][1] ]) ;
				update(i+dir[a][0],j+dir[a][1],n,graph,min,visited);				
			}
		}
	}
}

int findmin(int i,int j,int n,int graph[n][n],int min[n][n],int visited[n][n])
{
	if(i<0||j<0||i>n-1||j>n-1||visited[i][j])
		return INT_MAX;
	
	if(min[i][j]!=INT_MAX)
		return min[i][j];
	
	visited[i][j]=1;
	int mini=INT_MAX;
	
	for(int a=0;a<4;a++)
	{		
		int p=findmin(i+dir[a][0],j+dir[a][1],n,graph,min,visited);
		if(mini>p)
			mini=p;		
	}
	
	if(mini==INT_MAX)
	{
		visited[i][j]=0;
		return INT_MAX;
	}
	graph[i][j]<mini ? (min[i][j]=mini):(min[i][j]=graph[i][j]);
	update(i,j,n,graph,min,visited);
	visited[i][j]=0;
	return min[i][j];		
}

int main()
{
	int n;
	scanf("%d",&n);
	int graph[n][n];
	int min[n][n];
	int visited[n][n];
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&graph[i][j]);
			min[i][j]=INT_MAX;
			visited[i][j]=0;
		}
	}
	
	min[0][0]=graph[0][0];
	printf("\nRESULT:%d\nMIN:",findmin(n-1,n-1,n,graph,min,visited));	
	
	for(int i=0;i<n;i++)
	{	
		printf("\n\n");
		
		for(int j=0;j<n;j++)
		{
			printf("%3d",min[i][j]);
		}
	}
	
	return 0;
}

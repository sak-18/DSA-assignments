#include<stdio.h>
#include<math.h>

int graph[1000][1000]={};
float dist[1000][1000]={};
int n,m;

void at_distance(int t)
{
	printf("\nAT DISTANCE %d:",t);
	int none=1;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(dist[i][j]==t)
			{	
				none=0;
				printf("<%2d-%2d> ",i,j);
			}
		}
	}
	if(none)
	{
		printf("none");
	}
}

void print_dist()
{
	for(int i=0;i<n;i++)
	{	
		printf("\n");
		for(int j=0;j<n;j++)
		{
			printf("%12f ",dist[i][j]);
		}
	}	
}

float  min(float a,float b)
{
	printf("\nmin of %f ,%f is %f",a,b,a<b?a:b);
	return a<b?a:b;
}
void Floyd()
{
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}	
}

void draw_graph()
{
	
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);		
		graph[a][b]=1;
		a!=b ? (dist[a][b]=1.0):(dist[a][b]=0.0);			
	}
	printf("\nA\n");
	print_dist();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(graph[i][j]!=1 && i!=j)
			{
				dist[i][j] = INFINITY;
			}

		}
	}
	printf("\nB\n");
	print_dist();
	
	
		
}

int main()
{
	scanf("%d %d",&n,&m);
	int t;
	scanf("%d",&t);
	
	draw_graph();
	Floyd();
	print_dist();
	at_distance(t);
	return 0;
}

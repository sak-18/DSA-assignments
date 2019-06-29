#include<stdio.h>
#include<math.h>
	
int n,m;

float dist[1000][1000];

void print()
{
	int x=0;
	for(int i=0;i<n;i++)
	{
		int flag=1;
		for(int j=0;j<n;j++)
		{
			if(dist[i][j]==INFINITY)
				flag=0;
		}
		if(flag)
		{
			printf("%d ",i+1);
			x=1;
		}
	}
	if(!x)
	{
		printf("NO");
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
				if(dist[i][j]>dist[i][k]+dist[k][j])
				{
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
	}
}

void init_dist()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i!=j)
			{
				dist[i][j]=INFINITY;
			}
			else
			{
				dist[i][j]=0.0;
			}
		}
	}
}
int main()
{
	scanf("%d %d",&n,&m);
	init_dist();
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		dist[a-1][b-1]=1;	
	}
	Floyd();
	print();
}

#include<stdio.h>

int findlvl(int parent[],int i)
{
	if(parent[i]==i)
		return 0;
	return 1+findlvl(parent,parent[i]);	
}

int main()
{
	int n;
	printf("\nEnter n:");
	scanf("%d",&n);
	
	int parent[n];
	int visited[n];
	
	
	for(int i=0;i<n;i++)
	{
		visited[i]=0;
		parent[i]=i;
	}
	

	
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		printf("\nEdge b/w:");
		scanf("%d %d",&a,&b);
		parent[b-1]=a-1;
	}
	
	int m;
	printf("\nenter m:");
	scanf("%d",&m);
	
	for(int i=0;i<m;i++)
	{
		int x;
		printf("\nuniversity in:");
		scanf("%d",&x);
		visited[x-1]=1;		
	}
	
	int level=0;
	int found=0;
	while(!found && level<n)
	{
		printf("\nlevel:%d",level);
		for(int i=0;i<n;i++)
		{	
			printf("\n\nlevel of %d:%d,university:%d",i+1,findlvl(parent,i),visited[i]);
			if(visited[i] && level==findlvl(parent,i))
			{
				printf("\nUniverstity in city:%d",i+1);
				found=1;
				break;
			}
		}
		
		level++;
	}
	
	
		
	return 0;	
}

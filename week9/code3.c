#include<stdio.h>


void del(int i,int n,int par[n],int respect[n])
{
	for(int j=1;j<=n;j++)
	{
		if(par[j]==i)
		{
			par[j]=par[i];
			par[i]=i;
		}
	}	
}

int main()
{
	int n;
	scanf("%d",&n);
	
	int par[n+1];
	int respect[n+1];
	int res[n];
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&par[i],&respect[i]);	
		res[i]=0;
	}
	
	int done=0;
	int top=0;
	while(!done)
	{
		done=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(j==i)
					continue;
				if(par[j]==i && respect[j]==1 && respect[i]==1)
				{
					del(i,n,par,respect);					
					res[top++]=i;
					done=0;
					break;
				}	
			}
			if(done==0)
				break;			
		}
	}
	
	if(top==0)
		printf("-1");
	
	else
	for(int i=0;i<top;i++)
		printf("%d ",res[i]);
	
	
	return 0;
}

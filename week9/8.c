#include<stdio.h>
#include<limits.h>

int main()
{
	int k,w,n;
	scanf("%d %d %d",&k,&w,&n);
	
	int profit[n];
	int capital[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&profit[i]);
	}
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&capital[i]);
	}	
	int res=0;
	for(int i=0;i<k;i++)
	{
		int best_profit=0;
		int bestj=-1;
		for(int j=0;j<n;j++)
		{
			if(w>=capital[j] && profit[j]-capital[j]>best_profit )
			{
				best_profit=profit[j]-capital[j];
				bestj=j;
			}
			
		}
		
		if(best_profit==0||bestj==-1)
			break;
		
		w+=best_profit;
		res+=profit[bestj];
		profit[bestj]=-1;
	}
	printf("\n\nRes:%d\n",res);
	return 0;
}

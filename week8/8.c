#include<stdio.h>

void init (int n,int cumsum[n])
{
	for(int i=0;i<n;i++)
	{
		cumsum[i]=0;
	}
}

int solve(int n,int arr[n][n])
{
	int count=0;
	int cumsum[n];
	init(n,cumsum);
	for(int left=0;left<n;left++)
	{	
		init(n,cumsum);
		for(int right=left;right<n;right++)
		{
			
			for(int i=0;i<n;i++)
			{
				cumsum[i]+=arr[i][right];
			}
			
			for(int up=0;up<n;up++)
			{
				int sum=0;
				for(int down=up;down<n;down++)
				{
					sum+=cumsum[down];
					if(sum==1)
					{
						count++;
						printf("\nSubmatrix%3d left_top_x:%d left_top_y:%d right_bottom_x:%d right_bottom_y:%d",count,left,up,right,down);
					}
				}
			}
		}	
	}
	return count;
}

int main()
{
	int n;
	scanf("%d",&n);
	
	int arr[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	
	printf("\nCount:%d\n",solve(n,arr));	
	return 0;
}

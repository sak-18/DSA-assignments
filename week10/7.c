#include<stdio.h>

//O(n^2) algorithm
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	int count=0;
	
	for(int i=0;i<n;i++)
	{
		if(arr[i]==1)
		{
			arr[i]=++count;
		}
		
		else
		{
			arr[i]=count;
		}
	}
	
	int len,res=0;
	for(int l=0;l<n;l++)
	{
		for(int r=l+1;r<n;r++)
		{
			len=r-l+1;
			
			if(len%2==1 )
			{
				continue;
			}
			
			if(l==0)
			{
				if(arr[r]==len/2)
				{
					//prints subarray's left and right indices
					printf("\nSubarray %d to %d",l,r);
					res++;
				}
			}
			
			else			
			{
				if( (arr[r]-arr[l-1]) == len/2)
				{
					//prints subarray's left and right indices
					printf("\nSubarray %d to %d",l,r);
					res++;
				}
			}
		}
	}
	printf("\nCount:%d\n",res);
	
	//For debugging
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}

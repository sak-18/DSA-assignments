#include<stdio.h>

int min[15][15]={};

int minimum(int a,int b)
{
	return a<b?a:b;
}

int findmin(int size,int arr[size],int l,int r)
{
	if(l==r)
	{
		min[l][r]=arr[l];
		return arr[l];
	}
	if(min[l][r]!=0)
		return min[l][r];
	min[l][r]=minimum(arr[l],findmin(size,arr,l+1,r));
	findmin(size,arr,l,r-1);	
}

int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	for(int i=0;i<n;i++)
	{
		min[i][i]=arr[i];			
	}
	findmin(n,arr,0,n-1);	
	
	int sum=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			printf("\nmin[%d][%d]:%d",i,j,min[i][j]);		
			sum+=min[i][j];
		}
	}
	printf("\n\nMinsum:%d\n",sum);
	return 0;
}

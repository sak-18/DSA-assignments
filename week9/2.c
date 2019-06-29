#include<stdio.h>

int main()
{
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	int arr1[n];
	int arr2[m];
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr1[i]);		
	}
	
	for(int i=0;i<m;i++)
	{
		scanf("%d",&arr2[i]);		
	}
	
	int score=0;
	int l=0,r=0;
	int sum=0;
	while(1)
	{
		if(l>n&&r>m)
			break;
		
		if(l<n && r<m && arr1[l]<arr2[r])
		{
			sum+=arr1[l++];
			
		}
		
		else if(l<n && r<m && arr1[l]>=arr2[r])
		{
			sum+=arr2[r++];
		}
		else
		{
			if(l>=n)
			{
				sum+=arr2[r++];
			}
			else
			{
				sum+=arr1[l++];
			}	
		
		}
		
		if(sum>k)
			break;
		
		else
		{
			score++;
		}
	}
	
	printf("\nScore:%d\n",score);
	return 0;
}

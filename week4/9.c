#include<stdio.h>

int array[10000]={};

int main()
{
	int n;	
	scanf("%d",&n);	
	for(int i=0;i<n;i++)
		scanf("%d",&array[i]);
	
	int s;
	scanf("%d",&s);
	
	int low=0,high=n-1;
	int mid;
	while(low<=high)
	{
		mid=(high+low)/2;
		if(array[mid]==s)
		{
			printf("%s %d","Naruto",mid+1);
			return 0;
		}
		
		else if(array[mid]<s)
		{
			low=mid+1;
		}
		
		else
		{
			high=mid-1;
		}
	}
	
	array[mid] < s ? printf("Sakuto %d",mid+1+1) : printf("Sakuto %d",mid+1);	
	return 0;
}

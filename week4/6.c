#include<stdio.h>

int n;
int array[1000]={};

int search(int key,int l,int h)
{	
	while(l>=h)
	{
		mid=(l+h)/2;
		
		if(array[mid]==key)
			return mid;
		else if(array[mid]>key)
		{
			h=mid-1;
		}
		
		else
		{
			l=mid+1;
		}
	}
	return -1;
}

int main()
{
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&array[i]);	
	}
	int d;
	scanf("%d",&d);
	for(int i=n;i>0;i--)
	{
		int a=array[i];
		int flag=search(a-d,i+1,n-1);
		if(flag!=-1)
		{
			printf("\n%d",flag+a);
			break;
		}
	}
	return 0;
}

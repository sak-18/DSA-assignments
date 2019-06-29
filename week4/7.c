#include<stdio.h>

int array[1000]={};

int search(int l,int h,int key)
{
	printf("\n<%d %d>",l,h);
	int mid=(l+h)/2;
	if(array[mid]==key)
		return mid;
	else if(array[mid]<array[mid+1] && mid!=0 && array[mid]<array[mid-1])
	{
		int temp=array[mid];
		array[mid]=array[mid-1];
		array[mid]=temp;
	}
	else if(array[mid]>array[mid+1])
	{
		int temp=array[mid];
		array[mid]=array[mid+1];
		array[mid+1]=temp;		
	}	
	else if(l>h)
		return -1;
	else if(key>array[mid])
	{
		search(mid+1,h,key);
	}
	else
	{
		search(l,mid-1,key);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
		scanf("%d",&array[i]);
	
	int k;
	scanf("%d",&k);
	int l=0,h=n-1;
	printf("\n%d",search(l,h,k));
	
	return 0;
}

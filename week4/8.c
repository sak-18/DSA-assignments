#include<stdio.h>

int n;
int array[10000]={};
int piv=-1;
int find(int key,int l,int h)
{
	printf("\n<%d %d>",l,h);
	if(l>h)
		return -1;
	
	int mid=(l+h)/2;
	
	if(array[mid]==key)
	{
		return mid+1;
	}	
	
	else if(array[mid]<=array[h])
	{
		if(key>=array[mid] && key<=array[h])
			return find(key,mid+1,h);
		return find(key,l,mid-1);
	}	
	
	else if(array[l]<=array[mid])
	{
		if(key>=array[l] && key<=array[mid])
			return find(key,l,mid-1);
		return find(key,mid+1,h);
	}
	 	
}

int main()
{
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
		scanf("%d",&array[i]);		
	
	int l=0,h=n-1;	
	int k;
	
	scanf("%d",&k);	
	printf("\n%d",find(k,l,h));							
	
		
	return 0;
}

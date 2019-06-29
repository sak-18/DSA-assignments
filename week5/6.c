#include<stdio.h>
#include "mergesort.c"

int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	printf("\nCount:%d\n",mergesort(0,n-1,arr));
		
	return 0;
}

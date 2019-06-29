#include<stdio.h>
int n;

void print(int n,int arr[n])
{
	printf("\n******************************\n");
	for(int i=0;i<n;i++)
	{
			printf("%d ",arr[i]);
	}		
	printf("\n******************************\n");
}

void swap(int a,int b,int arr[])
{
	int temp=arr[a];
	arr[a]=arr[b];
	arr[b]=temp;
}

int partition(int s,int e,int arr[])
{
	int pivot=arr[s];
	int currptr=e;
	for(int i=e;i>=s+1;i--)
	{
		if(arr[i]>pivot)
		{
			swap(i,currptr,arr);
			currptr--;
		}
	}
	swap(s,currptr,arr);
	print(n,arr);
	printf("pivot:%d",pivot);	
	return currptr;
}

void quicksort(int start,int end,int arr[])
{
	if(start>end)
		return;
	int pi=partition(start,end,arr);
	quicksort(start,pi-1,arr);
	quicksort(pi+1,end,arr);
}

int main()
{
	
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	quicksort(0,n-1,arr);	
	print(n,arr);
	return 0;
}

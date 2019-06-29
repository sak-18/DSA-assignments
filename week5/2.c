#include<stdio.h>

void swap(int n,int arr[],int ind1,int ind2)
{
	int temp=arr[ind1];
	arr[ind1]=arr[ind2];
	arr[ind2]=temp;
}

int sort(int n,int start,int end,int arr[])
{
	for(int i=0;i<=end-start;i++)
	{	
		int done=1;
		for(int j=start;j<end;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(n,arr,j,j+1);
				done=0;
			}
		}
		if(done==1)
			return 1;
	}
}

void print(int n,int arr[])
{
	printf("\n");
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}


int main()
{
	int n,m;
	int array[1000]={};
	int arr[1000]={};
	
	scanf("%d ",&n);
	scanf("%d",&m);
	for(int i=0;i<n;i++)
		scanf("%d",&array[i]);
	
	int currptr=0;	
		
	for(int i=0;i<m;i++)
		scanf("%d",&arr[i]);
	
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(array[j]==arr[i])
			{
				swap(n,array,currptr,j);
				currptr++;
			}
		}		
	}
	sort(n,currptr,n-1,array);	
	print(n,array);
	return 0;
}

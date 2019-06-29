#include<stdio.h>

int size=0;
void heapify(int len,int arr[len],int num)
{
	size+=1;
	arr[size]=num;
			
	int curr = size;
	int par = size/2;
		
	while(arr[par]<num)
	{
		arr[curr]=arr[par];
		curr=par;
		par=par/2;
	}
		
	arr[curr]=num;
}

void heapifydown(int len,int arr[len])
{
	int key=arr[1];		
	int curr = 1;
	int child=curr*2;
	int x=1;		
	while(child<=size )
	{
		printf("\nLoop %d",x++);
		if(child+1<=size && arr[child+1]>arr[child])
		{
			child=child+1;
			printf("\nIF in loop %d",x++);		
		}
		
		if(arr[child]>key)
		{
			arr[curr]=arr[child];
		}
		else
		{
			break;
		}
		curr=child;
		child=child*2;
	}
	arr[curr]=key;	

		printf("\nPrinting heap\n\n");
		for(int i=0;i<size;i++)
			printf("%d ",arr[i+1]);

}



int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	
	int arr[n+1];
	arr[0]=9999999;
	int size=0;
	int num;			
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num);		
		heapify(n+1,arr,num);		
	}
	
	printf("\nPrinting heap\n\n");
	
	for(int i=0;i<n;i++)
		printf("%d ",arr[i+1]);
	
	
	int res=0;
	for(int i=0;i<k;i++)
	{
		res+=arr[1];
		arr[1]/=2;
		heapifydown(n+1,arr);

	}
	
	printf("\nResult is:%d",res);
	printf("\n");
	return 0;
}

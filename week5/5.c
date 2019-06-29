#include<stdio.h>

void sort(int n,int arr[n])
{
	for(int i=0;i<n;i++)
	{
		int done=1;
		for(int j=0;j<n-1;j++)
		{
			if(arr[j]<arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				done=0;
			}
		}
				
		if(done)
			break;		
	}
}

int search_rem(int r,int n,int arr[n])
{
	for(int i=n-1;i>=0;i--)
	{
		if(arr[i]%3==r && arr[i]!=-1)
		{
			arr[i]=-1;
			return 1;
		}	
	}
	return 0;
}

void remov(int n,int arr[n],int rem)
{
	if(rem==1)
	{
		if(search_rem(1,n,arr))
			return;
		else
		{
			search_rem(2,n,arr);
			search_rem(2,n,arr);
		}
	}
	else
	{
		if(search_rem(2,n,arr))
			return;
		else
		{
			search_rem(1,n,arr);
			search_rem(1,n,arr);
		}	
	
	}
}

void print(int n,int arr[n])
{
	printf("\n******************************\n");
	for(int i=0;i<n;i++)
	{
		if(arr[i]!=-1)
			printf("%d ",arr[i]);
	}		
	printf("\n******************************\n");
}

int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];	
	int sum=0;
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		sum+=arr[i];
	}
	
	int rem=sum%3;
	printf("\nrem:%d",rem);
	switch(rem)
	{
		case 0:
				sort(n,arr);
				break;
		case 1:
				sort(n,arr);
				print(n,arr);
				remov(n,arr,rem);
				break;
		case 2:
				sort(n,arr);
				print(n,arr);
				remov(n,arr,rem);
				break;		
	}
	
	print(n,arr);
			
	return 0;
}

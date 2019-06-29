#include<stdio.h>

void merge(int n,int arr[n],int l,int mid,int r)
{	
	int array[n];
	
	int done=0;
	for(int i=0,j=l,k=mid+1;i<n;i++)
	{
		if(done==0 && arr[j]<arr[k])
		{
			array[i]=arr[j];
			j++;
			if(j>mid)
			{
				done=1;
				continue;
			}
		}
		else if(done==0 && arr[j]>=arr[k])
		{
			array[i]=arr[k];
			k++;
			if(k>r)
			{
				done=2;
				continue;
			}
		}
		
		if(done==1)
		{
			array[i]=arr[k];
			k++;	
		}
		
		if(done==2)
		{
			array[i]=arr[j];
			j++;
		}
	}
	
	int ind=0;
	for(int i=l;i<=r;i++)
	{
		arr[i]=array[ind++];
	}
}

//l and r inclusive
void mergesort(int n,int arr[n],int l,int r)
{
	if(l>=r)
		return;
	int mid=(l+r)/2;
	
	mergesort(n,arr,l,mid);
	mergesort(n,arr,mid+1,r);
	
	merge(n,arr,l,mid,r);
}



int main()
{
	int n;
	scanf("%d",&n);
	
	int arr[n];
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}

	mergesort(n,arr,0,n-1);
	
	printf("\nSorted array:");
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}

	int num1=0,num2=0;
	
	for(int i=0;i<n;i++)
	{
		if(i%2==0)
			num1=num1*10+arr[i];
		else
			num2=num2*10+arr[i];
	}
	
	printf("\nnum1:%d num2:%d sum:%d",num1,num2,num1+num2);
	
	return 0;
}

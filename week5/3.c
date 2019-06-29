#include<stdio.h>
#include<string.h>
int n;

void swap(int n,int arr[],int ind1,int ind2)
{
	int temp=arr[ind1];
	arr[ind1]=arr[ind2];
	arr[ind2]=temp;
}

int search(int n,int arr[],int key)
{
	for(int i=0;i<n;i++)
		if(arr[i]==key)
			return i;
	return -1;		
}

int swap_elem(int n,int arr[],int a,int b)
{
	int ind1=search(n,arr,a);
	int ind2=search(n,arr,b);
	
	if(ind1==-1||ind2==-1)
		return -1;
	swap(n,arr,ind1,ind2);
	return 0;
}

int delete(int n,int arr[],int num)
{
	int index=search(n,arr,num);
	
	if(index==-1)
		return -1;	
	
	for(int i=index;i<n-1;i++)
	{
		arr[i]=arr[i+1];
	}
	
	return 0;
}

void insert(int n,int arr[],int num)
{
	printf("\nINSERT");
	int ind=search(n,arr,num);
	if(ind!=-1)
	{	
		int i;
		
		for(i=n;i>ind;i--)
		{
			arr[i]=arr[i-1];
		}
		
		arr[i]=num;		
	}
	
	else
	{
		int i;
		for( i=0;i<n;i++)
		{
			if(arr[i]>=num)
				break;
		}
		
		int j;
		
		for(j=n;j>i;j--)
		{
			arr[j]=arr[j-1];
		}
		
		arr[j]=num;		
			
	}
					
}

void print(int n,int arr[])
{
	printf("\n");
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}

int sort(int n,int arr[])
{
	for(int i=0;i<n;i++)
	{	
		int done=1;
		for(int j=0;j<n-1;j++)
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
int main()
{
	
	scanf("%d",&n);
	
	int arr[1000000];
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	int x;
	scanf("%d",&x);
	for(int i=0;i<x;i++)
	{	
		char str[2]={};
		scanf("%s",str);
		int num,num2;
		//printf("\nHERE");
		if(strcmp("SW",str)==0)
			scanf("%d %d",&num,&num2);
		else
		{
			scanf("%d",&num);
		}	
		//printf("\nHERE");
		int err;
		if(strcmp(str,"SO")==0)
			err=sort(n,arr);
		else if(strcmp(str,"I")==0)
			insert(n++,arr,num);
		else if(strcmp(str,"D")==0)
			err=delete(n--,arr,num);
		else if(strcmp(str,"SW")==0)
			err=swap_elem(n,arr,num,num2);
		if(err==-1)
		{
			printf("NO CHANGE");
		}
		print(n,arr);
		printf("\nn:%d\n",n);			
	}
	return 0;
}	

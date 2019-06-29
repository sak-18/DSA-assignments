#include<stdio.h>

/*worst case complexity:O(n^2)*/

//O(n)
void print(int n,int arr[])
{
	printf("\nSorted list :");
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}

//O(n^2)
void sort(int n,int arr[n])
{

	for(int i=0;i<n;i++)
	{
		int done=1;
		for(int j=0;j<n-1;j++)
		{
			if(arr[j]>arr[j+1])
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
	print(n,arr);
	printf("\n");
}


int main()
{
	int n;
	scanf("%d",&n);
	int arr[n],connection[n];
 	
 	//O(n)
 	//scanning array and init connections
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		connection[i]=i;//index wise positioning
	}
	
	int a;
	
	//O(n^2)
	//construct connections
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{	
			scanf("%d",&a);
			if(j>i)
			continue;
				if(a==1)
				{
					connection[j]=connection[i];//if i,j==1 then j is connected to y ,so making connection of j==connection of y
				}
		}
	}
	
	int stack[100][100]={};// row i corresponds to ith component
	int ptr[100]={};// length of each row()
	int ptr2[100]={};	

	//O(n)
	//build stack
	for(int i=0;i<n;i++)
	{
		int a=connection[i];
		int b=ptr[a];
		stack[a][b]=arr[i];
		ptr[a]+=1;
	}

	//sorting(O(n^2))
	for(int i=0;i<n;i++)
	{
		sort(ptr[i],stack[i]);
	}
	
	printf("\nSorted list:\n");
	
	//O(n^2)
	//printing O(n)
	for(int i=0;i<n;i++)
	{
		int a=connection[i];
		int b=ptr2[a];
		printf("%d ",stack[a][b]);
		ptr2[a]+=1;		
	}		
	printf("\n");
	return 0;
}

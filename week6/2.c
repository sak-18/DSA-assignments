#include<stdio.h>

typedef struct pair
{
	int x;
	int y;
}pair;

int count=0;
pair vector[100];

void sort(int k, int n, int arr[k][n], int order)
{
	for(int i=0;i<n;i++)
	{
		
		for(int j=i+1;j<n;j++)
		{
			int filled=0;
			for(int ind=0;ind<k;ind++)
			{				
				if( (order==0 && arr[ind][i]>arr[ind][j]) || (order==1 && arr[ind][i]<arr[ind][j]) )
				{
					int temp=arr[ind][i];
					arr[ind][i]=arr[ind][j];
					arr[ind][j]=temp;
					
					
					if(!filled)
					{
						vector[count].x=i;
						vector[count++].y=j;
						filled=1;
					}
				}
			}
		}
	}
}

void print(int k,int n,int arr[k][n])
{
	printf("\nPrinting\n");
	for(int i=0;i<k;i++)
	{
		printf("\n");
		for(int j=0;j<n;j++)
		{
			printf("%2d",arr[i][j]);						
		}
	}
}

int main()
{
	int n,k,order;	
	
	scanf("%d %d %d",&k,&n,&order);	
	int arr[k][n];	
	//printf("\n%d %d size:%lu\n",n,k,sizeof(arr));
	for(int a=0;a<k;a++)
	{
		for(int b=0;b<n;b++)
		{
			scanf("%d",&arr[a][b]);				
		}
	}
	print(k,n,arr);
	sort(k,n,arr,order);
	print(k,n,arr);
	printf("\ncount:%d\n",count);	
	for(int i=0;i<count;i++)
	{
		printf("\n");
		printf("%2d %2d",vector[i].x,vector[i].y);
	}
	printf("\n");
	return 0;
}

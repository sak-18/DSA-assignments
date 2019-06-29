#include<stdio.h>


int dp[100][100];

int s=-1,e=-1;
void print(int n,int arr[n])
{
	printf("\n******************************\n");
	for(int i=0;i<n;i++)
	{
			printf("%d ",arr[i]);
	}		
	printf("\n******************************\n");
}

int min(int a,int b)
{
	return a>b?b:a;
}

int minremovals(int start,int end,int arr[])
{
	if(start>end)
		return 0;
	else if(arr[start]*2>=arr[end] && (arr[start]!=arr[start+1] && arr[end]!=arr[end-1]) )
	{
		s=start;
		e=end;
		return 0;
	}
		
	else
	{		
		return 1+min(minremovals(start+1,end,arr),minremovals(start,end-1,arr));
	}		

}

void sort(int n,int arr[n])
{
	print(n,arr);
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
}
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<100;j++)
		{
			dp[i][j]=-1;
		}
	}
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	print(n,arr);
	sort(n,arr);
	print(n,arr);
	printf("\n*** %d ***\n",minremovals(0,n-1,arr));
	if(s!=-1 && e!=-1)
	{
		for(int i=s;i<=e;i++)
		{
			printf("%d ",arr[i]);
		}
		printf("\n");
	}
	return 0;
}

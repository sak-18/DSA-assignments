#include<stdio.h>
#include<math.h>
//anoop soln

int n;
int min(int a,int b)
{
	if(a < b)
		return a;
	return b;
}
int findVLoc(int arr[])
{
	for(int i = 0;i < n-1;i++)
	{
		if(arr[i]<arr[i+1])return i;
	}
	return n-1;
}

int count = 0;

int findMin(int arr[])
{	if(count > 100)return 0;
	count ++;
	
	int loc = findVLoc(arr);
	
	for(int i = 0;i < n;i++)
	{
		printf("%d ",arr[i]);
	}
	
	if(loc == n-1)
	{
		return 0;
	}
	
	int b[n];
	int c[n];
	int diff = arr[loc+1] - arr[loc];
	
	for(int i = 0;i < n;i++)
	{
		b[i] = arr[i];
	}
	
	for(int i = 0;i < n;i++)
	{
		c[i] = arr[i];
	}
		
	b[loc] = b[loc+1];
	c[loc+1] = c[loc];
	
	if(arr[loc] == arr[loc-1])
	{
		return diff + findMin(c);
	}
	return min(diff+findMin(b),diff+findMin(c));
}

int main()
{
	int arr[n];
	scanf("%d",&n);
	
	for(int i = 0;i < n;i++)
	{
		scanf("%d",&arr[i]);
	}	
	
	int sum = 0;
	sum += findMin(arr);
	
	for(int i = 0;i < n;i++)
	{
		printf("%d ",arr[i]);
	}	
	
	printf("\n%d",sum);	
	
	return 0;
}

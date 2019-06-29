#include<stdio.h>

void print(int n,int arr[])
{
	printf("\nprinting list :");
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}

int traverse(int i,int n,int arr[n],int par[n],int m)
{
	int temp=i;
	int count=0;
	while(par[temp]!=temp)
	{
		if(count>m)
			return 0;
		if(arr[temp]==1)
			count++;
		temp=par[temp];
	}
	if(arr[temp]==1)
		count++;
		
	if(count>m)
		return 0;
	
	return 1;
}

int main()
{
	int n,m;
	
	scanf("%d %d",&n,&m); 
	
	int arr[n];//input array
	int par[n];//parent array
	int leaf[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		par[i]=i;//parent of i is i
		leaf[i]=1;//all are leaves
	}

	// tree construction
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		par[b-1]=a-1;
		leaf[a-1]=0;
	}
	
	print(n,leaf);
	print(n,arr);
	print(n,par);
	int count=0;
	
	for(int i=0;i<n;i++)
	{
		//if leaf,traverse up the tree
		if(leaf[i]==1)
			count+=traverse(i,n,arr,par,m);
	}
	
	printf("\ncount:%d\n",count);
	return 0;
}

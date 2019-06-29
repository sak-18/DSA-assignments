#include<stdio.h>

int array[1000000]={};

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		array[a]+=1;
	}
	
	for(int i=0;i<=10000;i++)
	{
		if(array[i]%2!=0)
		{
			printf("%d",i);
			return 0;
		}
	}
	printf("%d",-1);
	return 0;
}

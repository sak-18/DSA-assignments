#include<stdio.h>

int count[1000]={};

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		count[a]+=1;
	}	
	for(int i=0;i<1000;i++)
	{
		if( count[i]%2 != 0)
		{
			printf("%d\n",i);
			break;
		}
	}
	
	return 0;
}

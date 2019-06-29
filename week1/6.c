#include<stdio.h>

int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	
	for(int i=a;i<=b;i++)
	{	
		int isprime=1;
		for(int j=2;j<i;j++)
		{
			if(i%j==0)
			{
				isprime=0;
				break;
			}
		}
		
		if(isprime)
			printf("%d\n",i);
		
	}
}

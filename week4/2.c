#include<stdio.h>
#include<math.h>
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	int v;
	for( v=1;;v++)
	{	printf("\n In for v:%d-",v);
		int sum=0;
		int temp=v;
		while(temp!=0)
		{
			printf("%d ",temp);
			sum+=temp;
			temp/=k;
		}
		if(sum>=n)
			break;
	}
	printf("\n%d",v);
	return 0;
}

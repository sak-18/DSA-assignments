#include<stdio.h>
int main()
{
	int n,count=1,time,h;
	scanf("%d%d",&n,&time);
	int a[n];
	int i,j;
	for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		int b[100001];
		for(i=1;i<100000;i++)
		{
			b[i]=0;
		}
		for(i=0;i<n;i++)
		{
			for(j=a[i];j<=100000;j=j+a[i])
			{
				b[j]=b[j]+count;
				count++;
			}
			count=1;
		}
		for(i=1;i<100000;i++)
		{
			if(b[i]==time)
			{
				h=i;
				break;
			}
		}
		printf("%d",h);
}

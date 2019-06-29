#include<stdio.h>
#define N 10000

int factor(int num,int fac[N])
{	
	int top=0;
	for(int i=2;i*i<=num;i++)
	{
		if(num%i==0)
		{
			fac[top++]=num/i;
		}
	}
	return top;
}

int findopt(int num,int n,int count[n])
{	
	printf("\nNUM:%d\n,count[num]:%d",num,count[num]);
	if(num<=3)
		return num;
	if(count[num]!=0)
		return count[num];
	int fac[N]={};
	int top=factor(num,fac);	
	
	int cnt=1+findopt(num-1,n,count);
	
	for(int i=0;i<top;i++)
	{
		int b=1+findopt(fac[i],n,count);		
		if(b<cnt)
			cnt=b;		
	}
	count[num]=cnt;
	return cnt;		
}

int main()
{
	int num;
	scanf("%d",&num);
	int count[num+1];
	for(int i=0;i<num+1;i++)
	{
		count[i]=0;
	}
	printf("\nRES:%d\n",findopt(num,num,count));
	return 0;
}

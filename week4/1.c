#include<stdio.h>

int n;
int bprice[1000]={};
int cprice[1000]={};

void cal_price(int k)
{
	printf("\n\n");
	for(int i=0;i<n;i++)
	{
		cprice[i]=(i+1)*k+bprice[i];
		printf("i+1:%2d k:%2d bprice:%2d\n",i+1,k,bprice[i]);
	}
	printf("***");
}

void print_price()
{
	printf("\n<");
	for(int i=0;i<n;i++)
	{
		printf("%2d ",cprice[i]);
	}
	printf(">\n");
}

void sort()
{
	for(int i=0;i<n;i++)
	{
		int done=1;
		for(int j=0;j<n-i;j++)
		{
			
			if(cprice[j+1]<cprice[j])
			{
				int temp=cprice[j];
				cprice[j]=cprice[j+1];
				cprice[j+1]=temp;
				done=0;
			}
		}
		if(done)
			break;
	}
}

int main()
{

	scanf("%d",&n);
	
	
	int price;
	scanf("%d",&price);

	for(int i=0;i<n;i++)
	{
		scanf("%d",&bprice[i]);		
	}

	int res=-1;
	int k;
	for(k=1;k<=n;k++)
	{	
		int sum=0;	
		cal_price(k);
		print_price();
		sort();
		
		for(int a=0;a<k;a++)
		{
			sum+=cprice[a];
		}
		if(sum>price)
			break;
		res=sum;	
	}
	
	printf("\n\n%d %d",k-1,res);
	
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
int n;
int **arr;
int *prime;
int next_prime();
void print(int num)
{
	for(int i=0;i<num;i++)
	{
		printf("\n");
		for(int j=0;j<num;j++)
		{
			printf(" %2d",arr[i][j]);
		}
	}
}

void spiral(int num)
{
	int tmp=num;
	int count=num*num;
	int start_i=num-1,start_j=num-1;
	int i=start_i,j=start_j;
	int x=n*n-1;
	while(tmp!=1&&tmp!=0)
	{	

		//printf("In while loop1\n");
		while(i+j!=num-1)
		{
			printf("In while loop2 :%d %d\n",i,j);
			arr[i][j]=prime[x--];
			j--;
		}
		
		while(i!=j)
		{
			printf("In while loop3:%d %d\n",i,j);
			arr[i][j]=prime[x--];
			i--;
		}
		while(i+j!=num-1)
		{
			printf("In while loop4:%d %d\n",i,j);
			arr[i][j]=prime[x--];
			j++;
		}
		while(i!=j)
		{
			printf("In while loop5:%d %d\n",i,j);
			arr[i][j]=prime[x--];
			i++;
		}
		start_i=start_i-1;
		start_j=start_j-1;
		tmp=tmp-2;
		i=start_i;
		j=start_j;
	}
	
	if(tmp==1)
	{
		arr[i][j]=prime[x--];
	}
}

int next_prime()
{
	static int a=2;
	
	while(1)
	{
		int flag=1;
		for(int i=2;i<a;i++)
		{
			if(a%i==0)
			{
				flag=0;
				break;
			}
			
		}
		
		if(flag)
		{			
			a++;
			return a-1;
		}
		
		else
			a++;	
	}	
			
}

int main()
{
	scanf("%d",&n);
	arr=(int**)calloc(n,sizeof(int*));
	
	for(int i=0;i<n;i++)
	{
		arr[i]=(int*)calloc(n,sizeof(int));
	}
	prime =(int*)calloc(n*n,sizeof(int));
	for(int i=0;i<n*n;i++)
	{
		prime[i]=next_prime();	
	}
	
	spiral(n);
	print(n);
	return 0;
}

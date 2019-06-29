#include<stdio.h>
#include<stdlib.h>
int **arr;

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
	while(tmp!=1&&tmp!=0)
	{	

		//printf("In while loop1\n");
		while(i+j!=num-1)
		{
			printf("In while loop2 :%d %d\n,",i,j);
			arr[i][j]=count--;
			j--;
		}
		
		while(i!=j)
		{
			printf("In while loop3:%d %d\n",i,j);
			arr[i][j]=count--;
			i--;
		}
		while(i+j!=num-1)
		{
			printf("In while loop4:%d %d\n",i,j);
			arr[i][j]=count--;
			j++;
		}
		while(i!=j)
		{
			printf("In while loop5:%d %d\n",i,j);
			arr[i][j]=count--;
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
		arr[i][j]=count;
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	arr=(int**)calloc(n,sizeof(int*));
	for(int i=0;i<n;i++)
	{
		arr[i]=(int*)calloc(n,sizeof(int));
	}
	spiral(n);
	print(n);	
}

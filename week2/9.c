#include<stdio.h>
#include<limits.h>
int array[1000][1000]={};
int main()
{
	int n;
	printf("Enter n:");
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("\nEnter value between -1000 and 1000 at [%d][%d]",i,j);
			scanf("%d",&array[i][j]);
		}
	}
	
	int s_max=INT_MIN;
	int temp_sum=0;
	printf("\ns_max:%d\n",s_max);
	for(int a=1;a<=n;a++)
	{
		for(int p=0;p<=n-a;p++)
		{
			for(int q=0;q<=n-a;q++)
			{
				for(int i=p;i<a+p;i++)
				{
					printf("\n");
					for(int j=q;j<a+q;j++)
					{
						temp_sum+=array[i][j];
						printf(" %d",array[i][j]);
					}
				
				}
				if(s_max<temp_sum)
				{
					s_max=temp_sum;
				}
				temp_sum=0;
				printf("\ns_max:%d\n",s_max);
			}
		}
	}
	return 0;
}

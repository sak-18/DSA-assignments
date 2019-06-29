#include<stdio.h>

int try(int l,int r,int array[],int array2[])
{
	for(int i=l;i<=r;i++)
	{
		if(array[i]==1)
			return -1;
	}
	
	for(int i=l;i<=r;i++)
	{
		array2[i]=1;
	}
	return 1;
}


int main()
{
	int test;
	scanf("%d",&test);
	char * str[10][1000]={};
	for(int i=0;i<test;i++)
	{
		int num;
		int l[100]={},r[100]={};
		
		scanf("%d",&num);
				
		for(int j=0;j<num;j++)			
			scanf("%d %d",&l[j],&r[j]);
		
		int starkc=0,capc=0;
		int stark[1000000]={},cap[1000000]={};
		for(int k=0;k<num;k++)
		{
			if(starkc<=capc)
			{
				int done=try(l[k],r[k],cap,stark);
				if(done==1)
				{
					starkc++;
					str[i][k]="IM";
					continue;
				}
				else
				{
					done=try(l[k],r[k],stark,cap);
					if(done==1)
					{
						capc++;
						str[i][k]="CA";
						continue;
					}
					else
					{
						for(int m=0;m<10;m++)
						{
							str[i][m]="-1";
						}
						break;		
					}
					
				}
					
			}
			else
			{
				int done=try(l[k],r[k],stark,cap);
				if(done==1)
				{
					capc++;
					str[i][k]="CA";
					continue;
				}
				else
				{
					done=try(l[k],r[k],cap,stark);
					if(done==1)
					{
						starkc++;
						str[i][k]="IM";
						continue;
					}
					else
					{
						for(int m=0;m<10;m++)
						{
							str[i][m]="-1";
						}
						break;		
					}
					
				}
			
			}		
		}		
	}
	
	for(int x=0;x<test;x++)
	{
		printf("\n");
		for(int y=0;y<10;y++)
		{
			printf("%s ",str[x][y]);
		}	
	}	
	printf("\n");
	return 0;
}

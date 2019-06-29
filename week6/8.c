#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int x[100]={};
int y[100]={};

int scan(int len,char * str,int found,int x,int y,int m,int n,char string[m][n])
{
	int flag=0;
	if(found==len)
		return 1;
	int xmov[4]={0,0,1,-1};
	int ymov[4]={1,-1,0,0};
	for(int i=0;i<4;i++)
	{
		printf("\ni:%d j:%d",x+xmov[i],y+ymov[i]);
		if(x+xmov[i]<0 || x+xmov[i]>m-1 || y+ymov[i]>n-1 || y+ymov[i]<0)
			continue;
		printf(" Character:%c\n",string[x+xmov[i]][y+ymov[i]]);
		if(string[x+xmov[i]][y+ymov[i]]==str[found])
		{
			printf("\nFound character %d\n",found+1);
			flag=scan(len,str,found+1,x+xmov[i],y+ymov[i],m,n,string);		
			if(flag==1)
				break;
		}		
	}
	return flag;
}

int search(int m,int n,char string[m][n],char c)
{
	int match=0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(string[i][j]==c)
			{
				x[match]=i;
				y[match]=j;
				match++;
			}	
		}
	}
	return match;
}

int main()
{	
	int m,n;
	
	scanf("%d %d",&m,&n);
	
	char string[m][n];

	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf(" %c",&string[i][j]);
		}
	}
	
	int q;
	scanf("%d",&q);
	int res[q];
	
	for(int i=0;i<q;i++)
	{
		char str[100]={};
		scanf(" %s",str);
		int found=search(m,n,string,str[0]);
		int present=0;	
		for(int j=0;j<found;j++)
		{
			int len=strlen(str);
			int f=scan(len,str,1,x[j],y[j],m,n,string);
			if(f==1)
			{
				res[i]=1;
				present=1;
				break;
			}
				
		}
		if(!present)
			res[i]=0;
					
	}
		
	printf("\nResult:\n");
	for(int i=0;i<q;i++)
		printf("\n%d",res[i]);
	
	printf("\n");
	return 0;
}

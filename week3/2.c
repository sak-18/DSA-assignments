#include<stdio.h>

char s[100]={};
int m;
int len;
void cycle(int a,int b,int c)
{
	for(int i=1;i<=c;i++)
	{
		char temp=s[b];
		for(int j=b-1;j>=a;j--)
		{
			s[j+1]=s[j];
		}
		s[a]=temp;
	}
}

int main()
{
	scanf("%s",s);
	scanf("%d",&m);
	
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		cycle(a-1,b-1,c);
	}
	printf("%s",s);
	
	return 0;
}

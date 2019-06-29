#include<stdio.h>
#include<string.h>
int n;
int array[100];
int lena;
char a[100]={};
char b[100]={};

int check(int num)
{
	
	a[num]='\0';	
	for(int i=0,j=0;i<lena;i++)
	{
	
		if(a[i]==b[j])
			j++;
		
		if(j==strlen(b))
			return 1;
	}
	

	
	return 0;
	
}

int main()
{

	scanf("%s",a);
	scanf("%s",b);
	scanf("%d",&n);
	lena=strlen(a);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&array[i]);	
	}
	
	int i;
	for(i=0;i<n;i++)
	{

		if(!check(array[i]-1))
		{
			break;
		}			
	}
	printf("%d",i);
}

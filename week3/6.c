#include<stdio.h>
#include<string.h>

int count[26]={};
int main()
{
	char string[100]={};
	scanf("%s",string);

	for(int i=0;i<strlen(string);i++)
	{
		count[string[i]-'a']++;
	}
	
	int flag=1;
	if(strlen(string)%2==0)
	{
		for(int i=0;i<26;i++)
		{
			if(count[i]%2!=0)
				flag=0;
		}
	}
	
	else
	{	
		int n=0;
		for(int i=0;i<26;i++)
		{
			if(count[i]%2!=0)
				n++;
		}
		if(n!=1)
		{
			flag=0;
		}
	}
	flag?printf("YES\n"):printf("NO\n");
}

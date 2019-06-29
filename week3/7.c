#include<stdio.h>
#include<string.h>

int main()
{
	char string[1000]={};
	scanf("%s",&string);
	
	printf("\n");
	for(int i=0;i<strlen(string);i++)
	{
		printf("%c",'a'+(string[i]-'a'+3)%26);
	}
}

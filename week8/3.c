#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char stack[100]={};
	int stop=-1;
	char * string=(char *)malloc(sizeof(char)*20);
	scanf("%s",string);
	
	for(int i=0;i<strlen(string);i++)
	{
		printf("\nString[i]:%c",string[i]);
		//push onto stack	
		if(string[i]=='{'||string[i]=='('||string[i]=='[')
		{
			stack[++stop]=string[i];
		}	
		
		//pop or add onto stack
		else if(string[i]=='}'||string[i]==']'||string[i]==')')
		{
			if(stop==-1)
			{
				printf("\nUnbalanced1");
				return -1;		
			}
			
			int flag=1;
			
			switch(string[i])
			{
				case '}':
						if(stack[stop]=='{')
							{stop--;}		 
						else
							{
							printf("%c",string[stop]);
							flag=0;}
						break;				
				case ']':
						if(stack[stop]=='[') 
							{stop--;}
						else
							{flag=0;
							printf("%c",string[stop]);
							}	
						break;
				case ')':
						if(stack[stop]=='(') 
							{stop--;}
						else
							{flag=0;
							printf("%c",string[stop]);}	
						break;
			}
			printf("\nOut of switch");
			if(flag==0)
			{
				printf("\nUnbalanced2");
				return -1;
			}
		}
		
		else
		{
			printf("\nUnbalanced3");
			return -1;
		}
	}
	
	if(stop==-1)
		printf("\nBalanced");
	
	else
		printf("\nUnbalanced");
	
	return 0;	
}

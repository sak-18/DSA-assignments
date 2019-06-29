#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *reverse(char input[],int len)
{
	char *rev=(char*)calloc(100,sizeof(char));
	for(int i=len-1,j=0;i>=0;i--,j++)
	{
		rev[j]=input[i];
		printf("\nprinting rev:%s",rev);
	}
	return rev;
}

char *decode(char input[],int len)
{
	
	
	int change=1;
	char *d_string=(char*)calloc(100,sizeof(char));
	char * rev=reverse(input,len);
	printf("\ndecode1 :%s",rev);
	for(int i=0;i<len;i++)
	{
		if(rev[i]==' ')
		{	
			d_string[i]=' ';
			continue;
		}		
		
		if(change==1)
		{	
			d_string[i]='a'+(rev[i]-'a'-3+26)%26;
			change=0;
		}
		else
		{			
			d_string[i]=rev[i];
			change=1;
		}
				
	}
	printf("\ndecode2 :%s\n",d_string);
	
	return d_string;
	
}

char *code(char input[],int len)
{
	int change=1;
	char en_string[100];
	strcpy(en_string,input);
	printf("Encode4 :%s",en_string);
	for(int i=0;i<len;i++)
	{
		if(input[i]==' ')
		{	
			continue;
		}		
		
		if(change==1)
		{	
			en_string[i]='a'+(input[i]-'a'+3)%26;
			change=0;
		}
		else
		{			
			change=1;
		}
				
	}
	printf("\nEncode5 :%s\n",en_string);
	
	return reverse(en_string,len);
	
}

int main()
{
	char input[100];
	scanf("%[^\n]s",input);
	printf("%s",input);
	int len=strlen(input);
	printf("%d",len);
	
	printf("Encode[E]/Decode[D]:");
	char ch;
	scanf(" %c",&ch);
	if(ch=='e'||ch=='E')	
	{
		char *dstring =code(input,len);
		printf("Encode2:%s",dstring);
	}
	else if(ch=='D'||ch=='d')
	{
		printf("Decode:%s",decode(input,len));
	}
	
}

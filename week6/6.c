#include<stdio.h>
#include<string.h>

int palindrome_check(int start,int len,char* string)
{
	/*
	printf("\npcheck:");
	for(int i=0;i<len ;i++)
	{
		printf("%c",string[start+i]);
	}
	//also check if its in ascending order
	for(int i=start,j=start+len-1;i<start+len/2;i++,j--)
	{
		printf("\n%d %d",start,start+len/2);
		printf("\n%c %c",string[i],string[j]);
		
		if( (string[i]!=string[j]) || (  i!=start && string[i]<string[i-1] ) )
			return 0;
	}
	printf("\nReturning 1");
	return 1;
	*/
	printf("\n");
	for(int i=0;i<len ;i++)
	{
		printf("%c",string[start+i]);
	}
	
	for(int i=start,j=len+start-1;i<j;i++,j--)
	{
		printf("\n%c %c",string[i],string[j]);
		if( (string[i]!=string[j]) || (i!=start && string[i]<string[i-1]) )
			return 0;
	}
	printf("\nReturning 1");
	return 1;
}

int main()
{
	char string[100]={};
	scanf("%s",string);
	
	char res1[100]={};
	char res2[100]={};
	res1[0]=127;
	int len=strlen(string);
	for(int i=len;i>0;i--)
	{
		int done=0;
		for(int j=0;j<len-i+1;j++)
		{
				int p=palindrome_check(j,i,string);

				if(p==1)
				{
					strncpy(res2,string+j,i);
					res2[i]='\0';
					printf("\nres1:%s res2:%s",res1,res2);
					done=1;
					if(strcmp(res1,res2)>0)
					{
						strcpy(res1,res2);
					}	
				} 
			
		}
		if(done==1)
			break;
	}
	printf("\nString:%s",res1);	
	return 0;
}


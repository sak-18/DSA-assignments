#include<stdio.h>
#include<string.h>
#include<math.h>

int ceil2(float a)
{
	printf("\nIn ceil (%f)..",a);
	int b=a;
	float res=b-a;
	if(res==0)
		return b;
	else
		return b+1;
			
}

int main()
{
	char str[100]={};
	int count[26]={};
	scanf("%s",str);
	
	for(int i=0;i<strlen(str);i++)
	{
		count[str[i]-'a']+=1;
	}
	printf("CEIL of 1.3=%f,1=%f",ceil(1.3) ,ceil(1.0));
	int k=ceil2((float)strlen(str)/2);
	printf("\nCeil of %f is %d",(float)strlen(str)/2,k);

	for(int i=0;i<strlen(str);i++)
	{
		if(count[i]>k)
		{
			printf("\nNOT POSSIBLE\n");	
			return 0;
		}	
	}
	
	
	printf("\nPossible\n");	
	return 0;
}

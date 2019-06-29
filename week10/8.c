#include<stdio.h>
#include<stdlib.h>

int main()
{
	
	int chairs,persons;
	scanf("%d %d",&chairs,&persons);
	char string[20]={};
	scanf("%s",string);
	int q;
	scanf("%d",&q);
	int queries[q];
	int *pos=(int *)calloc(chairs,sizeof(int));	
	
	for(int i=0;i<q;i++)
	{
		scanf("%d",&queries[i]);
	}
	
	for(int i=0;i<persons;i++)
	{
		int start=-1;
		int end=-2;
		int a=-1;
		int b=-1;
		for(int j=0;j<chairs;j++)
		{

			if(pos[j]!=0)
			{
				a=-1;
				b=-1;
				continue;
			}
			
			if(pos[j]==0 && a==-1 && b==-1)
			{
				a=j;
				b=j;
			}
			
			else if(pos[j]==0)
			{
				b+=1;
			}
			
			if(b-a > end-start)
			{
				end=b;
				start=a;
			}

		}
		
		if(start!=-1 && end!=-1)
		{
			int place=(start+end)/2;
						
			if(string[i]=='R' && (end-start)%2==1)
			{
				place+=1;
			}
			
			pos[place]=i+1;
		}
	}
	
	for(int i=0;i<q;i++)
	{
		printf("\n%d",pos[queries[i]-1]);
	}	
	return 0;
}

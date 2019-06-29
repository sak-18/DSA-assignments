#include<stdio.h>

#define N 100
int stop=-1;
int mtop=0;
int mini(int a,int b)
{
	return a>b?b:a; 
}

int push(int num,int stack[N],int min[N])
{
	if(stop==N-1)
		return 1;
		
	stack[++stop] =num;
	if(stop>0)
		min[stop] = mini(num,min[stop-1]);	
	if(stop==0)
		min[stop]=stack[stop];
	return 0;
}

int pop(int stack[N])
{
	if(stop==-1)
		return 2;
	stop--;
	mtop--;
}

void print(int len,int stack[N])
{
	printf("\nSTACK: ");
	for(int i=0;i<len;i++)
	{
		printf("%d ",stack[i]);
	}

}

int main()
{
	int stack[N];
	int min[N];
	int choice;
	int n;
	char c;
	int error;
	do
	{	
		printf("\n1-PUSH\n2-POP\n3-DISPLAY MININMUM\nEnter your choice:");
			
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
					printf("\nEnter a number:");
					scanf("%d",&n);
					error=push(n,stack,min);
					break;
			case 2:
					error=pop(stack);
					break;
			case 3:
					printf("\nmin:%d",min[stop]);
					break;
			
		}
		
		if(error==1)
		{
			printf("\nStackOverflow");
			return -1;
		}
		
		if(error==2)
		{
			printf("\nStackEmpty");
			return -1;
		}
		
		print(stop+1,stack);
		printf("\nCharacter[Y/N]:");
		scanf(" %c",&c);			
	}while(c=='y'||c=='Y');
	
	printf("\n");
	return 0;
}

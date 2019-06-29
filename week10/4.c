#include<stdio.h>

int size;

int check(int index,int heap[size])
{

	int child=index*2;	
	if(child+1<=size && heap[index]<heap[child] && heap[index]<heap[child+1])
	{
		return (check(child,heap) && check(child+1,heap));	
	}
	else if(child==size && heap[index]<heap[child])
	{
		return 1;
	}
	else if(child>size)
	{
		return 1;
	}
	
	return 0;
}

int main()
{
	
	scanf("%d",&size);
	int heap[size+1];
	heap[0]=-99999;
	
	for(int i=1;i<size+1;i++)
		scanf("%d",&heap[i]);
	
	if( check(1,heap) )
	{
		printf("\nYes\n");
	}
	
	else
	{
		printf("\nNo\n");
	}	
				
	return 0;	
}

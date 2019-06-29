#include<stdio.h>

int sizel=0,sizer=0;
int eff_median=0;
int leftmaxheap[100]={},rightminheap[100]={};

void heapify(int num,int heap)
{
	if(heap==1)
	{
		sizel+=1;
		leftmaxheap[sizel]=num;
			
		int curr = sizel;
		int par = sizel/2;
		
		while(leftmaxheap[par]<num)
		{
			leftmaxheap[curr]=leftmaxheap[par];
			curr=par;
			par=par/2;
		}
		
		leftmaxheap[curr]=num;
	}
	
	else
	{
		sizer+=1;
		rightminheap[sizer]=num;
			
		int curr = sizer;
		int par = sizer/2;
		
		while(rightminheap[par]>num)
		{
			rightminheap[curr]=rightminheap[par];
			curr=par;
			par=par/2;
		}		
		rightminheap[curr]=num;		
	}
}


void heapifydown(int heap)
{
	if(heap==1)
	{
		leftmaxheap[1]=leftmaxheap[sizel];
		sizel--;
		int key=leftmaxheap[1];			
		int curr = 1;
		int child=curr*2;
		int x=1;		
	
		while(child<=sizel)
		{
			printf("\nLoop %d",x++);
		
			if(child+1<=sizel && leftmaxheap[child+1]>leftmaxheap[child])
			{
				child=child+1;
				printf("\nIF in loop %d",x++);		
			}
		
			if(leftmaxheap[child]>key)
			{
				leftmaxheap[curr]=leftmaxheap[child];
			}
		
			else
			{
				break;
			}
		
			curr=child;
			child=child*2;
		}
	
		leftmaxheap[curr]=key;	

	}
	
	else
	{
		rightminheap[1]=rightminheap[sizer];
		sizer--;
		int key=rightminheap[1];			
		int curr = 1;
		int child=curr*2;
		int x=1;		
	
		while(child<=sizer)
		{
			printf("\nLoop %d",x++);
		
			if(child+1<=sizer && rightminheap[child+1]<rightminheap[child])
			{
				child=child+1;
				printf("\nIF in loop %d",x++);		
			}
		
			if(rightminheap[child]<key)
			{
				rightminheap[curr]=rightminheap[child];
			}
		
			else
			{
				break;
			}
		
			curr=child;
			child=child*2;
		}
	
		rightminheap[curr]=key;	

	}
	
}



int main()
{
	int n;
	scanf("%d",&n);
	
	int num;
	
	leftmaxheap[0]=9999999;
	rightminheap[0]=-999999;		
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num);	
		
		//send to leftmaxheap
		if(num<eff_median)
		{
			if(sizel>sizer)
			{
				heapify(leftmaxheap[1],2);
				heapifydown(1);
				heapify(num,1);
				eff_median=(leftmaxheap[1]+rightminheap[1])/2;
			}
			
			else if(sizer>sizel)
			{
				heapify(num,1);
				eff_median=(leftmaxheap[1]+rightminheap[1])/2;
			}
			
			else
			{
				heapify(num,1);
				eff_median = leftmaxheap[1];		
			}
		}
		
		else//send to rightminheap
		{
			if(sizer>sizel)
			{
				heapify(rightminheap[1],1);
				heapifydown(2);
				heapify(num,2);
				eff_median=(leftmaxheap[1]+rightminheap[1])/2;				
			}
			
			else if(sizel>sizer)
			{
				heapify(num,2);
				eff_median=(leftmaxheap[1]+rightminheap[1])/2;			
			}
			
			else
			{
				heapify(num,2);
				eff_median=rightminheap[1];
			}
		}
		printf("\n\nEffect median:%d\n\n",eff_median);
			
		printf("\nPrinting leftmaxheap\n\n");
		for(int i=0;i<sizel;i++)
			printf("%d ",leftmaxheap[i+1]);
	
	
		printf("\nPrinting rightminheap\n\n");
		for(int i=0;i<sizer;i++)
			printf("%d ",rightminheap[i+1]);
		printf("\n");
	}
				
	return 0;
}

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

/*
 * Complete the cookies function below.
 */
/*
void sort(int n,int A[n])
{
    for(int i=1;i<n;i++)
    {
        int done=1;
        for(int j=i-1;j<n-1;j++)
        {
            if(A[j]>A[j+1])
            {
                int temp=A[j+1];
                A[j+1]=A[j];
                A[j]=temp;
                done=0;
            }
        }
        if(done)
            break;
    }
}
*/
int hcount=0;
int heap[1000000]={};

void heapify(int index)
{
    static int count=0;
    int par_index=index/2;
    count++;
    printf("\ncount:%d\n",count);
    
    if(index==0)
    	return;
    	
    while(index!=0)
    {
      int par_index=index/2;
      
      if(heap[par_index]>heap[index])
      {
	  	int temp = heap[par_index];
      	heap[par_index]=heap[index];
      	heap[index]=temp;						     
      }
      index=par_index;
    }
}

void makeheap(int num)
{
    heap[hcount++]=num;
    heapify(hcount-1);
}

int max(int a,int b)
{
    return a<b?b:a; 
}

void heapify_down()
{
     heap[0]=heap[hcount-1];
     hcount--;
    int ind=0;
    while((2*ind<hcount)||(2*ind+1<hcount) && (heap[ind]>heap[2*ind] || heap[ind]>heap[2*ind+1]))
    {
        int a=0;
        if(2*ind+1>=hcount)
        {
            int temp=heap[ind];
            heap[ind]=heap[2*ind];
            heap[2*ind]=temp;
            ind=2*ind;	
        }
        else if(heap[2*ind]<heap[2*ind+1])
        {
            int temp=heap[ind];
            heap[ind]=heap[2*ind];
            heap[2*ind]=temp;
            ind=2*ind;
        }
        else
        {
          int temp = heap[ind];
          heap[ind] = heap[2 * ind+1];
          heap[2 * ind+1] = temp;
          ind=2*ind+1;
        }
    }
}

int cookies(int k, int A_count, int* A) {
    /*
     * Write your code here.
     */
     for(int i=0;i<A_count;i++)
        makeheap(A[i]);
    int count=0;
    
    while(hcount>2 && heap[0]<k)
    {
        int nvalue;      
        count++;
    	heap[1]>heap[2]? (nvalue=heap[0]+2*heap[2]):(nvalue=heap[0]+2*heap[1]);
    	heapify_down();
    	heapify_down();
    	makeheap(nvalue);
    	printf("\nInside while\n");
    }
    
    if(hcount==2 && heap[0]>=k)
    {
    	return count;
    }
    
    else if(hcount==2 && heap[0]+2*heap[1]>=k)
    {
    	count++;
    	return count;   		 	
    }
    
    else
    {
    	return -1;
    }
    
}

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	int A[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&A[n]);	
	}
	printf("\nResult:%d\n",cookies(k,n,A));
	return 0;
}


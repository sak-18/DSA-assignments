#include<stdio.h>
#include<stdlib.h>



typedef struct node
{
	int num;
	struct node* next;
}node;

node* hptr=NULL;

void printlist(node* headptr)
{
	node* temp=headptr;
	printf("\nprinting:");
	while(temp!=NULL)
	{
		printf("%2d ",temp->num);
		temp=temp->next;
	}
	printf("\n");
}

void makelist(int n,node* headptr)
{	
	node* temp=headptr;	
	for(int i=0;i<n;i++)
	{
		printf("\nINSERT:");
		scanf("%d",&temp->num);
		if(i==n-1)
		{
			temp->next=NULL;
			break;
		}
		temp->next=(node *)malloc(sizeof(node));
		temp=temp->next;
	}
	
}

void sortlist(node* ptr1,node* ptr2,int n,int m)
{
	node* cptr1=ptr1,*cptr2=ptr2;
	
	if(cptr1->num <= cptr2->num)
	{
		hptr=cptr1;	
		cptr1=cptr1->next;
	}
	else
	{
		hptr=cptr2;
		cptr2=cptr2->next;
	}
	
	node* temp=hptr;
	printf("\ncptr1:%p cptr2:%p temp:%p hptr:%p",cptr1,cptr2,temp,hptr);
	printf("\nOutside while");
	while(cptr1!=NULL && cptr2!=NULL)
	{
		printf("\ntemp->num:%2d",temp->num);
		printf("\ninside while");
		if(cptr1->num <= cptr2->num)
		{
			temp->next=cptr1;	
			cptr1=cptr1->next;
			temp=temp->next;
		}
		
		else
		{
			temp->next=cptr2;	
			cptr2=cptr2->next;
			temp=temp->next;	
		}
		
	}
	printf("\nout now");
	if(cptr1==NULL)
	{
		temp->next=cptr2;
	}
	else
	{
		temp->next=cptr1;
	}
}

int main()
{
	int n,m;
	scanf("%d",&n);
	
	node * headptr1=(node *)malloc(sizeof(node));
	headptr1->next=NULL;
	makelist(n,headptr1);
	printlist(headptr1);
	
	scanf("%d",&m);
	
	node * headptr2=(node *)malloc(sizeof(node));
	headptr2->next=NULL;
	makelist(m,headptr2);
	printlist(headptr2);
	
	sortlist(headptr1,headptr2,n,m);
	printlist(hptr);
	return 0;
}

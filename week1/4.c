#include<stdio.h>
#include<stdlib.h>
int no_nodes=0;
struct node* headptr;
struct node*currptr;
struct node
{
	struct node* next;
	int num;
};

struct dnode
{
	struct node* prev;
	struct node* next;
	int num;
};
void clist(){}
void dlist(){}
void slist()
{
	
	headptr=(struct node*)calloc(1,sizeof(struct node));
	currptr=headptr;
	char ch;
	do
	{
	
		int number;
		printf("\nenter a number:");
		scanf("%d",&number);
		if(no_nodes==0)
		{
			headptr->num=number;
			headptr->next=NULL;
			currptr=headptr;
			no_nodes++;				
		}
		
		else
		{
			struct node *newnode=(struct node*)calloc(1,sizeof(struct node));
			currptr->next=newnode;
			currptr=currptr->next;
			currptr->num=number;
			currptr->next=NULL;		
			no_nodes++;
		}
		printf("Another node?[y/n]:");
		scanf(" %c",&ch);
	}while(ch=='y');
	
	printf("Kth node from last.What k?");
	int k;
	scanf("%d",&k);
	currptr=headptr;
	for(int i=1;i<=no_nodes-k;i++)
	{
		currptr=currptr->next;
	}
	printf("%dnode from back:%d",k,currptr->num);
}

void printlist()
{
	for(int i=1;i<no_nodes;i++)
	{
		if(i==1)
			currptr=headptr;
		else
			currptr=currptr->next;		
		printf("\nnode%d:%d",i,currptr->num);
	}
}
int main()
{
	char c;
	scanf("%c",&c);
	
	switch(c)
	{
		case's':
				slist();
				break;
		case 'd':
				dlist();
				break;
		case 'c':
				clist();
				break;				
	}	
	return 0;
}

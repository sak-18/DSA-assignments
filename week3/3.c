#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int num;
	int pos;
	struct node *next;
}node;

int count=0;
node* headptr=NULL,*currptr=NULL,*tempptr=NULL;

void revfrom(node* prev,node* this)
{
		
	node *ptr=this->next;
	
	if(this->next==NULL)
	{	
		this->next=prev;
		tempptr->next=this;
		return;
	}
	

	else
	{
		this->next=prev;
		revfrom(this,ptr);	
	}
		
}
void swapall(node* from,node* to)
{
	node* ptr=from;
	int store=to->num;
	while(ptr!=to->next)
	{
		int temp=store;
		store=ptr->num;
		ptr->num=temp;
		ptr=ptr->next;		
	}
	currptr=currptr->next;
}

void printlist()
{
	tempptr=headptr;
	printf("\nprinting list:");
	while(tempptr!=NULL)
	{
		printf("%2d ",tempptr->num);
		tempptr=tempptr->next;
	}
}


void makelist()
{
	
	char c;
	do{
		int n;
		scanf("%d",&n);
		if(count==0)
		{
			headptr=(node*)malloc(sizeof(node));
			currptr=headptr;
			headptr->next=NULL;
			headptr->num=n;
			count+=1;
			headptr->pos=count;
		}
		
		else
		{
			currptr->next=(node*)malloc(sizeof(node));
			currptr=currptr->next;
			currptr->num=n;
			currptr->next=NULL;
			count+=1;
			currptr->pos=count;
		}
	scanf(" %c",&c);
	}while(c=='y'||c=='Y');

}

int main()
{
	makelist();
	printlist();
	int k;
	scanf("%d",&k);
	
	//set pointers
	for(currptr=headptr,tempptr=headptr;tempptr!=NULL;tempptr=tempptr->next)
	{
		if(tempptr->pos % k==0)
			swapall(currptr,tempptr);
		
	}	
	printlist();
	tempptr=headptr;
	while(tempptr->next!=currptr)
		tempptr=tempptr->next;
	
	revfrom(NULL,currptr);
	printf("\nList reversed\n");
	printlist();
	return 0;
}

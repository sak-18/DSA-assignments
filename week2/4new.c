#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int num;
	struct node* prev;
	struct node* next;
	int cid;
	char* colour;	
}node;
int count=0;
char *string[]={"red","blue","green","yellow","orange"};
node * headptr=NULL;
node *currptr=NULL;
node * store[1000]={};

void paint(int cid,node* currptr)
{
	int temp=0;
	if(currptr->cid!=-1)
		return;
	
	while(temp==cid || temp==currptr->next->cid || (currptr->prev!=NULL && temp==currptr->prev->cid))
		temp++;
	
	
	if(temp>count)
		count=temp;
	
	currptr->cid=temp;
	currptr->colour=string[temp];
}

void paint_colour()
{
	currptr=headptr;
	while(currptr->next!=NULL)
	{
		currptr=currptr->next;
	}
	
	currptr->cid=0;
	currptr->colour=string[0];
	int temp=-1;
	while(currptr->prev!=NULL)
	{
		 temp=currptr->cid;
		if(currptr->prev->num == currptr->num -1)
		{
			currptr=currptr->prev;
			paint(temp,currptr);
		}
		
		else
		{
			currptr=currptr->prev;
			paint(temp,currptr);
			int colour=currptr->cid;
			currptr=currptr->next;
			paint(colour,currptr);
		}
	}
	paint(temp,currptr);
}

void traverse()
{
	int i=1;
	currptr=headptr;
	printf("\nNODE %d<%d %p %p colour:%s>\n",i++,currptr->num,currptr->prev,currptr->next,currptr->colour);
	while(currptr->next!=NULL)
	{
		currptr=currptr->next;
		printf("\nNODE %d<%d %p %p colour:%s>\n",i++,currptr->num,currptr->prev,currptr->next,currptr->colour);
		
	}
}

void make_list(int a,int b,int c)
{
	if(headptr==NULL || b==0 )
	{
		headptr=(node*)calloc(1,sizeof(node));		
		store[0]=headptr;
		headptr->num=a;
		headptr->cid=-1;
		headptr->colour=NULL;
		headptr->prev=NULL;
		headptr->next=NULL;		
	}
	
	else
	{
		currptr=headptr;
		while(currptr->next!=NULL)
		{
			currptr=currptr->next;
		}
		store[a-1]=currptr->next=(node*)calloc(1,sizeof(node));		
		currptr=currptr->next;
		currptr->num=a;
		currptr->cid=-1;
		currptr->colour=NULL;
		currptr->prev=store[b-1];
		currptr->next=NULL;
	}
}

int main()
{
	int a,b,c;
	do
	{
		scanf("%d %d %d",&a,&b,&c);
		make_list(a,b,c);		
	}while(c!=0);
	traverse();
	paint_colour();
	traverse();
	printf("\nChromatin number:%d\n",count+1);
}

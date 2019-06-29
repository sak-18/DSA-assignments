#include<stdio.h>
#include<stdlib.h>

int count=0;
int id_list[100]={};
string colour[]={"red","blue","green","yellow"};
count=0;
struct node
{
	int id;
	int cid;
	string colour;
	struct node* next;
	struct node* prev;
};

struct node* headptr=NULL;
struct node* currptr=NULL;
struct node*search(int n)
{
	currptr=headptr;
	while(currptr!=NULL)
	{
		if(currptr->id==n)
			break;
		else
			currptr=currptr->next;
	}
	return currptr;
}

void create_node(int x,int y,int z)
{
	if(y==0)
	{
		headptr=(struct node*)calloc(1,sizeof(struct node));
		headptr->id=x;
		headptr->prev=NULL;
		headptr->next=(struct node*)calloc(1,sizeof(struct node));
		headptr->next->id=z;
	}
	
		    
}

int main()
{
	do
	{
		printf("\nEnter a tuple(x,y,z):");
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		create_node(a,b,c);
	}while(c!=0);
	return 0;
}

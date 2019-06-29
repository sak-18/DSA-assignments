#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node* next;
	int num;
};
struct node* headptr=NULL;
struct node* currptr=NULL;
int count=0;
void make_list()
{
	char ch;
	do
	{
		int n;
		printf("\nEnter a number:");
		scanf("%d",&n);
		if(headptr==NULL)
		{
			headptr=(struct node*)calloc(1,sizeof(struct node*));
			currptr=headptr;
			count++;
			currptr->num=n;
			currptr->next=NULL;
		}
		else
		{
			currptr->next=(struct node*)calloc(1,sizeof(struct node*));;
			currptr=currptr->next;
			currptr->num=n;
			currptr->next=NULL;
			count++;
		}
		printf("\nDo you want another new node?[y/n]");
		
		scanf(" %c",&ch);
	}while(ch=='y'||ch=='Y');
}
void printlist()
{
	currptr=headptr;
	printf("\n%d",currptr->num);
	currptr=currptr->next;
	while(currptr!=NULL)
	{
		printf("->%d",currptr->num);
		currptr=currptr->next;
	}
}
void search()
{	
	printf("\ncount:%d",count);
	int array[100];//Doubt 1
	printf("Enter the number you want to be searched:");
	int number;
	scanf("%d",&number);
	currptr=headptr;
	for(int i=0;i<count;i++)
	{
		array[i]=0;
		if(currptr==NULL)
		{
			printf("\nEnd of list!");
			break;
		}
		if(currptr->num==number)
		{
			array[i]=1;
		}
		currptr=currptr->next;
		
	}
	printf("Found at locations:");
	for(int i=0;i<count;i++)
	{
		if(array[i]==1)
			printf("%d ",i+1);
	}
}
void delete()
{
	printf("Enter the number you want to be deleted:");
	int number,flag=0,deleted=0;
	scanf("%d",&number);
	struct node* prev =(struct node*)calloc(1,sizeof(struct node*));
	
	if(headptr->num==number)
		flag=1;	
	
	prev=headptr;
	currptr=headptr->next;
	while(currptr!=NULL)
	{
		if(!flag && headptr->num == number)
			flag=1;
		else if(flag && currptr->num == number)
		{
			deleted=1;
			prev->next=currptr->next;
			currptr=currptr->next;
		}
		else
		{
			prev=prev->next;
			currptr=currptr->next;
		}	
	}
	printlist();	
}
void swap()
{
	int number;
	printf("Enter the number you want to be swapped:");
	scanf("%d",&number);
	struct node* prev =(struct node*)calloc(1,sizeof(struct node*));
	prev=headptr;
	currptr=headptr->next;
	while(currptr!=NULL)
	{
		if(currptr->num==number)
		{
			currptr->num=prev->num;
			prev->num=number;
		}
		currptr=currptr->next;
		prev=prev->next;
	}
	printlist();
	
}
int main()
{
	make_list();
	printlist();
	printf("\nSearch[1]/Delete[2]/Swap[3]:");
	int a;
	scanf("%d",&a);
	switch(a)
	{
		case 1:
				search();
				break;
		case 2:
				delete();
				break;
		case 3:
				swap();
				
	}
	
}

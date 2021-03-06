/* 
E11 - Delete all nodes that have value n 
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
};

struct node *create_list(struct node *start);
void display(struct node *start);
struct node *addatbeg(struct node *start,int data);
struct node *addatend(struct node *start,int data);
struct node *Delete(struct node *start, int n);

main()
{
	struct node *start=NULL;	
	int n;
	start=create_list(start);
	display(start);
	printf("Enter n :");
	scanf("%d",&n);
	start = Delete(start,n);
	display(start);
}/*End of main()*/

struct node *Delete(struct node *start, int n)
{
	struct node *prev, *ptr;
	
	if(start==NULL)
		return start;

	/*Delete all the nodes that are at the beginning of the list and have value n*/
	while(start!=NULL && start->info==n)
	{
		ptr=start;
		start = start->link;
		free(ptr);
	}
	
	prev = ptr = start;
	while(ptr!=NULL)
	{
		if(ptr->info==n)
		{
			prev->link = ptr->link;
			free(ptr);
			ptr=prev->link;
		}
		else
		{
			prev=ptr;
			ptr=ptr->link;
		} 
	}
	return start;
}/*End of Delete()*/

struct node *create_list(struct node *start)
{
	int i,n,data;
	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	start=NULL;
	if(n==0)
		return start;

	printf("Enter the element to be inserted : ");
	scanf("%d",&data);
	start=addatbeg(start,data);

	for(i=2;i<=n;i++)
	{
		printf("Enter the element to be inserted : ");
		scanf("%d",&data);
		start=addatend(start,data);	
	}
	return start;
}/*End of create_list()*/

void display(struct node *start)
{
	struct node *p;
	if(start==NULL)
	{
		printf("List is empty\n");
		return;
	}
	p=start;
	printf("List is :\n");
	while(p!=NULL)
	{
		printf("%d ",p->info);
		p=p->link;
	}
	printf("\n\n");
}/*End of display() */

struct node *addatbeg(struct node *start,int data)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->link=start;
	start=tmp;
	return start;
}/*End of addatbeg()*/

struct node *addatend(struct node *start,int data)
{
	struct node *p,*tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	p=start;
	while(p->link!=NULL)
		p=p->link;
	p->link=tmp;
	tmp->link=NULL;
	return start;
}/*End of addatend()*/


#include <stdio.h>
struct node
{
	int data;
	struct node *next;
};

struct node *head=NULL , *tail=NULL;

int main()
{
	int ch;
	while(1)
	{ 
	  printf("1 for create, 2 for delete,  3 for insert, 4 for view , 5 for exit");
	         
	         
	         
	         printf("choice????");
	         scanf("%d",&ch);
	         if(ch==1)create();
	         if(ch==2)delete();
	         if(ch==3)insert();
	         if(ch==4)view();
	         if(ch==5)break;
	}
}



void create()
{
	int n,i;
	struct node *temp;
	printf("ENTER NO. OF NODES TO CREATE");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
	   temp=(struct node*)malloc(sizeof(struct node));
	   printf("ENTER DATA");
	   scanf("%d",temp ->data);
	   temp->next=NULL;
	   if(head==NULL)
	    {
	    	head=temp;
	    	tail=temp;
			}	
		
		else
		  {
		  	tail->next=temp;
		  	tail=temp;
		  }
		i=i+1;
	}
	
	
}




void view()
{
	struct node *trav;
	trav=head;
	while(trav!=NULL)
	{
		printf("%d \t", trav->data);
		trav=trav->next;
	}
}



void insert()
{
	int target;
	struct node*temp, *trav;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("ENTER ITEM TO INSERT");
	scanf("%d",temp->data);
	temp->next=NULL;
	printf("ENTER THE NODE AFTER WHICH YOU WANT TO ENTER DATA");
	scanf("%d",&target);
	
	trav=head;
	while(trav!=NULL)
	{
		if(trav->data==target)
		break;
		else
		trav=trav->next;
		
		temp->next=trav->next;
		trav->next=temp;
		
		if(trav==tail)
		  {
		  	tail=trav;
		  }
		
	}
	
}


void delete()
{
	struct node *trav, *prev;
	int item;
	
	peintf("ENTER NODE TO DELETE");
	scanf("%d",&item);
	{
		trav=head;
		while(trav->data!=item)
		{
			prev=trav;
			trav=trav->next;
		}
		
		prev->next=trav->next;
		if(trav==tail)     ///delete tail node
		  tail=prev;
		  free(trav);
	}
}

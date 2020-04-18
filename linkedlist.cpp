#include<iostream>
using namespace std;

class node
{
	public:
		int data;
		node * next;
};
node* head3 =NULL;

void append(node** head, int d)  
{  
    node* nnode = new node(); 
    node *last = *head; 
    nnode->data = d;  
    nnode->next = NULL;  
    if (*head == NULL)  
    {  
        *head = nnode;  
        return;  
    }  
    while (last->next != NULL)  
        last = last->next;  
  
    last->next = nnode;  
    return;  
}  
  
node* mergelist(node* head1, node* head2)
{	

	node*t3= head3;
	node* t1= head1;
	node* t2= head2;
	if(t1==NULL&&t2==NULL)
	return t3;
	if(t1!=NULL&&t2!=NULL)
	{
		if(t1->data<t2->data)
			{
				append(&head3,t1->data);
				
				return mergelist(t1->next,t2);
			}
		else if (t2->data<t1->data)
			{
				append(&head3,t2->data);
				return mergelist(t1,t2->next);	
			}	
		else 
		{
			append(&head3,t1->data);
			append(&head3,t2->data);
			return mergelist(t1->next,t2->next);
			
		}
	}
	
	if(t1==NULL&&t2!=NULL)
	{
		append(&head3,t2->data);
		return mergelist(t1,t2->next);
			 
	}
		if(t1!=NULL&&t2==NULL)
	{
		append(&head3,t1->data);
		return mergelist(t1->next,t2);
			 
	}
	
}

int main()
{
	
	node* head1=NULL;
	node* head2=NULL;
	append(&head1,1);

	append(&head1,2);
    append(&head1,3);
	append(&head2,3);
	append(&head2,4);
	mergelist(head1,head2);
	node* temp=head3;
	while(temp!=NULL)
	{
		cout<<temp->data;
		temp=temp->next;
		
	}
		return 0;
}

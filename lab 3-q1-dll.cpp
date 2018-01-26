#include <iostream>
using namespace std;

struct node  //structure that contains pointers for next and before node
{
	int data;
	node *next;
	node *before;
};

class linkedlist  //class having functions that operate on nodes
{
	private:
	 node *head;
	 node *tail;
            public:
	 linkedlist() //constructor to make value of head and tail as null
	 {
	 	head=NULL;
	 	tail=NULL;
	 }
	
	void insert(int n) //function to insert node at the end
	{
		node *temp=new node;
		temp->data=n;
		temp->next=NULL;
		if(head==NULL)
		{
			temp->before=NULL;
	                        head=temp;
		}
		else
		{
			tail->next=temp;
			temp->before=tail;
		}
		tail=temp;
	}
	
	void insertAt(int pos,int n) //function to insert a node at a particular position
	{
		node *temp=new node;
		node *curr=new node;
		node *prev=new node;
		curr=head;
		temp->data=n;
		if(pos<=countitems())
		{
	              for(int i=1;i<pos;i++)
	              {
	        	    prev=curr;
	        	    curr=curr->next;
	              }
	              prev->next=temp;
	              temp->before=prev;
	              temp->next=curr;
	              curr->before=temp;
		}
		else
		  cout<<"invalid position"<<endl;
	}
	
	void Delete() //function to delete last node
	{
		node *prev=new node;
		node *curr=new node;
		curr=head;
		while(curr->next!=NULL)
		{
		   prev=curr;
		   curr=curr->next;
		}
		tail=prev;
		prev->next=NULL;
		delete curr;
		
	}
	
	void DeleteAt(int pos) //function to delete node at a particular position
	{
		node *prev=new node;
		node *curr=new node;
		node *after=new node;
		curr=head;
		if(pos<=countitems())
		{
			for(int i=1;i<pos;i++)
			{
				prev=curr;
				curr=curr->next;
				after=curr->next;
			}
			prev->next=after;
			after->before=prev;
			delete curr;
		}	
	           else
	            cout<<"invalid position"<<endl;
	}
	
	int countitems()  //function to count items
	{
		node *temp=new node;
		int c;
		temp=head;
		while(temp!=NULL)
		{
			temp=temp->next;
			c++;
		}
		return c;
	}
	
	void display()  //function to display data of all the nodes
	{
		node *temp=new node;
		temp=head;
		while(temp!=NULL)
		{
			cout<<temp->data<<endl;
			temp=temp->next;
		}
	}
};	
	
	int main()
	{
		linkedlist l;
		l.insert(10);
		l.insert(30);
		l.display();
		l.insertAt(2,20);
		l.display();
		l.Delete();
		l.display();
		l.insertAt(3,30);
		l.display();
		l.DeleteAt(2);
		l.display();
		 return 0;
	}	 
		
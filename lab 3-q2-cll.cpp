#include <iostream>
using namespace std;

struct node // structure having pointer for the next node. 
{
   int data;
   node *next;

};	

class linkedList //  class having  functions to operate on the nodes
{

  private:
   node *head, *tail;   //Declaring pointers head and tail

  public:
   linkedList() //The constructer will make them NULL
   {
      head=NULL;
      tail=NULL;
   } 
   
  void insert(int value) //function to insert node at the end
  {
      node *temp=new node;
      temp->data=value;
      temp->next=NULL;
      if(head==NULL)
      {
        head=temp;
      }
      else
      { 
      	temp->next=head;	
        tail->next=temp;
      }
      tail=temp;
  }

  void insertAt(int pos,int value)//function to insert node  at a certain position
  {
    node *cur=new node;
    node *prev=new node;
    node *temp= new node;
    cur= head;
    temp->data=value;
    if(pos<=countItems()) 
    {
      for(int i=1;i<pos;i++)
      { 
      	prev= cur;
        cur=cur->next;	
      }
      prev->next=temp;
      temp->next=cur;
   }
   
  }
  
  void Delete()// function to delete last node
  {
   	 node*cur=new node;
     node*prev=new node;
     cur=head;
     while(cur->next!=head)
     {
   	    prev=cur;
    	cur=cur->next;
     }
     tail=prev;
     prev->next=head;
     delete cur;
  }
  
  void deleteAt(int pos)// function to delete node at a certain position
  {
     node *cur=new node;
     node *prev=new node;
     node *after=new node;
     cur=head;
     if(pos<=countItems()) //To check if the list has that many elements 
     {
       for(int i=1;i<pos; i++)
       {
     	prev=cur;
        cur=cur->next;
        after=cur->next;
       }
       prev->next=after;
       delete cur;
     }
  }   
  
    int countItems() //To count the number of elements in the list
    {      
    	int count=0;
    	node *temp=new node;
    	temp= head;
        do	
    	{ 
    	  temp=temp->next;
    	  count++;
    	}
        while(temp!=head);
    	return count;

    }

   void display()// to display the elements
   {
    	node*temp= new node;
    	temp=head;
    	cout<<"The list is: ";
    	do
    	{
    	    cout<<temp->data<<"->";
    	    temp=temp->next;
    	}

        while(temp!=head);
        cout<<endl;
   }
 };	

int main()
{

 linkedList l; // Declaring object of class linkedList

 l.insert(1);

 l.insert(2);

 l.display();

 cout<<"The total number of elements in the list is "<<l.countItems()<<endl;

 l.insertAt(2,3);

 l.display();

 l.Delete();

 l.display();

 l.insertAt(2,4);

 l.display();

  cout<<"The total number of elements in the list is "<<l.countItems()<<endl;

 l.deleteAt(2);

 l.display();

 l.insertAt(5,4);

 l.deleteAt(3);

 l.display();

	return 0;
}	
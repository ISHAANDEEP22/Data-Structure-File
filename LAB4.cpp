#include <iostream>

using namespace std;
struct node{
	int data;
	node *next;
	node *prev;
};node *head;
struct node2
{
	int data2;
	node2 *link;
}; //structure of linked list
node2 *head2; //pointers of node type
void insert_start(int value)//function to add an element at end
{
	node2 *temp=new node2;//creates a node at dynamic time.
	temp->data2=value; //assigning values to temporary node.
	temp->link=NULL;//assigning values to temporary node.
	if(head2==NULL)
{
	head2=temp;
	head2->link=head2;
}
else{
    node2 *temp2=head2;
	while(temp2->link!=head2)
	{
		temp2=temp2->link;
	}
	temp2->link=temp;
	temp->link=head2;
	head2=temp;
}
}
void insert_end(int value)
{
node2 *temp1=new node2;//creates a node at dynamic time.
	temp1->data2=value; //assigning values to temporary node.
	temp1->link=NULL;//assigning values to temporary node.
	node2 *temp2=head2;
while(temp2->link!=head2)
{
temp2=temp2->link;
}
temp1->link=temp2->link;
temp2->link=temp1;
}
void insert_p(int value)
{
    node2 *temp1=new node2;//creates a node at dynamic time.
	temp1->data2=value; //assigning values to temporary node.
	temp1->link=NULL;//assigning values to temporary node.
	node2 *temp2=head2;
	cout<<"enter position "<<endl;
	int n;
	cin>>n;
	for(int i=1;i<n;i++)
    {
        temp2=temp2->link;
    }
    temp1->link=temp2->link;
    temp2->link=temp1;
}
void create_node()//function to add an element if the node is empty
{

    int value;
    cout<<"enter value you want to insert"<<endl;
    cin>>value;
	node *temp=new node;//creates a node at dynamic time.
	temp->data=value; //assigning values to temporary node.
	temp->prev=NULL;//assigning values to temporary node.
	temp->next=NULL;
	if(head==NULL) //checks whether the linked list is empty or not
	{
		head=temp;
    }
    else{
       temp->next=head;//updating a address to add a particular node.
	head->prev=temp;
	head=temp;
    }

}
void insert_node3()//to insert at particular position
{
    int value;
    int position;
    int count1=1;
    cout<<"enter position where you want to insert"<<endl;
    cin>>position;
    if(position==1)// if the value is to be inserted at first position
    {
        create_node();
        return;
    }
    if(position!=1 && head==NULL)// if this function is called when the head is NULL
    {
        create_node();
        return;
    }
    cout<<"enter value you want to insert"<<endl;
    cin>>value;
	node *temp=new node;//create a temporary node
	temp->data=value;
	temp->prev=NULL;//to add in a list setting values to temp node.
	temp->next=NULL;
	node *temp2=head;
	while(temp2->next!=NULL && count1<position-1)
    {
        count1++;
        temp2=temp2->next;
    }
    if(count1==position-1)//inserts at position
    {
        if(temp2->next!=NULL)//if the position of the node to be inserted is not the last position.
        {
        temp->next=temp2->next;
        temp2->next->prev=temp;
        temp2->next=temp;
        temp->prev=temp2;
        }
        else// if the position of the node to be inserted is the last position
        {
             temp2->next=temp;
             temp->prev=temp2;
        }
    }
    else if(temp2->next==NULL && count1<position)// when the position user entered does not exist
    {
       //cout<<"position not found";//or simply insert at the end
       temp2->next=temp;
       temp->prev=temp2;
    }

}
void search()
{
    cout<<"enter the value of element to search in the linked list"<<endl;
    int n;
    cin>>n;
    int count=0;
    int c=0;
    node *temp1=head;
    while(temp1!= NULL)
	{
	    c++;
	    if(temp1->data==n)
        {
            count++;
            cout<<"element found at"<<c<<endl;
            break;
        }
		temp1=temp1->next;
	}
	if(count==0)
    {

        cout<<"no such element present"<<endl;
    }
}
 void insert_node2()//to insert at end
{
    int value;
        cout<<"enter value you want to insert"<<endl;
    cin>>value;
	node *temp=new node;//create a temporary node
	temp->data=value;
	temp->prev=NULL;//to add in a list setting values to temp node.
	temp->next=NULL;
	node *temp2=head;
	if(head==NULL)
    {
        head=temp;
        return;
    }
	while(temp2->next!= NULL)
	{
		temp2=temp2->next;
	}
	temp2->next=temp;
	temp->prev=temp2;//updating a address to add a particular node.

}
void display()
{
	node *temp=head;
	while(temp!= NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
void display2()
{
	node2 *temp=new node2;
	temp=head2;
	while(temp->link!=head2)
	{
		cout<<temp->data2<<" ";
		temp=temp->link;
	}
	cout<<temp->data2<<" ";
}
void search22(int n)
{
    node2 *temp=head2;
	int count=0;
	while(temp->link!=head2)
	{
		if(temp->data2==n)
        {
            count++;
            break;
        }
        count++;
		temp=temp->link;
	}
    if(count==0)
    {
        cout<<"element not found"<<endl;
    }
    else{
        cout<<"element found at"<<" " count " "<<"index"<<endl;
    }
}
void delete22(int n)
{

	node2 *temp=head2;
	int count=0;
	while(temp->link!=head2)
	{
		if(temp->data2==n)
        {
            count++;
            break;
        }
		temp=temp->link;
	}
	node2 *temp2=head2;
	while(temp2->link!=temp)
	{
		temp2=temp2->link;
	}
	if(count==1)
    {
       temp2->link=temp->link;
       delete(temp);
    }
    else{
        cout<<"element not a part of linked list"<<endl;
    }
}
void del()
{
	 cout<<"enter the value of element to delete from the linked list"<<endl;
    int n;
    cin>>n;
    int count=0;
    node *temp1=head;
    if(head->data==n)//element to be deleted is at the beg
    {

        head=head->next;
        head->prev=NULL;
        delete(temp1);
        return;

    }
    while(temp1->next!= NULL)
	{
	    if(temp1->data==n)
        {
            count++;
            node *temp2=temp1->next;
           temp2->prev=temp1->prev;
           temp1->prev->next=temp2;
           delete(temp1);
            break;
        }
		temp1=temp1->next;
	}
	if(temp1->next==NULL && temp1->data==n)//element to be deleted is at the last position
    {
        temp1->prev->next=NULL;
        temp1->prev=NULL;
        delete(temp1);
        }
	if(count==0)
    {

        cout<<"no such element present"<<endl;
    }
}
int main()
{
  cout<<"enter 1 to do operations on doubly linked list"<<endl;
  cout<<"enter 2 to do operations on circular linked list "<<endl;
  int a;
  cin>>a;
  if(a==1)
  {
	head=NULL;
	int choice;
    cout<<"Enter 1 to insert an element in beginning"<<endl;
    cout<<"Enter 2 to insert an element in end"<<endl;
    cout<<"Enter 3 to insert an element at particular position"<<endl;
    cout<<"Enter 4 to delete an element from linked list"<<endl;
    cout<<"Enter 5 to search an element in the linked list"<<endl;
    cout<<"Enter 6 to display the elements in the linked list"<<endl;
    cout<<"Enter 0 to exit"<<endl;
    cin>>choice;
    while(choice!=0)
    {
        switch(choice)
    {
        case 1:create_node();
                break;
        case 2:insert_node2();
                break;
        case 3:insert_node3();
                break;
        case 4:del();
                break;
        case 5:search();
                break;
        case 6:display();
                break;
    }
    cout<<endl<<endl<<endl;
     cout<<"Enter 1 to insert an element in beginning"<<endl;
    cout<<"Enter 2 to insert an element in end"<<endl;
    cout<<"Enter 3 to insert an element at particular position"<<endl;
    cout<<"Enter 4 to delete an element from linked list"<<endl;
    cout<<"Enter 5 to search an element in the linked list"<<endl;
    cout<<"Enter 6 to display the elements in the linked list"<<endl;
    cout<<"Enter 0 to exit"<<endl;
    cin>>choice;
    }
  }
  else if(a==2)
  {
	head2=NULL;
	int choice;
    cout<<"Enter 1 to insert an element in beginning"<<endl;
    cout<<"Enter 2 to insert an element in end"<<endl;
    cout<<"Enter 3 to insert an element at particular position"<<endl;
    cout<<"Enter 4 to delete an element from linked list"<<endl;
    cout<<"Enter 5 to search an element in the linked list"<<endl;
    cout<<"Enter 6 to display the elements in the linked list"<<endl;
    cout<<"Enter 0 to exit"<<endl;
    cin>>choice;
    while(choice!=0)
    {
        switch(choice)
    {
        case 1:int value;
        cout<<"enter element to insert"<<endl;
        cin>>value;
            insert_start(value);
                break;
        case 2:int value2;
        cout<<"enter element to insert"<<endl;
        cin>>value2;
        insert_end(value2);
                break;
        case 3:int value3;
        cout<<"enter element to insert"<<endl;
        cin>>value3;
        insert_p(value3);
                break;
        case 4:
            int value4;
        cout<<"enter element to delete"<<endl;
        cin>>value4;
        delete22(value4);
                break;
        case 5:
            int value5;
        cout<<"enter element to search"<<endl;
        cin>>value5;
        search22(value5);
                break;
        case 6:display2();
                break;
    }
    cout<<endl<<endl<<endl;
     cout<<"Enter 1 to insert an element in beginning"<<endl;
    cout<<"Enter 2 to insert an element in end"<<endl;
    cout<<"Enter 3 to insert an element at particular position"<<endl;
    cout<<"Enter 4 to delete an element from linked list"<<endl;
    cout<<"Enter 5 to search an element in the linked list"<<endl;
    cout<<"Enter 6 to display the elements in the linked list"<<endl;
    cout<<"Enter 0 to exit"<<endl;
    cin>>choice;
    }
  }
}

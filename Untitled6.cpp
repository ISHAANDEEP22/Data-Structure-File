#include<iostream>
using namespace std;
struct node{
	int data;
	node *link;
}; //structure of linked list
node *head; //pointers of node type
void push(int value)//function to add an element at end
{
	node *temp=new node;//creates a node at dynamic time.
	temp->data=value; //assigning values to temporary node.
	temp->link=NULL;//assigning values to temporary node.
	if(head==NULL) //checks whether the linked list is empty or not
	{
		head=temp;//assigning the address of temporary node to head and tail
		}
		else
		{
			temp->link=head;//assigning the address of temp to tail's lin
		head=temp;
				   }           
}
void display()
{
	node *temp=new node;
	temp=head;
	while(temp!= NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->link;
	}
}
void pop()
{
node *temp1=head;
for(int i=1;i<2;i++)
	{
		head=temp1->link;
	}
delete(temp1);
	
}
void top1()
{
cout<<"top is:"<<head->data;	
}
int main()
{
	head=NULL;
	int n;
    cout<<"enter 1 for push"<<endl;
    cout<<"enter 2 for pop"<<endl;
    cout<<"enter 3 to see top"<<endl;
    cout<<"enter 4 to display stack"<<endl;
    cout<<"enter 0 to exit"<<endl;
	cin>>n;
	 while(n!=0)
    {
        switch(n)
    {
        case 1:int x;
        cout<<"enter element"<<endl;
				cin>>x;
	        push(x);
	        break;
        case 2:pop();
                break;
        case 3:top1();
                break;
        case 4:display();
                break;
    }
    cout<<endl<<endl<<endl;
    cout<<"enter 1 for push"<<endl;
    cout<<"enter 2 for pop"<<endl;
    cout<<"enter 3 to see top"<<endl;
    cout<<"enter 4 to display stack"<<endl;
    cout<<"enter 0 to exit"<<endl;
	cin>>n;
    }
}


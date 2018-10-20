#include<iostream>
using namespace std;
#define MAX 100
class Stack
{
public:
    int a[MAX];    
    int top=0;
    int push(int x);
    int pop();
    void top1();
    int display();
    
};
void Stack::top1()
{
cout<<"top element is:"<<a[top];	
}
int Stack::push(int x)
{
	
      a[++top] = x;    
}
int Stack::pop()
{
    int x = a[top--];
}
int Stack::display()
 {
 	for (int i=1;i<=top;i++)
	{
	cout<<a[i]<<endl;
}
 }
int main()
{
    struct Stack s;
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
	        s.push(x);
	        break;
        case 2:s.pop();
                break;
        case 3:s.top1();
                break;
        case 4:s.display();
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

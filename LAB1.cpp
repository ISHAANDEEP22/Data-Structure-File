#include<iostream>
using namespace std;
int inserting(int arr[],int l)
{
    int x,n,i=0,t;
    cout<<"Enter element to insert:"<<endl;
    cin>>x;
    if(l==0)
        arr[0]=x;
        else
        {
        cout<<"Enter position of element in array:"<<endl;
        cin>>n;
        for(int i=l-1;i>=n-1;i--)
         {
          arr[i+1]=arr[i];
        }
        arr[n-1]=x;
        l++;
        }
    return l;
}
int deleting(int arr[],int l)
{
    int x,position;
    int choice;
    cout<<"Enter 1 to delete element by value"<<endl;
    cout<<"Enter 2 to delete a element by position"<<endl;
    cin>>choice;
    if(choice==1)
    {
        cout<<"Enter value:"<<endl;
        cin>>x;
        for(int i=0;i<l;i++)
            if(arr[i]==x)
                position=i;
        for(int i=position;i<l;i++)
                arr[i]=arr[i+1];
        l--;
    }
    else if(choice==2)
    {
        cout<<"Enter position of element:"<<endl;
        cin>>position;
        for(int i=position;i<l;i++)
                arr[i]=arr[i+1];
        l--;
    }
    return l;
}
void finding(int arr[],int l)
{
    int x,i=0;
    cout<<"Enter element to search"<<endl;
    cin>>x;
    int count=0;
    for(i=0;i<l;i++)
    {
        if(arr[i]==x)
        {cout<<"Element is found at position "<<i<<endl<<endl<<endl;
        count++;
        break;
    }
}
        if(count==0)
         cout<<"Element not present in the given array "<<endl<<endl<<endl;
}
void display(int arr[],int l)
{
    cout<<"The array is:";
    for(int i=0;i<l;i++)
        cout<<arr[i]<<" ";
        cout<<endl<<endl<<endl;
}
int main()
{
    int arr[10]={1,2,3,4,5};
    int choice;
    cout<<"Enter 1 to insert an element:"<<endl;
    cout<<"Enter 2 to delete an element:"<<endl;
    cout<<"Enter 3 to find location of element:"<<endl;
    cout<<"Enter 4 to print array:"<<endl;
    cout<<"Enter 0 to exit:"<<endl;
    cin>>choice;
    int l=5;
    while(choice!=0)
    {
        switch(choice)
    {
        case 1:l=inserting(arr,l);
                break;
        case 2:l=deleting(arr,l);
                break;
        case 3:finding(arr,l);
                break;
        case 4:display(arr,l);
                break;
    }
    cout<<"Enter your choice to select function:"<<endl;
    cout<<"Enter 1 to insert an element:"<<endl;
    cout<<"Enter 2 to delete an element:"<<endl;
    cout<<"Enter 3 to find location of element:"<<endl;
    cout<<"Enter 4 to print array:"<<endl;
    cout<<"Enter 0 to exit:"<<endl;
     cin>>choice;
    }
    return 0;
}

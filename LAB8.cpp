#include<iostream>
using namespace std;
class insertion
{
  public:
  	int size,arr[100];
    insertion()
    {
      cout<<"Enter the size of array: ";
      cin>>size;
      int arr[size];
    }
    void create()
    {
      cout<<"Enter the elements: ";
      for(int i=0;i<size;i++)
      {
        cin>>arr[i];
      }
    }
    void insertionsort()
    {
      int temp=0;
      int j=0;
      for(int i=0; i<size; i++)
    	{
    		temp=arr[i];
    		j=i-1;
    		while((temp<arr[j]) && (j>=0))
    		{
    			arr[j+1]=arr[j];
    			j=j-1;
    		}
    		arr[j+1]=temp;
    	}
    }
    void insert(int val)
    {
      int i=size-1;
      while(val<arr[i] && i>=0)
      {
        arr[i+1]=arr[i];
        i--;
      }
      arr[i+1]=val;
      size++;
    }
    void display()
    {
      for(int i=0; i<size; i++)
    	{
    		cout<<arr[i]<<" ";
    	}
    }
};
int main()
{
  insertion i;
  i.create();
	i.insertionsort();
  cout<<"Array after sorting: ";
  i.display();
  int val;
  cout<<"\nEnter the element to be inserted: ";
  cin>>val;
  i.insert(val);
  cout<<"Array after sequential insertion: ";
  i.display();
}

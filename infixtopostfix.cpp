#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<iostream>
# define MAX 100
using namespace std;

char st[MAX];
int top=-1;
void push(char);
char pop();
int infixtopostfix(char source[],char target[]);
int getpriority(char);
bool isoperand(char);
int main()
{
int l=0;
    char infix[100], postfix[100];
    cout<<"Enter infix expression"<<endl;
    cin.get(infix,100);
    strcat(infix,")");
    int x=infixtopostfix(infix,postfix);
    if(x==0)
        cout<<"invalid expression"<<endl;
       else
       {
           cout<<"postfix expression:";
           cout<<postfix;
       }

    return 0;
}
int infixtopostfix(char source[],char target[])
{
     int i=0,j=0;
     char temp;
     push('(');
     for(i=0;source[i]!='\0';i++)
     {
         if(source[i]=='(')
         {
             push('(');
         }
         else if(isalpha(source[i])||isdigit(source[i]))
         {
             target[j]=source[i];
             j++;
         }
         else if(source[i]==')')
         {
              while(top!=-1 && st[top]!='(')
              {
                   int x=pop();
                   target[j]=x;
                   j++;
              }
              if(top==-1)
              {
                  return 0;
              }
              else if(st[top]=='(')
              {
                  int y=pop();
              }

          }
          else if(isoperand(source[i]))
          {
              while(isoperand(st[top]) && st[top]!='(' && getpriority(source[i])<=getpriority(st[top]) )
              {

                  target[j]=pop();
                   j++;
              }
              push(source[i]);
          }
     }
     if(source[i]=='\0' && top!=-1)
     {
         return 0;
     }
     else
     {
         target[j]='\0';
         return j;
     }
}
bool isoperand(char c)
{
    if(c=='+'||c=='*'||c=='/'||c=='-'||c=='%'||c=='^')
        return true;
    else false;
}
int getpriority(char op)
{

    if(op=='^')
        return 2;
    else if(op=='*'||op=='/'||op=='%')
        return 1;
    else if(op=='+'|| op=='-')
        return 0;
}
void push(char val)
{

    if(top==MAX-1)
        printf("overflow");
    else
    {
        top++;
        st[top]=val;
    }
}
char pop()
{

    char val;
    if(top==-1)
    {

        printf("underflow");
    }
    else
    {
        val=st[top];
        top--;
    }
    return val;
}


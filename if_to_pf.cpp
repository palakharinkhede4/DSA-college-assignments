//TO CONVERT INFIX EXPRESSION TO POSTFIX EXPRESSION...

#include<iostream>
#include<stdlib.h>
#include<string.h>
#define MAX 50

using namespace std;

class Stack
{

private:
    int data[MAX];
    int top;
//     char input[MAX];
//     char x[MAX];

public:

    Stack()
    {
        top=-1;
//         length=0;

    }//constructor


    int stacktop()
    {

        return data[top];

    }//stacktop



    void push(int d)
    {
        if(top==(MAX-1))
        {
            cout<<"\nStack is Full\n";
            return;

        }
        data[++top]=d;

    }//push


    int pop()
    {

        return data[top--];

    }//pop



    int isempty()
    {

        return(top==-1);

    }//isempty



};//CLASS STACK


class evaluate

{

private:
    char input[MAX],post[MAX];

    Stack s;


public:

    void getstring()
    {
        //cin.ignore();


        cout<<"\nenter the infix expression to be converted\n";
        cin.getline(input,MAX);
    //    length=strlen(input);

    }//getstring


    void inf_to_post()
    {
        int i,j;
        char ch,ch1;

        s=Stack();

        for(i=0,j=0;input[i]!='\0';i++)
        {
            ch=input[i];

            switch(ch)

            {
                case '(': s.push(ch);
                            break;


                case '+':

                case '-':

                case '/':

                case '*': if(s.isempty())
                          {
                              s.push(ch);
                          }//if

                          else
                          {
                              ch1=s.stacktop();

                              while(priority(ch1)>=priority(ch))
                              {
                                  ch1=s.pop();
                                  post[j++]=ch1;
                                  ch1=s.stacktop();

                              }//while

                          s.push(ch);

                          }//else

                          break;



                case')':
                         ch1=s.pop();

                         while(ch1!='(')
                         {
                             post[j++]=ch1;
                             ch1=s.pop();

                         }//while

                         break;

                default:
                    post[j++]=ch;

            }//switch

        }//for




        while(!s.isempty())
        {

            post[j++]=s.pop();

        }//while

        post[j]='\0';

        cout<<"\nTHE POSTFIX EXPRESSION IS "<<post;

    }//convert

      int priority(char ch)
      {

          switch(ch)
          {
              case '*':

              case '/': return 2;


              case '+':

              case '-': return 1;


              case '(': return 0;

          }//switch

          return -1;

      }//priority

int find()
 {
 char ch;
  int op1,op2,v,i;
  float r;
 cout<<"\nEvaluation....";
 for(i=0;post[i]!='\0';i++)
 {
 ch=post[i];
 if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))
 { // It is alphabet
 cout<<"Pls enter value of variable "<<ch<<"\t";
 cin>>v;
 s.push(v);
 }
 else
 { // it is operator
 op2=s.pop();
 op1=s.pop();
 switch(ch)
 {
 case '+': r=op1+op2;
 break;

 case '-': r=op1-op2;
 break;

 case '*': r=op1*op2;
 break;

 case '/': r=op1/op2;
 break;

 }//switch

 s.push(r);
 }//else
}//for

 r=s.pop();

 cout<<"result is\t"<<r;
}//find

};//CLASS

int main()
{

    evaluate e1;
    e1.getstring();

    e1.inf_to_post();
    e1.find();

    return 0;
}//main





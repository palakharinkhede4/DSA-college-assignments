#include<iostream>
#include<string.h>
using namespace std;
#define MAX 5
class Queue
{
char name[20][20],code[20][10];
int front,rear;
public:
Queue()
{
 front=0;
 rear=0;
}
void insert(char n[],char c[])
{
 // Increment rear in circular fashion
 if(rear==MAX-1)
 rear=0; // circular queue
 else
 rear++;
 strcpy(name[rear],n);
 strcpy(code[rear],c);
}//insert
void remove(char n[],char c[])
{
 // Increment front in circular fashion
 if(front==MAX-1)
 front=0;
 else
 front++;
 strcpy(n,name[front]);
 strcpy(c,code[front]);
}//remove
void current(char n[],char c[])
{
 strcpy(n,name[front+1]);
 strcpy(c,code[front+1]);
}
int isempty()
{
 return(front==rear);
}
int isfull()
{
 if( (rear+1)%MAX==front)
 return 1;
 return 0;
}
void display()
{
 int j,k;
 j=front;
 k=rear;
 do
 {
 j=(j+1)%MAX;
 cout<<"\n\t"<<name[j]<<"\t"<<code[j];

 }while(j!=k);
}//display
};//class Queue
int menu()
{
 int choice;
 cout<<"\n1.Place an order.";
 cout<<"\n2.Current Order.";
 cout<<"\n3.Order Delivery.";
 cout<<"\n4.Display Order List.";
 cout<<"\n5.Exit";
 cout<<"\n\tEnter your choice\t";
 cin>>choice;
 return choice;
}//menu
int main()
{
Queue q;
int choice,x;
char n[20],c[10];
while(1)
{
 choice=menu();
 switch(choice)
 {
 case 1: if(q.isfull())
 {
 cout<<"\nmaximum limit reached\n";
 }
 else
 {
 cout<<"\nenter your name\n";
 cin>>n;
 cout<<"\nplease select any pizza";
 cout<<"\nClassic cheese paneer pizza(1)/Magic pan corn pizza(2)\n\t";
 cin>>x;
 if(x==1)
 q.insert(n,"CCP");
 else if(x==2)
 q.insert(n,"MPCP");
 else
 cout<<"\nEnter correct choice...";
 }
 break;
 case 2: if(q.isempty())
 cout<<"\nno order to be delivered\n";
 else
 {
 	cout<<"\ncurrent order is\n";
 q.current(n,c);
 cout<<"\n\t"<<n<<"\t"<<c;
 }
 break;
 case 3: if(q.isempty())
 cout<<"\nno order to be delivered\n";
 else
 {
 cout<<"\nOrder Delivery for";
 q.remove(n,c);
 cout<<"\n\t"<<n<<"\t"<<c;
 }
 break;
 case 4: if(q.isempty())
 cout<<"\nno order to be delivered";
 else
 q.display();
 break;
 case 5: cout<<"\n Program ending....";
 return 0;
 default: cout<<"\nWrong choice...";
}//switch
 }//while
}//main

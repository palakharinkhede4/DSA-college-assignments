#include<iostream>
#include<string.h>
using namespace std;
class node
{
char id[20];
node *next;
public:
node()
{
 id[0]='\0';
 next=NULL;
}
node(char id[])
{
 strcpy(this->id,id);
 next=NULL;
}
friend class list;
};
class list
{
node *front,*rear;
public:
list()
{
 front=NULL; // front is similar to headnd
}
void addjob(char id[]) // is same as insert() function
{
 node *newnd;
 newnd=new node(id);
 if(front==NULL)
 { front=newnd;
 rear=newnd;
 }
 else
 { rear->next=newnd;
 rear=newnd;
 }
}//addjob
void curjob()
{
if(front==NULL)
 cout<<"\nno job in a queue\n";
else
 cout<<"\ncurrent job is=\t"<<front->id;
}// curjob
void execute() // is same as remove() function
{
node *tempnd=front;
if(tempnd==NULL)
 cout<<"\nthere is no pending job\n ";
else
{ cout<<"\nexecuted job is\t"<<tempnd->id;
 front=front->next;
 delete tempnd;
}
}//execute
void displaylist()
{
node *current;
if(front==NULL)
{
 cout<<"\nthere is no pending job in a queue\n";
 return;
}
 cout<<"list of jobs are\n";
 for(current=front;current!=NULL;current=current->next)
 {
 cout<<"\n\t"<<current->id;
 }//for
}//displaylist
};//class list
int menu()
{
 int choice;
 cout<<"\n1.Add Job";
 cout<<"\n2.Current Job";
 cout<<"\n3.Execute Job";
 cout<<"\n4.Display Job List";
 cout<<"\n5.Exit";
 cout<<"\n\tEnter your choice\t";
 cin>>choice;
 return choice;
}//menu
int main()
{
int choice;
char idd[20];
list l;
while(1)
{
 choice=menu();
 switch(choice)
 {
 case 1: cout<<"enter the job id\n";
 cin>>idd;
 l.addjob(idd);
 break;
 case 2: l.curjob();
 break;
 case 3: l.execute();
 break;
 case 4: l.displaylist();
 break;
 case 5: cout<<"\n Program ending....";
 return 0;
 default: cout<<"\nWrong choice...";
 }//switch
 }//while
}//main

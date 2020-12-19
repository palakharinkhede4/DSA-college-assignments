#include <iostream>
#include<stdlib.h>
using namespace std;
class Node{
    int data;
    Node *next, *prev;
    public:
    Node(){
        data=0;
        next=prev=NULL;
    }
    void setdata(int num)
    {
        data=num;
    }
    int getdata()
    {
        return data;
    }
    void setnext(Node *n)
    {
        next=n;
    }
    void setprev(Node *p)
    {
        prev=p;
    }
    Node* getnext()
    {
        return next;
    }
     Node* getprev()
    {
        return prev;
    }
};
class DLL
{
    Node *head;
    int tot_r, tot_c;
    public:
    DLL()
    {   
        head=NULL;
    }
    void setTheater(int r,int c)
    {
        tot_r=r;
	tot_c=c;
    }
    int get_rows()
   {
     return tot_r;
   }
    void bookSeat(int c)
    {
        Node *new1,*temp;
        new1=new Node();
        new1->setdata(c);
       
        if(head==NULL)
        {
            new1->setnext(new1);
            new1->setprev(new1);
            head=new1;
        }
        else{
             
            temp=head;
            do{
                   if(temp->getdata()==c)
                   {
                         cout<<"\n SORRY This seat is already booked!! Choose another seat\n";
                         return;
                   }
            }while(temp!=head); 
            if(temp==head)
            {
            new1->setnext(head);
            new1->setprev(head->getprev());
            head->getprev()->setnext(new1);
            head->setprev(new1);
            head=new1;
            }
        }
    }
   
    void cancleSeat(int c)
   {
       Node *temp;
       temp=head;
       if(head==NULL)
        {
            cout<<"\n No booking for this seat!! kindly enter correct seat\n";
            return;  
        }
       if(temp->getnext()==head)
       { 
           if(temp->getdata()==c)
              head=NULL;
           else
           {   cout<<"\n No booking for this seat!! kindly enter correct seat\n";
            return;}
       }
       do
       { 
         if(temp->getdata()==c)
         {
             temp->getprev()->setnext(temp->getnext());	
		  temp->getnext()->setprev(temp->getprev());  
 		  temp->setprev(NULL);
             temp->setnext(NULL);
 		  delete(temp);
             break;
         }
        temp=temp->getnext();
       }while(temp!=head);
       if(temp==head)
        {  cout<<"\n No booking for this seat!! kindly enter correct seat\n";
            return;
        }
   }
   
   void display()
   {
       Node *temp;
       if(head==NULL)
       {
            for(int col=1;col<=tot_c;col++)
            {
                cout<<col<<"E"<<"   ";
            }
       }
       else
       {    
         
            for(int col=1;col<=tot_c;col++)
            {    temp=head;
                 int flag=0;
            do{
               if(temp->getdata()==col)
                {
                   cout<<col<<"B"<<"   ";
                   flag=1;
                   break;
                }
               temp=temp->getnext();
              
            }while(temp!=head);
            if(temp==head && flag==0)
            {
                 cout<<col<<"E"<<"   ";
            }

           }
       }
   }
    
};
int main() {
   int ch,r,c;
   cout<<"\n Enter total row and col of theater:";
   cin>>r>>c;
   DLL theater[r];
   for(int i=0;i<r;i++)
     theater[i].setTheater(r,c);
   while(1)
   {  
      cout<<"\n Menu: \n 1. Book seat \n 2. Cancle Seat \n 3. Diaplay cinemax \n 4. Exit";
      cout<<"\n Enter Choice:";
      cin>>ch;
      switch(ch)
      {
        case 1:  
                 cout<<"\n Enter row and col to book seat:";
      		 cin>>r>>c;
                 theater[r].bookSeat(c);
                 break;
       case 2:

                 cout<<"\n Enter row and col to cancle seat:";
      		 cin>>r>>c;
                 theater[r].cancleSeat(c);
                 break;
      case 3: 
                 cout<<"\n *******Cinemax Theater*******\n ";
                 for(int i=0;i<theater[0].get_rows();i++)
                 { 
                   cout<<"\nRow-"<<i<<" ";
                   theater[i].display();
                 }
                 break;
      case 4: exit(0);
      }
   }
   
}

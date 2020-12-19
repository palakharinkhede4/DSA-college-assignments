#include<iostream>
#include<stdlib.h>
using namespace std;

class node
{
 private:
   int data;
   node *next;
 public:
   void set_data(int d)
   {
     data=d;
   }
   int get_data()
   {
     return data;
   }
   void set_next(node *n)
   {
     next=n;
   }
   node* get_next()
   {
     return next;
   }
};

class linkedlist
{
 private:
   node *head;
 public:
   linkedlist()
   {
     head=NULL;
   }
   void create(int d)
   {
     node *new1,*temp;
     
     new1=new node();
     new1->set_data(d);
     new1->set_next(NULL);
     if(head==NULL)
     {
       head=new1;  
     }
     else{
       temp=head;
     while(temp->get_next()!=NULL)
     {
       temp=temp->get_next();  
     }
     temp->set_next(new1);
     }
   }
   void display()
   {
     node *temp;
     temp=head;
     cout<<head<<" \n";
     while(temp!=0)
     {
       cout<<temp->get_data()<<"-->";
       temp=temp->get_next();
     }
     cout<<"NULL";
   }
  void union1(linkedlist L1, linkedlist L2)
  {
       node *tempL1,*tempL2;
       
       if(L1.head==NULL || L2.head==NULL)
       { 
	  cout<<"\n Error....List is/are empty";
	  return;
       }
       else
       {
	tempL1=L1.head;   //copy list 1
	 while(tempL1!=NULL)
	 {
	     create(tempL1->get_data());
	     tempL1=tempL1->get_next();
	 }
// 	 
         tempL2=L2.head;
	 while(tempL2!=NULL)
	 {  
	    tempL1=L1.head;
	    while(tempL1!=NULL)
	    {
	        if(tempL1->get_data()==tempL2->get_data())
		{
		   break;
		}
		tempL1=tempL1->get_next();
	    }
	    
	    if(tempL1==NULL)
	    {
	       create(tempL2->get_data());
	    }
	    
	    tempL2=tempL2->get_next();
	   
	 }
	 
	   
       }
  }
  void intersection(linkedlist L1, linkedlist L2)
  {
       node *tempL1,*tempL2;
        if(L1.head==NULL || L2.head==NULL)
       { 
	  cout<<"\n Error....List is/are empty";
	  return;
       }
       else
       {
       
         tempL2=L2.head;
	 while(tempL2!=NULL)
	 {  
	    tempL1=L1.head;
	    while(tempL1!=NULL)
	    {
	        if(tempL1->get_data()==tempL2->get_data())
		{
		   create(tempL2->get_data());
		   break;
		   
		}
		tempL1=tempL1->get_next();
	    }  
	  tempL2=tempL2->get_next();
	 }
	 
      }
  }
  
   void difference(linkedlist L2, linkedlist L1)
  {
    node *tempL1,*tempL2;
    if(L1.head==NULL || L2.head==NULL)
       { 
	  cout<<"\n Error....List is/are empty";
	  return;
       }
       else
       {
    tempL2=L2.head;
	 while(tempL2!=NULL)
	 {  
	    tempL1=L1.head;
	    while(tempL1!=NULL)
	    {
	        if(tempL1->get_data()==tempL2->get_data())
		{
		   
		   break;
		   
		}
		tempL1=tempL1->get_next();
	    }  
	  if(tempL1==NULL)
		{
		create(tempL2->get_data());
		}
		tempL2=tempL2->get_next();
	 }
       }
	 
  }
};
int main()
{
  int choice,d,n;
  linkedlist L1,L2,L3,L4,L5,L6,L7,L8;
  
  while(1)
  {
  cout<<"\n Menu--> \n 1. Create list-1 \n 2. Create list-2\n 3. Display list-1\n 4. display list-2\n5. union\n6. intersection\n 7. diff_L1L2\n 8. diff_L2L1\n 9. complement of union\n 10. Exit"; 
  cout<<"\n Enter Choice:";
  cin>>choice;
  
  switch(choice)
  {
    case 1: 
     cout<<"\nenter the roll number of student who like vanilla icecream:  ";
     cin>>d;
          L1.create(d);
	  break;
    case 2: 
     cout<<"\nenter the roll number of student who like butterscotch icecream:  ";
     cin>>d;
          L2.create(d);
	  break;
    case 3: 
  cout<<"\nThe roll numbers of students who like vanilla icecream  ";          
          L1.display();
	  break;
    case 4: 
  cout<<"\nThe roll numbers of students who like butterscotch icecream:  ";           
          L2.display();
	  
	  break; 
    case 5:
  cout<<"\nThe roll numbers of students who like vanilla or butterscotch icecream or both:  ";          
           L3.union1(L1,L2);   
	   L3.display();
           break;
    case 6:
  cout<<"\nThe roll numbers of students who like both vanilla and butterscotch icecream:  ";          
          L4.intersection(L1,L2);
	  L4.display();
	  break;
    case 7:
  cout<<"\nThe roll numbers of students who like only vanilla icecream:  ";          
          L5.difference(L1,L2);
	  L5.display();
	  break;
    case 8:
  cout<<"\nThe roll numbers of students who like only butterscotch icecream:  ";          
          L6.difference(L2,L1);
	  L6.display();
	  break;
    case 9:
          cout<<"\nenter the total number of students: ";
	  cin>>n;
	  for(int i=1;i<=n;i++)
	  {
	    L7.create(i);
	  }
	  L3.union1(L1,L2);
	  L8.difference(L7,L3);
  cout<<"\nThe roll numbers of students who neither like vanilla nor like butterscotch:  ";          
	  L8.display();
	  break;
    case 10:
         exit(0);
            
 }
}
 
}

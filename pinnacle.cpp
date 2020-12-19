#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;


class club
{
private:
  char n[30],PRN[15],post;//post j is for president, m for members , s for secretary  
   club *next;
   
   
public:
   void set_data(char a[30],char p[15],char pt)
   {
     strcpy(n,a);
     strcpy(PRN,p);
     post=pt;
   }
   
   void set_next(club *c)
   {
     next=c;
   }
   
   char* get_name()
   {
     return n;
   }
   
   char* get_PRN()
   {
     return PRN;
     
   }
   
   club* get_next()
   {
     return next;
   }
   
   char get_post()
   {
       return post;
   }

};

class pinc_club
{
  club *head;
  int pflag,sflag;
  
public:
   pinc_club()
   {
     head=NULL;
     pflag=sflag=0;  //no  president as well as secretary
   }
   
   
     
   void create_mem(char a[30],char p[15],char pt)
   {
     
       
     club *mem1,*temp;
     
     mem1=new club();
    mem1->set_data(a,p,pt);
    mem1->set_next(NULL);
     

     
    if(pt=='j' && pflag==1)
     {
         cout<<"\nPRESIDENT ALREADY PRESENT..\n";
         return;
         
     }
     else if(pt=='s' && sflag==1)
     {
         cout<<"\nSECRETARY ALREADY PRESENT..\n";
         return;
     } 
     
     
     //FIRST NODE CHECK..
      
     if(head==0)
     {
       head=mem1;
       if(pt=='j')  //PRESIDENT AS FIRST NODE  
           pflag=1;
           
       if(pt=='s')    //SECRETARY AS FIRST NODE
        sflag=1;
       return;
       
     }
     
    
    
        
     //OTHER THAN FIRST NODE CHECK..
     
     if(pt=='j')   //make president first node
     {
        
         mem1->set_next(head);
         head=mem1;
         pflag=1;
         return;
     }
     
     if(pt=='s')  //make secretary last node
     {
         temp=head;
         while(temp->get_next()!=NULL)
         {
             temp=temp->get_next();
         }
         temp->set_next(mem1);
        // mem1->set_next(NULL);
         sflag=1;
         return;
         
     }
         
         // OTHER THAN PRESIDENT AND SECRETARY...
         
         if(sflag==0)  //secretary not there ,add at last node
         {
             
          temp=head;
          
          while(temp->get_next()!=NULL)
             {
             temp=temp->get_next();
             }
              temp->set_next(mem1);
             // sflag=1;
              return;
       
         }
         
         if(head->get_post()=='s')  // only secretary present ,add at start
         {
             mem1->set_next(head);
             head=mem1;
             return;
         }
             
          if(sflag==1)          //secretary present at last,add at second last node   
          {
              temp=head;
              
              while(temp->get_next()->get_next()!=NULL)
              {
                  temp=temp->get_next();
              }
              mem1->set_next(temp->get_next());
              temp->set_next(mem1);
              return;
          }
        
     
   }
     
   void display_mem()
   {
  
       club *temp;
       
       if(head==NULL)
       {
           cout<<"\nList Is Empty\n";
           return;
       }
     
     temp=head;
     cout<<head<<"\n";
     cout<<"NAME,PRN,AND POST OF STUDENTS\n";
     
     while(temp!=0)
     {
       cout<<"1.NAME : "<<temp->get_name()<<" "<<"2. PRN : "<<temp->get_PRN()<<" "<<"3. POST : "<<temp->get_post()<<"\n"; 
	temp=temp->get_next();
     }
     cout<<"NULL";
   }
   
      
   
//DELETE OPERATIONS
   
      void cancel_mem()
      {
        club *prev,*temp;
        
        // CHECK FOR EMPTY LIST 
        
            if(head==NULL)
            {
                cout<<"\nCANNOT DELETE FROM AN EMPTY LIST\n";
                return;
            }
             
             char target[15];
             int flag=0;
             
             cout<<"\nEnter the PRN of the member to be deleted..\n"; 
             
             cin.ignore();
             cin.getline(target,15);
             
             
        //1. DELETE AT START(PRESIDENT..)
        
             if(strcmp(head->get_PRN(),target)==0)
             {
                temp=head;
              head=head->get_next();
              
              cout<<"\n"<<head<<"\n";
              flag=1;
              
             }
        
        
        //2. DELETE OTHER NODES(OTHER THAN PRESIDENT)
            
            else
            {
                       prev=temp=head;
       
                while(prev->get_next()!=NULL)
                {
                    if(strcmp(prev->get_next()->get_PRN(),target)==0)
                    {
                    cout<<"\nMEMBERSHIP OF THE STUDENT IS BEING CANCELED\n";
                    temp=prev->get_next();
                    prev->set_next(temp->get_next());
                    flag=1;
                    break;
                    }
                    
                    prev=prev->get_next();
                }
            }
                
                 if(flag==1)
                  {
                    cout<<"\nMEMBERSHIP CANCELED..\n";
                     
                     if(temp->get_post()=='j')
                         pflag=0;
                     if(temp->get_post()=='s')
                         sflag=0;
                     
                     delete(temp);
                     
                    return;
                 }
                
                
                else
                {
                    cout<<"\nMEMBERSHIP NOT FOUND\n";
                }
            
            
            }
        
        
      
//       TO COUNT TOTAL  MEMBERS OF THE CLUB

      void count()
      {
          int cnt=0;
          club *temp;
          
          temp=head;
          while(temp!=NULL)
          {
              temp=temp->get_next();
              cnt++;
          }
              cout<<"\nTHE TOTAL MEMBERS OF THE CLUB ARE.. "<<cnt<<"\n";
      }
      
      
//     TO DISPLAY LIST OF CLUB MEMBERS IN REVERSE ORDER..(using recursion)    
      void disp_rev()
      {
          club *temp;
          temp=head;
          rev(temp);
      }
      
      void rev(club *t)
      {
          if(t==NULL)
          {
              return;
          }
          
          else
          {
              rev(t->get_next());
              cout<<"1.NAME : "<<t->get_name()<<" "<<"2. PRN : "<<t->get_PRN()<<" "<<"3. POST : "<<t->get_post()<<"\n"; 
          }
          
      }
          
          
//    TO COMBINE TWO DIVISION MEMBERS OF SE AS  CLUB MEMBERS..(concatnate two lists)
    pinc_club conc_div(pinc_club m)
    {
        pinc_club q;
        club *temp,*tempm1;
    
        
        if(this->head==NULL && m.head==NULL)
         {
             
                cout<<"\nError: List is empty\n";
                q.head=NULL;
                return q;
         }
         
         if(this->head==NULL)
         {
             q=m;
             return q;
         }
         
         if(m.head==NULL)
         {
             q=*this;
             return q;
         }
         
         //point to last node of the first list
       
            q=*this;
            
            tempm1=this->head;
            //tempm1=m1.head;
            //tempm2=m2.head;
            while(tempm1->get_next()!=NULL)
            {
                tempm1=tempm1->get_next();
            }
            
            //link last node to first node of the second list
            
            tempm1->set_next(m.head);
            return q;
        }
        
};


  int main()
  {
    
    
    int choice;
    char a[30], p[15],pt;
    pinc_club m1,m2,m3;
    while(1)
    {
        
        
      cout<<"\nEnter a choice to perform following operations\n";
     cout<<"\n1.To Enter the Name And PRN Of Students Of SE 1 Division\n2.To Enter the Name And PRN Of Students Of SE 2 Division\n3.To Display the Name And PRN Of Students Of SE 1 Division\n4.To Display the Name And PRN Of Students Of SE 2 Division\n5.To Cancel Membership Of SE 1 Students..\n6.To Cancel Membership Of SE 2 Students\n7.TO COMBINE TWO DIVISION MEMBERS OF SE AS  CLUB MEMBERS\n8.TO COUNT TOTAL  MEMBERS OF THE CLUB\n9.TO DISPLAY LIST OF CLUB MEMBERS IN REVERSE ORDER\n10.To Exit\n";             
     cin>>choice;
     
      switch(choice)
      {
     case 1:
     
     cout<<"\nEnter the Name And PRN Of Students..\n";
     cout<<"1.Enter Name :";
     cin>>a;
     cout<<"2.Enter PRN :";
     cin>>p;
     cout<<"3.Enter Post :(j for present, s for secretary , m for members)";
     cin>>pt;
    
     m1.create_mem(a,p,pt);
     
         
     break;
     
     case 2:
     
     cout<<"\nEnter the Name And PRN Of Students..\n";
     cout<<"1.Enter Name :";
     cin>>a;
     cout<<"2.Enter PRN :";
     cin>>p;
     cout<<"3.Enter Post :(j for present, s for secretary , m for members)";
     cin>>pt;
    
     m2.create_mem(a,p,pt);    
     break;
     
       
       case 3:
           
     cout<<"\nThe Students Of SE 1 Division are..\n";
     m1.display_mem();
     break;
 
   
     case 4:
         
     cout<<"\nThe Students Of SE 2 Division are..\n";
     m2.display_mem();
     break;
     
         
     case 5:    
     m1.cancel_mem();
     break;
         
     case 6:
     m2.cancel_mem();
     break;    
       
     
     case 7:
     m3=m1.conc_div(m2);    
     cout<<"\nTHE COMBINED MEMBERS OF SE 1 AND SE 2 TOGETHER ARE..\n";
     m3.display_mem();
     break;
         
    
    
    
     case 8:
     m3.count();
     break;
     
     case 9:
     cout<<"\nLIST OF CLUB MEMBERS IN REVERSE ORDER IS: \n";
         
     m3.disp_rev();    
     break;
     
     
     case 10:
     exit(0);
      }
      
    }
    return 0;
  }

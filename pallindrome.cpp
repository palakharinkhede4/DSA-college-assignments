//TO CHECK FOR PALINDROME OF A STRING ...

#include<iostream>
#include<stdlib.h>
#include<string.h>

#define MAX 50

using namespace std;

class Stack
{
    
private:
    char data[MAX];
    int top,length,cnt;
    char input[MAX];
    
    
public:
    
    Stack()
    {
        top=-1;
        length=0;
        
    }//constructor
    
    
    void push(char d)
    {
        if(top==(MAX-1))
        {
            cout<<"\nStack is Full\n";
            return;
            
        }
        data[++top]=d;
        
    }//push
    
    
    char pop()
    {
        if(top==-1)
        {
            cout<<"\nStack is empty!\n";
            
        }//if
        
       char ch=data[top--];
        return ch;
        
    }//pop
    
    
    void getstring()
    {
        cin.ignore();
                    
        
        cout<<"\nenter the string to be pushed\n";
        cin.getline(input,MAX);
        length=strlen(input);
    }//getstring
    
    
    void checkpalindrome()
    {
        int cnt=0;
        
        for(int i=0;i<length;i++)
        
            push(input[i]);
            
        for(int i=0;i<length;i++)
        {
            if(input[i]==pop())
            
                cnt++;  
            else
                cnt=0;
        
        }//for
        cout<<"count"<<cnt<<"\n";
        cout<<"length"<<length<<"\n";
        if(cnt==length)
        
            cout<<"\nThe given string is a PALINDROME\n";
        
        else
        
            cout<<"\nThe given string is  NOT a PALINDROME\n";
        
    }//checkpalindrome
        
        
        
      void editstring() 
      //to remove punctuations,spaces and converting string to  lowercase  respectively and then check for PALINDROME..
      {
          char temp[MAX];
          int i,j;
          
          //FISRT COPY ORIGINAL STRING TO A TEMPORARY STRING..
          
          for(i=0;i<length;i++)
          {
              temp[i]=input[i];
          }
          
          //NOW CHECK FOR LOWERCASE 
          
          for(i=0,j=0;i<length;i++)
          {
              if(temp[i]>='a' && temp[i]<='z')  //lowercase already present
                   
              {
                  input[j++]=temp[i];   //copy as it is
              }
              
              if(temp[i]>='A' && temp[i]<='Z')
              {
                  temp[i]+=32;            //conversion to lowercase
                  input[j++]=temp[i];     //then copy  
              }
              //Thus Spaces and symbols are not copied
          }
          
          input[j]='\0';
          
          cout<<"\nMODIFIED STRING IS "<<input<<"\n";
          
          length=j;   //modify length of the string..
          
      }//editstring

      
      void reverse_string()
      {
          for(int i=length-1;i>=0;i--)
          {
              
              cout<<input[i];
          }
          cout<<"\n";
      }
      
};//class stack

int main()
{
    Stack s;
    int choice;
    
    
    while(1)
    {
        
        
        cout<<"\nplease select any of following operation\n";
        cout<<"\n1.To enter the string\n2.To check whether given is PALINDROME\n3.to remove punctuations,spaces and converting string to lowercase\n4.To reverse the given string\n5.exit\n";
        cin>>choice;
        
        switch(choice)
        {
            case 1:
                
                s.getstring();

            break;


            case 2:
                
                s.checkpalindrome();
                
            break;
          
          
            case 3:
          
                s.editstring();
                
                break;
          
            case 4:
                
                cout<<"\nREVERSE OF GIVEN STRING IS :\n";
                
                s.reverse_string();
                
                break;
                
                  
            case 5:
                exit(0);
                
        }//switch
        
    }//while
    
}//main

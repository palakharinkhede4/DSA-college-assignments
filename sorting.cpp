// ASSIGNMENT NUMBER 12:TO IMPLEMENT SORTING TECHNIQUES..

#include<iostream>

using namespace std;

class sort
{
    
  private:
  float P[10];
  int i,j,size_a;
  
  public:

  int read_arr()
{
    
    cout<<"\nEnter the total number of students  \n";
    cin>>size_a;
    
   cout<<"\nEnter the percentages  of students\n";
       for(j=0;j<size_a;j++)
        {
          cin>>P[j];
        }
}

// SELECTION SORT... 

  int sel_sort()
  {
     
      int curr,sm=0,run;
      float k;
    
      for(curr=0;curr<size_a-1;curr++)
         {
           for(run=curr+1;run<size_a;run++)
            {
	          sm=curr;
	           if(P[sm]>P[run])
	            {
	              sm=run;
                }
            
            k=P[sm];
            P[sm]=P[curr];
            P[curr]=k;
         }
       
       }     
     
     cout<<"\nThe values in ascending order..\n";
          for(j=0;j<size_a;j++)
          {
              
	        cout<<P[j]<<"\n";
          
          } 
   
}
// BUBBLE SORT... 

  void bubble_sort()
{
       
     float temp;
     
     for(int i=1;i<size_a;i++)
      {
        for(int counter=0;counter<size_a-i;counter++)
           {
            if(P[counter]>P[counter+1])
              {
                temp=P[counter+1];
                P[counter+1]=P[counter];
                P[counter]=temp;
              }
           }
           
      cout<<"pass"<<i<<"\n";
          for (int i=0;i<size_a;i++)
            {
              cout<<P[i]<<"\t";
            }
         cout<<"\n";
       }
     cout<<"\nfinal\n";
    
       for (int i=0;i<size_a;i++)
          {
            cout<<P[i]<<"\t";
          }
     cout<<"\n";
     
}

//  INSERTION SORT...

  void insertion_sort()
{
    
  float hold;
  
    for(int current=1;current<size_a;current++)
  {
        hold=P[current];
        int walker=current-1;
        
          while(walker>=0 && P[walker]>hold)
            {
              P[walker+1]=P[walker];
              walker--;
            } 
       P[walker+1]=hold;
    cout<<"pass"<<current<<"\n";
    
          for (int k=0;k<size_a;k++)
             {
               cout<<P[k]<<"\t";
             }
     cout<<"\n";
   }
   
     cout<<"\nfinal\n";
       for(int i=0;i<size_a;i++)
          {
            cout<<P[i]<<"\t";
          }
        cout<<"\n";
}

//   DISPLAY ..
   void display_scores()
{
    
   cout<<"\n Marks of top five students are\n";
   
       for (int i=size_a-1;i>size_a-6;i--)
          {
           cout<<P[i]<<"\t";
          }
    cout<<"\n";
}

};




  int main()
{
    
    sort s1;
    int c;
    
    
  while(1)
   {
        
     cout<<"\n Enter \n 1. To store Percentage of First Year Students \n 2. for Bubble sort \n 3. for Selection sort\n 4. for Insertion sort \n 5. To Display top 5 scores\n 6. exit\n";
     cin>>c;
     
     switch(c)
     {
         
      case 1:
      s1.read_arr();
      break;
      
      case 2:
      s1.bubble_sort();
      break;
     
      case 3:
      s1.sel_sort();
      break;
     
      case 4:
      s1.insertion_sort();
      break;
    
      case 5:
      s1.display_scores();
      break;
    
      case 6:
      exit(0);
      
      default:
      cout<<"\nPlease enter a value between 1 to 6\n";
          
    }
   }
    
  return 0;
}
 

        
    
    

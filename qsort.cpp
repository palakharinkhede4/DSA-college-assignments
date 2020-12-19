#include<iostream>
using namespace std;
#define MAX 10

class qsort
{
private:
  int l,r,mid,lsort,rsort;
  
  float pivot,A[MAX]; 
  
public:
  
  
  void setdata(int size)
  {
    
    cout<<"\nEnter the elements you want to sort\n";
    
    for(int i=0;i<size;i++)
    {
      cin>>A[i];
    }
      
  }//setdata 
   
   
   void display_data(int size)
  {
  
    for(int i=0;i<size;i++)
    {
      cout<<A[i]<<"\n";
    }
      
  }//display_data
  
  void median(int l,int r)
  {
    
    mid=(l+r)/2;
    if(A[l]>A[mid])
    {
      float temp;
      temp=A[l];
      A[l]=A[mid];
      A[mid]=temp;
      
    }
    if(A[l]>A[r])
    {
      float temp;
      temp=A[l];
      A[l]=A[r];
      A[r]=temp;
      
    }
    if(A[mid]>A[r])
    {
      float temp;
      temp=A[mid];
      A[mid]=A[r];
      A[r]=temp;
      
    }
    float temp;
    
    temp=A[l];
    A[l]=A[mid];
    A[mid]=temp;
    
    
  }//median 
  
  int Quicksort(int l,int r)
  {
    median(l,r);
    
      pivot=A[l];
      lsort=l+1;
      rsort=r;
      
      while(lsort<rsort)
      {
	while(A[lsort]<=pivot)
	{
	  lsort++;
	}
	
	while(A[rsort]>pivot)
	{
	  rsort--;
	}
	
	if(lsort<rsort)
	{
	  float temp;
	  temp=A[lsort];
	  A[lsort]=A[rsort];
	  A[rsort]=temp;
	  
	}
	 A[l]=A[lsort-1];
	 A[lsort-1]=pivot;
	 
	 
	 if(l<rsort)
	 {
	   Quicksort(l,rsort-1);  //recursion
	 }
	 
	 if(lsort<r)
	 {
	   Quicksort(lsort,r);  //recursion
	 }
	 
      }//while
      
    }//Quicksort
  
  
  
  
  
  
  
};
    int main()
    {
      
      qsort q1;
      int size;
      
      cout<<"\nEnter the size of the array\n";
      cin>>size;
    
      
      q1.setdata(size);
      
      cout<<"\nElements are\n";
      
      q1.display_data(size);
      
       q1.Quicksort(0,size-1);
       cout<<"\n-----------------------------\n";
       cout<<"elements in sorted order are:"<<endl;
     q1.display_data(size);
      return 0;
    }
    

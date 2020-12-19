#include<iostream>
#include<stdlib.h>
using namespace std;
class matrix
{
private:
    int A[10][10],B[10][10],C[20][20];
    int Ra,Ca,Rb,Cb;
public:
    void details_matrix()
    {
        cout<<"\n number of rows in matrix A\n";
        cin>>Ra;
        cout<<"\n number of columns in matrix A\n";
        cin>>Ca;
        cout<<"\n number of rows in matrix B\n";
        cin>>Rb;
        cout<<"\n number of columns in matrix B\n";
        cin>>Cb;
    }
    void read_matrix(int k[10][10],int r,int c)
    {
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cin>>k[i][j];
            }
        }
    }
    void display_matrix( int k[10][10],int r,int c)
    {
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cout<<k[i][j]<<"\t";
            }
            cout<<"\n";
        }
    }
    void read_function()
    {
        cout<< "\n enter the elements of matrix A\n";
        read_matrix(A,Ra,Ca);
        cout<<"\n enter the elements of matrix B\n";
        read_matrix(B,Rb,Cb);
    }
     void display_function()
    {
        cout<< "\n elements of matrix A\n";
        display_matrix(A,Ra,Ca);
        cout<<"\n  elements of matrix B\n";
        display_matrix(B,Rb,Cb);
    }
    void addition()
    {
        int i;
        if(Ra==Rb&&Ca==Cb)
        {
            for(i=0;i<Ra;i++)
            {
                for(int j=0;j<Ca;j++)
                {
                    C[i][j]=A[i][j]+B[i][j];
                }
            }
            if(i==Ra)
            {
                cout<<"\n additon of matrices is\n";
                 for(int k=0;k<Ra;k++)
                    {
                        for(int j=0;j<Ca;j++)
                        {
                            cout<<C[k][j]<<"\t";
                        }
                        cout<<"\n";
                    }
            }
        }
        else
        {
            cout<<"\n addition is not possible \n";
        }
    }
    void substraction()
    {
        int i;
        if(Ra==Rb&&Ca==Cb)
        {
            for(i=0;i<Ra;i++)
            {
                for(int j=0;j<Ca;j++)
                {
                    C[i][j]=A[i][j]-B[i][j];
                }
            }
            if(i==Ra)
            {
                cout<<"\n substraction of matrices is\n";
                 for(int k=0;k<Ra;k++)
                    {
                        for(int j=0;j<Ca;j++)
                        {
                            cout<<C[k][j]<<"\t";
                        }
                        cout<<"\n";
                    }
            }
        }
        else
        {
            cout<<"\nsubstraction is not possible\n";
        }
    }
    void multiplication()
    {
        int i;

        if (Ca==Rb)
        {
            for( i=0;i<Ra;i++)
            {
                for(int j=0;j<Cb;j++)
                {
                     C[i][j]=0;
                    for(int k=0;k<Rb;k++)
                    {
                       C[i][j]= C[i][j]+(A[i][k]*B[k][j]);
                    }
                }
           }
           if(i==Ra)
            {
                cout<<"\n multiplication of matrices is\n";
                 for(int k=0;k<Ra;k++)
                    {
                        for(int j=0;j<Cb;j++)
                        {
                            cout<<C[k][j]<<"\t";
                        }
                        cout<<"\n";
                    }

            }
        }
        else
            {
                cout<<"\nmultiplication is invalid\n";
            }

    }
    void principle_diagonal()
    {
        int i,j;
        int e;
        e=0;
	if(Ra==Ca)
	{
        for(i=0;i<Ra;i++)
        {
            for(j=0;j<Ca;j++)
            {
                if(i==j)
                {
                    e=e+A[i][j];
                }
            }
	    }
        if(i==Ra)
        {
            cout<<"\n summation of principle diagonal elements of A is \n";
            cout<<e;
        }
	}
    else
	{
	  cout<<"\ncan not find summation of principle dagonal elements \n";
	}
    }
    void upper_triangular()
    {
       int flag=0;
       for(int i=0;i<Ra;i++)
        {
            for(int j=0;j<Ca;j++)
            {
                if(i>j && A[i][j]!=0)
                {
                 flag=1;
                 break;
		        }
            }
        }
        if(flag==0)
        {
            cout<<"\n matrix is  an upper triangular\n";
        }
        else
	    {
	        cout<<"\n matrix is not an upper triangular\n";
	    }
    }
    void transpose()
    {
      for(int i=0;i<Ra;i++)
      {
	    for(int j=0;j<Ca;j++)
	    {
          C[j][i]=A[i][j];
        }
      }
      cout<<"\n transpose of matrices is\n";
      for(int i=0;i<Ca;i++)
      {
        for(int j=0;j<Ra;j++)
        {
          cout<<C[i][j]<<"\t";
        }
        cout<<"\n";
      }

    }
    void secondary_diagonal()
    {
      int i,j;
      int e;
      e=0;
      if(Ra==Ca)
      {
	    for(i=0;i<Ra;i++)
        {
            for(j=0;j<Ca;j++)
            {
                if((i+j)==Ra+1)
                {
                    e=e+A[i][j];
                }
            }
	    }
        if(i==Ra)
        {
          cout<<"\n summation of secondary diagonal elements of A is \n";
          cout<<e;
        }
      }
      else
      {
	    cout<<"\ncan not find summation of secondary dagonal elements \n";
      }
    }
    void lower_triangular()
    {
       int flag=0;
       for(int i=0;i<Rb;i++)
        {
            for(int j=0;j<Cb;j++)
            {
                if(i<j && B[i][j]!=0)
                {
                 flag=1;
		         break;
		        }
            }

        }
        if(flag==0)
        {
            cout<<"\n matrix is  a lower triangular\n";
        }
        else
	    {
	        cout<<"\n matrix is not a lower triangular\n";
	    }

    }
    int saddle_point()
    {
        int flag=0;
        int i,j;
        for ( i=0;i<Ra;i++)
        {
            int Min=A[i][0];
            int Ci=0;
            for( j=0;j<Ca;j++)
            {
                if(Min >A[i][j])
                {
                    Min=A[i][j];
                    Ci=j;
                }
            }
            for( j=0;j<Ra;j++)
            {
                if(Min<A[j][Ci])
                {
                    break;
                }
            }
            if(j==Ra)
            {
                cout<<"\nsaddle point found\n";
                cout<<"\n saddle point is at\n";
                cout<<i<<"th row"<<"\t"<<Ci<<"th column\n";
                cout<<"\nsaddle point is\n";
                cout<<A[i][Ci];
                flag=flag+1;
            }
        }
        if(i==Ra)
        {
            if(flag==0)
            {
                cout<<"\n saddle point not found\n";
            }
        }
        return flag;
    }
};
 int main()
 {
   int n;
   matrix s;
   s.details_matrix();
   s.read_function();
   s.display_function();
   while(1)
   {
     cout<<"\n Enter\n 1. To get addtion of two matrices\n 2. to get substraction of two matrices\n 3. To get multiplication of 2 matrices \n 4. Sum of principle diagonals of  matrix A \n 5. Sum of secondary diagonal\n 6.Transpose of  matrix A \n 7.Find whether matrix A is upper triangular or not \n 8.Find whether matrix B is lower triangular or not\n 9. for checking if saddle point is present in matrix A or not\n 10. exit\n";
     cin>>n;
     switch(n)
     {
       case 1:
	 s.addition();
	 break;
       case 2:
         s.substraction();
         break;
       case 3:
         s.multiplication();
         break;
       case 4:
         s.principle_diagonal();
         break;
       case 5:
         s.secondary_diagonal();
         break;
       case 6:
         s.transpose();
         break;
       case 7:
         s.upper_triangular();
         break;
       case 8:
         s.lower_triangular();
         break;
       case 9:
         s.saddle_point();
         break;
       case 10:
	     exit(0);
    }
  }
  return 0;
}


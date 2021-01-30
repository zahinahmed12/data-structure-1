#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

void print_array(int *a,int n)
{
      int i=0;
      cout<<"THE SORTED ARRAY :"<<endl;
      for(i=0;i<n;i++)
      {
           printf("%d ",a[i]);
      }
      printf("\n");
      printf("\n");
}

int* counting_sort(int a[],int n,int maxE)
{

      int copya[n];
      int *b;
      b=new int[n];
      int minE=0;
      for(int i=0;i<n;i++)
      {
          if(minE>a[i])
          {
              minE=a[i];
          }
      }
      if(minE<0)
      {
          for(int i=0;i<n;i++)
          {
              copya[i]=a[i]-minE;
          }
      }
      else
      {
          for(int i=0;i<n;i++)
          {
              copya[i]=a[i];
          }
      }

      int newmax=maxE-minE;


      int temp[newmax+1];
      for(int i=0;i<=newmax;i++)
       {
          temp[i]=0;
       }

      for(int i=0;i<n;i++)
       {
          temp[copya[i]]+=1;
           }

      for(int i=1;i<=newmax;i++)
      {
         temp[i]=temp[i]+temp[i-1];
      }

      for(int i=n-1;i>=0;i--)
      {
          b[temp[copya[i]]-1]=copya[i];
          temp[copya[i]]=temp[copya[i]]-1;
      }

      for(int i=0;i<n;i++)
      {
          b[i]=b[i]+minE;
      }
      return b;
}
int main()
{
    while(1){
    int n,k,m;
    cout<<"ENTER SIZE OF ARRAY: "<<endl;
    cin >>n;
    int a[n];
    cout<<"ENTER ELEMENTS OF ARRAY: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>k;
        a[i]=k;
        //b[i]=0;
    }
    m=-100000;
    for(int i=0;i<n;i++)
    {
        if(a[i]>m)
            m=a[i];
    }
    int *p= counting_sort(a,n,m);
    print_array(p,n);

    }
}

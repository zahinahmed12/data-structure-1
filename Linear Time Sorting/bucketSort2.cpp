#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void print_array(float *a, int n)
{
      int i=0;
      cout<<"THE SORTED ARRAY :"<<endl;
      for(int i=0;i<n;i++)
      {
           printf("%f ",a[i]);
      }
      printf("\n");
      printf("\n");

}

vector<float> bucketSort(vector <float> a)
{
    //int length=a.size();
    vector<float>m[5];
    vector<float>n;
    int l=a.size();

    for(int i=0;i<l;i++)
    {
        int idx=(int)5*a[i];
        m[idx].push_back(a[i]);
    }

    for(int i=0;i<5;i++)
    {
        sort(m[i].begin(),m[i].end());
    }

    for(int i=0;i<5;i++)
    {
        for(int j=0;j< m[i].size();j++ )
        {
            n.push_back(m[i][j]);
        }
    }

    return n;
}

float* MergeBuckets(float arr[],int n,float maxE)
{
    vector<float>pos;
    vector<float>neg;
    vector<float>pos1;
    vector<float>neg1;
    int c = 1;
    float *a;
    a = new float[1000];

    while(maxE>=1)
    {
        maxE=maxE/10;
        c*=10;
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=arr[i]/c;
        if(arr[i]<0)
        {
             neg.push_back(-arr[i]);
        }
        else
        {
             pos.push_back(arr[i]);
        }
    }

    pos1=bucketSort(pos);

    neg1=bucketSort(neg);

    int p=-1;

    for(int i=0;i<neg1.size();i++)
    {
        a[i]=(-1.0)*c*neg1[neg1.size()-i-1];
        p=i+1;
    }

    if(p==-1) p=0;
    for(int i=0; i<pos1.size(); i++)
    {
        a[p++]=(1.0)*c*pos1[i];
    }

    return a;
}

int main()
{
    while(1){
    int n;
    float x,maxE=0.000,minE=10000000.0;
    cout<<"ENTER SIZE OF ARRAY: "<<endl;
    cin>>n;
    float arr[n];
    cout<<"ENTER ELEMENTS OF ARRAY: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        arr[i]=x;
        if(arr[i]>maxE) maxE=arr[i];
        if(arr[i]<minE) minE=arr[i];
    }
    if(maxE<0) maxE=(-1.0)*maxE;
    if(minE<0) minE=(-1.0)*minE;
    maxE=max(maxE,minE);

    float *a =MergeBuckets(arr,n,maxE);

    print_array(a,n);
    }

}

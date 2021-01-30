#include<stdio.h>
#include<iostream>
#include<cstring>
#include<limits.h>

using namespace std;

int Matrix_Chain_Order(int p[],int n)
{
    int j,q;
    int m[n][n];
    for(int i=1;i<n;i++)
    {
        m[i][i]=0;
    }
    for(int l=2;l<n;l++)
    {
        for(int i=1;i<n-l+1;i++)
        {
            j=i+l-1;
            m[i][j]=INT_MAX;
            for(int k=i;k<=j-1;k++)
            {
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j])
                {
                    m[i][j]=q;
                }
            }
        }
    }
    return m[1][n-1];
}

int main()
{
    while(1)
    {
        int n;
        printf("ENTER NO OF ELEMENTS: ");
        scanf("%d",&n);
        int p[n];
        printf("ENTER THE ELEMENTS: ");
        for(int i=0;i<n;i++)
        {
            scanf("%d",&p[i]);
        }
        printf("MINIMUM NO OF MULTIPLICATIONS: %d",Matrix_Chain_Order(p,n));
        printf("\n\n");
    }


}

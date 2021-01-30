#include<iostream>
#include<cstring>
#include<cstdio>
#include<stdio.h>

using namespace std;

void LCS_LENGTH(char s1[],char s2[],int m,int n,char b[][1001])
{
    char c[1001][1001];

    for(int i=0;i<=m;i++)
    {
        c[i][0]=0;
    }
    for(int j=0;j<=n;j++)
    {
        c[0][j]=0;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]='#';
            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                b[i][j]='|';
            }
            else
            {
                c[i][j]=c[i][j-1];
                b[i][j]='-';
            }
        }
    }
}

void PRINT_LCS(char s1[],int m,int n,char b[][1001])
{
    if(m==0 || n==0)
    {
        return;
    }
    if(b[m][n]=='#')
    {
        PRINT_LCS(s1,m-1,n-1,b);
        printf("% c",s1[m-1]);
    }
    else if(b[m][n]=='|')
    {
        PRINT_LCS(s1,m-1,n,b);
    }
    else PRINT_LCS(s1,m,n-1,b);
}

int main()
{
    while(1)
    {
        char str1[1000],str2[1000];
        char b[1001][1001];
        cout << "ENTER THE FIRST STRING : "<<endl;
        gets(str1) ;
        cout << "ENTER THE SECOND STRING : "<<endl;
        gets(str2);
        int m,n;
        m=strlen(str1);
        n=strlen(str2);
        LCS_LENGTH(str1,str2,m,n,b);
        printf("\nLCS for input sequences is ");
        PRINT_LCS(str1,m,n,b);
        printf("\n\n");
    }

}

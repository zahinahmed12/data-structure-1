#include<stdio.h>
#include<stdlib.h>

void auxFunc(int l[][2],int r[][2],int nl, int nr, int a[][2])
{
    int i,j,k;
    i=j=k=0;
    while(i<nl && j<nr)
    {
        if(l[i][0]<=r[j][0]){
            a[k][0]=l[i][0];
            a[k][1]=l[i][1];
            i++;
        }
        else{
            a[k][0]=r[j][0];
            a[k][1]=r[j][1];
            j++;
        }
        k++;
    }
    while(i<nl){
            a[k][0]=l[i][0];
            a[k][1]=l[i][1];
            i++;
            k++;
    }
    while(j<nr){
            a[k][0]=r[j][0];
            a[k][1]=r[j][1];
            j++;
            k++;
    }
}

void minimizeTime(int a[][2],int n)
{
    int i;
    if(n<2) return;
    int mid=n/2;
    int a1[mid][2], a2[n-mid][2];
    for(i=0;i<mid;i++)
    {
        a1[i][0]=a[i][0];
        a1[i][1]=a[i][1];
    }
    for(i=mid;i<n;i++)
    {
        a2[i-mid][0]=a[i][0];
        a2[i-mid][1]=a[i][1];
    }
    minimizeTime(a1, mid);
    minimizeTime(a2, n-mid);
    auxFunc(a1,a2,mid,n-mid,a);
}

int main()
{
    int n,i,j;
    printf("ENTER NO OF CUSTOMERS: ");
    scanf("%d",&n);
    int a[n][2];
    for(i=0;i<n;i++)
    {
        printf("\nENTER Waiting time %d): ",i+1);
        scanf("%d",&a[i][0]);
        a[i][1]=i+1;
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("%d) %d  ",a[i][1],a[i][0]);
    }
    printf("\n\n");
    minimizeTime(a,n);
    printf("THE ORDER IN WHICH CUSTOMERS SHOULD BE SERVICED: \n\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i][1]);
    }
    printf("\n");

}

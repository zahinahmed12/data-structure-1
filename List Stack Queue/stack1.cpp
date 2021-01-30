#include<stdio.h>
#include<stdlib.h>
#include "liststack.cpp"


#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

class Stack
{
    LinkedList ll,l;
public:
    Stack()
    {

    }
    void push(int item)
    {
        //write your codes here
        //ll.insertLast(item);
        l.insertItem(item);
    }
    int pop()
    {
        //write your codes here
        if(l.getLength()==0)
        {
            printf("THE LIST IS EMPTY\n");
            return NULL_VALUE;
        }
        ListNode * temp=l.getItemAt(1);
        int n=temp->item;
        l.deleteFirst();
        return n;

    }
};

int main(void)
{
    Stack st;

    while(1)
    {
        printf("1. Push. 2. Pop. 3. Exit. \n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            st.push(item);
        }
        else if(ch==2)
        {
            int item=st.pop();
            printf("%d\n",item);
        }
        else if(ch==3)
        {
            break;
        }
    }

}

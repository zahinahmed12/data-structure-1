#include<stdio.h>
#include<stdlib.h>


#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

class ListNode
{
public:
    int item;
    ListNode * next;
};

class LinkedListWithTail
{

    ListNode * list;
    ListNode * tail;
    int length;

public:
    LinkedListWithTail()
    {
        list = 0;  //initially set to NULL
        tail = 0;
        length=0;
    }

    int getLength()
    {
        return length;
    }

    //add required codes to set up tail pointer
    int insertItem(int item) //insert at the beginning
    {
        ListNode * newNode ;
        newNode = new ListNode() ;

        if(list==0) //inserting the first item
        {
            newNode->next = 0;
            list = newNode;
            tail = newNode;
        }
        else
        {
            //tail=list;
            newNode->next = list;
            //list->prev = newNode;
            list = newNode;
            //tail = newNode;

        }
        newNode->item = item ;
        //newNode->next = list ; //point to previous first node
        //list = newNode ; //set list to point to newnode as this is now the first node
        length++;

        return SUCCESS_VALUE ;
    }

    //add required codes to set up tail pointer
    int deleteItem(int item)
    {
        ListNode *temp, *prev ;
        temp = list ; //start at the beginning
        tail=list;
        while (temp != 0)
        {
            if (temp->item == item) break ;
            prev = temp;
            temp = temp->next ; //move to next node
        }
        if (temp == 0) return NULL_VALUE ; //item not found to delete
        if (temp == list) //delete the first node
        {
            tail=list->next;
            list = list->next ;
            delete temp ;
            length--;
        }
        else
        {
            prev->next = temp->next ;
            delete temp;
            length--;
        }
        return SUCCESS_VALUE ;
    }

    //add required codes to set up tail pointer
    ListNode * searchItem(int item)
    {
        ListNode * temp ;
        temp = list ; //start at the beginning
        tail=list;
        while (temp != 0)
        {
            if (temp->item == item) return temp ;
            temp = temp->next ; //move to next node
        }
        return 0 ; //0 means invalid pointer in C, also called NULL value in C
    }

    void printList()
    {
        ListNode * temp;
        temp = list;
        while(temp!=0)
        {
            printf("%d->", temp->item);
            temp = temp->next;
        }
        printf("\n");
        printf("Length: %d\n",getLength());
    }

    //------------write code for the functions below-----------
    int insertLast(int item)
    {
        //write your codes here
        ListNode * newNode = new ListNode() ;
        //ListNode *temp;
        if(list==NULL)
        {
        tail=list;
        list=newNode;
        tail=newNode;
        }
        else
        {
             tail->next=newNode;
             tail=newNode;
        }
        newNode->item=item;
        newNode->next=NULL;
        length++;


        return SUCCESS_VALUE;
    }

    ListNode * getItemAt(int pos)
    {
         //write your codes here
         if(pos>length)
         {
             return 0;
         }
         ListNode * temp;
         temp = list;
         int c=0;

         while(temp!=NULL){
         c++;
         if(c==pos)
         {
             return temp;
         }
         temp=temp->next;
    }

    }

    int deleteLast()
    {
        //write your codes here
        if(length==0)
        {
            printf("THE LIST IS EMPTY NOW\n");
            return NULL_VALUE;
        }
        if(length==1)
        {
            list=0;
            tail=0;
            length--;
            return SUCCESS_VALUE;
        }
        ListNode *prev;
        prev=list;

        while(prev->next!=tail){
        prev=prev->next;
    }
    tail=prev;
    tail->next=NULL;
    length--;
    return SUCCESS_VALUE;

    }
};

/*int main(void)
{
    LinkedListWithTail ll;

    while(1)
    {
        printf("1. Insert new item. 2. Delete item. 3. Search item. \n");
        printf("4. Insert Last. 5. Print. 6. exit. 7. DeleteLast\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            ll.insertItem(item);
        }
        else if(ch==2)
        {
            int item;
            scanf("%d", &item);
            ll.deleteItem(item);
        }
        else if(ch==3)
        {
            int item;
            scanf("%d", &item);
            ListNode * res = ll.searchItem(item);
            if(res!=0) printf("Found.\n");
            else printf("Not found.\n");
        }
        else if(ch==4)
        {
            int item;
            scanf("%d", &item);
            ll.insertLast(item);
        }
        else if(ch==5)
        {
            ll.printList();
        }
        else if(ch==6)
        {
            break;
        }
        else if(ch==7)
        {
            ll.deleteLast();
        }
    }

}*/


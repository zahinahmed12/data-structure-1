#include<stdio.h>
#include<stdlib.h>
#include<iostream>


#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

class ListNode
{
public:
    int item;
    ListNode * next;
};

class LinkedList
{

    ListNode * list;
    int length;

public:
    LinkedList()
    {
        list=0; //initially set to NULL
        length=0;
    }

    int getLength()
    {
        return length;
    }

    int insertItem(int item) //insert at the beginning
    {
        ListNode * newNode = new ListNode() ;
        newNode->item = item ;
        newNode->next = list ; //point to previous first node
        list = newNode ; //set list to point to newnode as this is now the first node
        length++;
        return SUCCESS_VALUE ;
    }

    int deleteItem(int item)
    {
        ListNode *temp, *prev ;
        temp = list ; //start at the beginning
        while (temp != 0)
        {
            if (temp->item == item) break ;
            prev = temp;
            temp = temp->next ; //move to next node
        }
        if (temp == 0) return NULL_VALUE ; //item not found to delete
        if (temp == list) //delete the first node
        {
            list = list->next ;
            delete temp;
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


    ListNode * searchItem(int item)
    {
        ListNode * temp ;
        temp = list ; //start at the beginning
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
        printf("Length: %d\n",length);
    }

    //------------write code for the functions below-----------

    int insertLast(int item)
    {
        //write your codes here
        ListNode * newNode = new ListNode() ;
        ListNode* trav=list;
        ListNode* prev;

     while(trav!=NULL){
        prev=trav;
        trav=trav->next;
    }
    newNode->item=item;
    newNode->next=NULL;
    if(list== NULL) {
        list=newNode;
        length++;
        }   else{
            prev->next=newNode;
            length++;
        }

    }

    int insertAfter(int oldItem, int newItem)
    {
        //write your codes here
        if(searchItem(oldItem)==0)
        {
            printf("\nTHE OLD ITEM DOESN'T EXIST\n");
            return NULL_VALUE;
        }
        ListNode * newNode = new ListNode() ;
        ListNode* trav=list;

        while(trav!=searchItem(oldItem)){
        trav=trav->next;
        }
        newNode->item=newItem;
        newNode->next=trav->next;
        trav->next=newNode;

        length++;

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

    int deleteFirst()
    {
        //write your codes here
        if(length==0)
        {
            printf("THE LIST IS EMPTY NOW\n");
            return NULL_VALUE;
        }
        ListNode * temp;
        temp=list;
        list=temp->next;
        length--;

    }


    ~LinkedList()
    {
        //write your codes here
        ListNode * temp =list;
        while(temp!=0)
        {
            ListNode *trav=temp;
            delete trav;
            temp=temp->next;
            length--;
        }
        delete list;
        delete temp;
    }

};

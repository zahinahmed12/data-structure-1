#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LIST_INIT_SIZE 2
#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

int listMaxSize;
int * list;
int length;

void initializeList()
{
	listMaxSize = LIST_INIT_SIZE;
	list = (int*)malloc(sizeof(int)*listMaxSize) ;
	length = 0 ;
}

int searchItem(int item)
{
	int i = 0;
	for (i = 0; i < length; i++)
	{
		if( list[i] == item ) return i;
	}
	return NULL_VALUE;
}

int insertItem(int newitem)
{
	int * tempList ;
	if (length == listMaxSize)
	{
		//allocate new memory space for tempList
		listMaxSize = 2 * listMaxSize ;
		tempList = (int*) malloc (listMaxSize*sizeof(int)) ;
		int i;
        for( i = 0; i < length ; i++ )
        {
            tempList[i] = list[i] ; //copy all items from list to tempList
        }
        free(list) ; //free the memory allocated before
        list = tempList ; //make list to point to new memory
	}

	if(listMaxSize<LIST_INIT_SIZE)
    {
        initializeList();
    }

	list[length] = newitem ; //store new item
	length++ ;

	return SUCCESS_VALUE ;
}

void getLength()
 {
     /*int c=0,i;
     for(i=0;i<length;i++)
     {
        c++;
     }*/
     printf("\nTHE NUMBER OF ITEMS OF THE LIST: %d\n",length);
 }

int insertItemAt(int pos,int item)
{
    int * tempList ;
    if ( pos >= length ){

        printf("\nINSERT ITEM AT THOSE POSITION WHICH ARE LESS THAN CURRENT LENGTH (%d)\n",length);
        return NULL_VALUE;
    }

	if (length == listMaxSize)
	{
		listMaxSize = 2 * listMaxSize ;
		tempList = (int*) malloc (listMaxSize*sizeof(int)) ;
		int i;
        for( i = 0; i < length ; i++ )
        {
            tempList[i] = list[i] ; //copy all items from list to tempList
        }
        free(list) ; //free the memory allocated before
        list = tempList ; //make list to point to new memory
	}
	list[length]=list[pos];
	list[pos]=  item;
    length++;
	return SUCCESS_VALUE ;
}

int shrink()
{
    int * tempList ;

    if(listMaxSize == LIST_INIT_SIZE){
        //printf("THE LIST DOESN'T NEED TO SHRINK ITSELF!\n");
        return NULL_VALUE;
    }
    if(length== listMaxSize/2)
    {
        listMaxSize = listMaxSize/2 ;
		tempList = (int*) malloc (listMaxSize*sizeof(int)) ;
		int i;
        for( i = 0; i < listMaxSize ; i++ )
        {
            tempList[i] = list[i] ; //copy all items from list to tempList
        }
        free(list) ; //free the memory allocated before
        list = tempList ; //make list to point to new memory
	}
	return SUCCESS_VALUE;

}

int deleteItemAt(int position) //version 2, do not preserve order of items
{
	if ( position >= length ){
         printf("THE POSITION IS NOT VALID\n");
         return NULL_VALUE;
	}
	list[position] = list[length-1] ;
	length-- ;
	return SUCCESS_VALUE ;
}

int deleteItem(int item)
{
	int position;
	position = searchItem(item) ;
	if ( position == NULL_VALUE ){
         printf("THAT ITEM IS NOT PRESENT IN THE LIST\n");
         return NULL_VALUE;
	}
	deleteItemAt(position) ;
	return SUCCESS_VALUE ;
}

 void deleteLast()
 {
     if(length==0)
     {
         printf("\nTHE LIST IS EMPTY RIGHT NOW\n");
         //return NULL_VALUE;
         return;
     }
     length--;
     shrink();
 }

int Clear()
{

    length=0;
    listMaxSize=0;
    free(list);
    list=NULL;

    return SUCCESS_VALUE;
}

void deleteAll()
{
    if(length==0)
    {
        printf("\nTHE LIST IS EMPTY\n");
        return;
    }
    int * tempList;
    if(length> LIST_INIT_SIZE)
    {
        int i;
        tempList=list;
        listMaxSize=LIST_INIT_SIZE;
        //tempList = (int*) malloc (listMaxSize*sizeof(int)) ;
        for( i = 0; i < listMaxSize; i++ )
        {
            tempList[i] = list[i] ;
        }
    }
    while(length!=0)
    {
        length--;
    }

}

void printList()
{
    int i;
    for(i=0;i<length;i++)
        printf("%d ", list[i]);
    printf("\nCurrent size: %d, current length: %d\n\n", listMaxSize, length);
}

void postfix_exp(char s[])
{
    int i,a,b;
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]=='0') insertItem('0'-48);
        else if(s[i]=='1') insertItem('1'-48);
        else if(s[i]=='2') insertItem('2'-48);
        else if(s[i]=='3') insertItem('3'-48);
        else if(s[i]=='4') insertItem('4'-48);
        else if(s[i]=='5') insertItem('5'-48);
        else if(s[i]=='6') insertItem('6'-48);
        else if(s[i]=='7') insertItem('7'-48);
        else if(s[i]=='8') insertItem('8'-48);
        else if(s[i]=='9') insertItem('9'-48);
        else if(s[i]=='+')
        {
            a=list[length-2];
            b=list[length-1];
            deleteLast();
            deleteLast();
            insertItem(a+b);
        }
        else if(s[i]=='-')
        {
            a=list[length-2];
            b=list[length-1];
            deleteLast();
            deleteLast();
            insertItem(a-b);
        }
        else if(s[i]=='*')
        {
           a=list[length-2];
            b=list[length-1];
            deleteLast();
            deleteLast();
            insertItem(a*b);
        }
        else if(s[i]=='/')
        {
            a=list[length-2];
            b=list[length-1];
            deleteLast();
            deleteLast();
             if(b==0)
            {
                printf("Invalid Expression\n");
                break;
            }
            insertItem(a/b);
        }
    }
    printf("\nTHE TOTAL OUTPUT = ");
    //printf("%d",list[0]);
    //deleteLast();
    printList();
    Clear();
    printf("\nAFTER REMOVING THE OUTPUT FROM THE LIST AND CLEARING THE LIST,\n");
    printf("\nCURRENT SIZE %d, CURRENT LENGTH %d\n",listMaxSize,length);

}
//this main function is for task 7- 'postfix expression'
/*int main(void)
{
    initializeList();
    char s[100];
    int i,a,b;
    printf("ENTER THE POSTFIX EXPRESSION: ");
    scanf("%s",&s);

    for(i=0;i<strlen(s);i++)
    {
        if(s[i]=='0') insertItem('0'-48);
        else if(s[i]=='1') insertItem('1'-48);
        else if(s[i]=='2') insertItem('2'-48);
        else if(s[i]=='3') insertItem('3'-48);
        else if(s[i]=='4') insertItem('4'-48);
        else if(s[i]=='5') insertItem('5'-48);
        else if(s[i]=='6') insertItem('6'-48);
        else if(s[i]=='7') insertItem('7'-48);
        else if(s[i]=='8') insertItem('8'-48);
        else if(s[i]=='9') insertItem('9'-48);
        else if(s[i]=='+')
        {
            a=list[length-2];
            b=list[length-1];
            deleteLast();
            deleteLast();
            insertItem(a+b);
        }
        else if(s[i]=='-')
        {
            a=list[length-2];
            b=list[length-1];
            deleteLast();
            deleteLast();
            insertItem(a-b);
        }
        else if(s[i]=='*')
        {
           a=list[length-2];
            b=list[length-1];
            deleteLast();
            deleteLast();
            insertItem(a*b);
        }
        else if(s[i]=='/')
        {
            a=list[length-2];
            b=list[length-1];
            deleteLast();
            deleteLast();
             if(b==0)
            {
                printf("Invalid Expression\n");
                break;
            }
            insertItem(a/b);
        }
    }
    printf("\nTHE TOTAL OUTPUT = ");
    //printf("%d",list[0]);
    //deleteLast();
    printList();
    Clear();
    printf("\nAFTER REMOVING THE OUTPUT FROM THE LIST AND CLEARING THE LIST,\n");
    printf("\nCURRENT SIZE %d, CURRENT LENGTH %d\n",listMaxSize,length);

}*/
int main(void)
{
    initializeList();
    char s[100];
    int a;
    while(1)
    {
       printf("ENTER THE POSTFIX EXPRESSION: ");
       scanf("%s",&s);
       postfix_exp(s);
       printf("\nENTER 0 TO EXIT ; ");
       printf("ENTER 1 TO CONTINUE\n");
       scanf("%d",&a);
       if(a==0) break;
       //else if(a==1) continue;
    }


}

/*int main(void)
{
    initializeList();
    while(1)
    {
        printf("\n\n1. Insert new item. 2. Delete item at. 3. Delete item.\n");
        printf("4. Delete Last Item . 5. Insert Item at. 6. Delete All Item.\n");
        printf("7. Clear List. 8. Print. 9. exit.\n\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            printf("ENTER THE ITEM:");
            scanf("%d", &item);
            insertItem(item);
            printf("SUCCESSFULLY INSERTED THAT ITEM!!\n");
        }
        else if(ch==2)
        {
            int pos;
            printf("ENTER THE POSITION:");
            scanf("%d", &pos);
            deleteItemAt(pos);
            printf("DELETED THE ITEM AT POSITION %d (ONLY IF THE POSITION IS VALID)\n",pos);
        }
        else if(ch==3)
        {
            int item;
            printf("ENTER THE ITEM:");
            scanf("%d", &item);
            deleteItem(item);
            printf("DELETED THE ITEM %d FROM THE LIST(ONLY IF THE ITEM WAS PRESENT IN THE LIST)\n",item);
        }
        else if(ch==4)
        {
            deleteLast();
            printf("THE LAST ITEM HAS BEEN DELETED FROM THE LIST(IF ONLY THE LIST WASN'T EMPTY)\n");
        }
        else if(ch==5)
        {
            int item,pos;
            printf("ENTER THE ITEM:");
            scanf("%d", &item);
            printf("ENTER THE POSITION:");
            scanf("%d", &pos);
            insertItemAt(pos,item);
            printf("SUCCESSFULLY INSERTED THAT ITEM AT POSITION %d (ONLY IF THE POSITION IS VALID)\n",pos);
        }
        else if(ch==6)
        {
            printf("THE CURRENT ADDRESS OF THE LIST %d\n",list);
            deleteAll();
            printf("EVERY SINGLE ITEM HAS BEEN DELETED FROM THE LIST!!\n");
            printf("THE SAME ADDRESS OF THE LIST AFTER DELETION %d\n",list);
        }
        else if(ch==7)
        {
            printf("THE CURRENT ADDRESS OF THE LIST %d\n",list);
            Clear();
            printf("THE LIST HAS BEEN CLEARED AND THE PREVIOUS MEMORY HAS BEEN DE-ALLOCATED\n");
            printf("THE NEW ADDRESS OF THE LIST AFTER CLEARING ALL ITEMS %d\n",list);
        }
        else if(ch==8)
        {
            printf("THE LIST IS BEING PRINTED SEQUENTIALLY\n");
            printList();
        }
        else if(ch==9)
        {
            printf("WE EXIT NOW!");
            break;
        }
    }

}*/


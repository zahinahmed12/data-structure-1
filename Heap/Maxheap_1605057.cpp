#include<iostream>
#include<climits>
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

class MaxHeap
{
    int *arr;
    int capacity;
    int heap_size;

    int parent(int i) { return (i-1)/2; }

    int left(int i) { return (2*i + 1); }

    int right(int i) { return (2*i + 2); }

public:

    MaxHeap(int capacity);

    void MaxHeapify(int );

    void set_heap_size(int n) { heap_size = n;}

    int extractMax();

    void increaseKey(int i, int new_val);

    int find_Max() { return arr[0]; }

    //void deleteKey(int i);

    void insertKey(int k);

    void build_maxheap(int n)
    {
        for(int i=(n/2) -1; i>=0; i--)
            MaxHeapify(i);
    }

    int heapsize()
    {
        return heap_size;
    }

    bool heap_is_empty()
    {
        return heapsize() == 0;
    }

    void siftup(int i)
    {
        /*if(i<heap_size && i>0 && arr[i]> arr[parent(i)])
        {
            swap(&arr[i], &arr[parent(i)]);
            siftup(parent(i));
        }*/
        while (i != 0 && arr[parent(i)] < arr[i])
        {
           swap(&arr[i], &arr[parent(i)]);
           i = parent(i);
        }
    }

    void siftdown(int i)
    {
       int largest = i;
       if (left(i) < heap_size && arr[largest] < arr[left(i)])
            largest = left(i);
       if (right(i) < heap_size && arr[largest] < arr[right(i)])
            largest = right(i);
       if (largest != i)
       {
           swap(&arr[i], &arr[largest]);
           siftdown(largest);
       }
    }

    void delete_max()
    {
        if (heap_size <= 0)
        return ;

    /*if (heap_size == 1)
    {
        heap_size--;
        return arr[0];
    }*/
        arr[0]=arr[heap_size-1];
        heap_size--;
        siftdown(0);
    }

    void Replace(int val)
    {
        arr[0] = val;
        siftdown(0);
    }

    void create_heap(int cap)
    {
       heap_size = 0;
       capacity = cap;
       arr = new int[cap];
    }

    void deleteKey(int i)
    {
        if (heap_size <= 0)
           return ;
        /*if (heap_size == 1)
        {
           heap_size--;
           return ;
        }*/
        if(i>=heap_size)
        {
            cout <<"ERROR"<<endl;
            return;
        }
        arr[i] = arr[heap_size-1];
        heap_size--;
        siftdown(i);
    }

    void decreaseKey(int i, int key)
    {
        if(i>=heap_size)
        {
            cout <<"ERROR"<<endl;
            return;
        }
        if(key > arr[i]){
            printf("new key is greater than current key\n");
            return;
        }
        arr[i] = key;
        siftdown(i);
    }

 void Merge(MaxHeap &heap1, MaxHeap &heap2)
{
        MaxHeap u(1000);
        int heap_size1 = heap1.heapsize();
        int heap_size2 = heap2.heapsize();
        int n = heap_size1 + heap_size2;

        u.set_heap_size(n);

        for(int i=0; i<heap_size1; i++)
            u.arr[i] = heap1.arr[i];

        for(int i=0; i<heap_size2; i++)
            u.arr[heap_size1 + i] =heap2.arr[i];

        u.build_maxheap(n);

        for(int i=0;i<n;i++)
        {
            printf("%d ",u.arr[i]);
        }
        //return u;
}

 void Meld(MaxHeap &heap1, MaxHeap &heap2)
{
        MaxHeap u(1000);
        int heap_size1 = heap1.heapsize();
        int heap_size2 = heap2.heapsize();
        int n = heap_size1 + heap_size2;

        u.set_heap_size(n);

        for(int i=0; i<heap_size1; i++)
            u.arr[i] = heap1.arr[i];

        delete (&heap1);

        for(int i=0; i<heap_size2; i++)
            u.arr[heap_size1 + i] =heap2.arr[i];

        delete(&heap2);

        u.build_maxheap(n);

        for(int i=0;i<n;i++)
        {
            printf("%d ",u.arr[i]);
        }
}

void print()
    {
        cout << "THE CURRENT SIZE OF HEAP: "<<this->heap_size << endl;
        for(int i = 0; i < this->heap_size; i++)
            cout<<this->arr[i]<<"->";
        printf("\n");
    }

    ~MaxHeap()
    {
        heap_size = 0;
        capacity = 0;
        delete[] arr;
    }

};

MaxHeap::MaxHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    arr = new int[cap];
}

void MaxHeap::insertKey(int k)
{
    if (heap_size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    /*heap_size++;
    int i = heap_size - 1;
    harr[i] = k;

    while (i != 0 && harr[parent(i)] > harr[i])
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }*/
        heap_size++;
        arr[heap_size -1] = INT_MIN;
        increaseKey(heap_size -1, k);
}

void MaxHeap::increaseKey(int i, int new_val)
{
    if(i>=heap_size)
        {
            cout <<"ERROR"<<endl;
            return;
        }
    if(new_val<arr[i])
    {
        cout<< "ERROR" << endl;
        return;
    }
    arr[i] = new_val;
    while (i != 0 && arr[parent(i)] < arr[i])
    {
       swap(&arr[i], &arr[parent(i)]);
       i = parent(i);
    }
}

int MaxHeap::extractMax()
{
    if (heap_size <= 0)
        return INT_MIN;
    if (heap_size == 1)
    {
        heap_size--;
        return arr[0];
    }
    int root = arr[0];
    arr[0] = arr[heap_size-1];
    heap_size--;
    MaxHeapify(0);

    return root;
}

void MaxHeap::MaxHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int largest = i;
    if (l <= heap_size && arr[l] > arr[i])
        largest = l;
    else largest=i;
    if (r <= heap_size && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        MaxHeapify(largest);
    }
}

int main()
{
    MaxHeap h(50);

    while(1)
    {
        printf("1.Insert.  2. Find-max. 3. Extract-max.\n");
        printf("4. Delete-max. 5. replace. 6. Create-heap.\n");
        printf("8. Merge. 9. Meld. 10. Size. 11. Is-empty.\n");
        printf("12. Increase-key. 13. Decrease-key. 14.Delete\n");
        printf("15. Sift-up. 16. Sift-down. 17.Print. 18. exit.\n");

        int ch;
        scanf("%d",&ch);

        if(ch==1)
        {
            int k;
            cin>>k;
            h.insertKey(k);
        }
        else if(ch==2)
        {
            cout<<"Root is "<<h.find_Max()<<endl;
        }
        else if(ch==3)
        {
            h.extractMax();
            cout<<"AFTER  EXTRACTING THE MAX ELEMENT :"<<endl;
            h.print();
        }
        else if(ch==4)
        {
            h.delete_max();
            cout<<"AFTER DELETION OF THE MAX ELEMENT :"<<endl;
            h.print();
        }

        else if(ch==5)
        {
            int n;
            cout<<"ENTER THE ELEMENT :"<<endl;
            cin>>n;
            h.Replace(n);
        }
        else if(ch==6)
        {
            h.create_heap(100);
            cout <<"HEAP CREATED"<<endl;
        }
        /*else if(ch==7)
        {
            h.MaxHeapify();
        }*/
        else if(ch==8)
        {
            MaxHeap h2(50),h1(50),h(50);
            int n,m;
            cout <<"ENTER NO OF NODES OF 1ST HEAP ";
            cin >>n;
            cout <<"ENTER NO OF NODES OF 2ND HEAP ";
            cin >>m;
            int a[n],b[m];
            cout<< "ENTER THE NODES FOR 1ST HEAP:";
            for(int i =0 ; i < n; i++)
            {
                cin>>a[i];
                h1.insertKey(a[i]);
            }
            cout<< "ENTER THE NODES FOR 2ND HEAP:";
            for(int i =0 ; i < m; i++)
            {
                cin>>b[i];
                h2.insertKey(b[i]);
            }

            h.Merge(h1,h2);
        }
        else if(ch==9)
        {
            MaxHeap h2(50),h1(50),h(50);
            int n,m;
            cout <<"ENTER NO OF NODES OF 1ST HEAP ";
            cin >>n;
            cout <<"ENTER NO OF NODES OF 2ND HEAP ";
            cin >>m;
            int a[n],b[m];
            cout<< "ENTER THE NODES FOR 1ST HEAP:";
            for(int i =0 ; i < n; i++)
            {
                cin>>a[i];
                h1.insertKey(a[i]);
            }
            cout<< "ENTER THE NODES FOR 2ND HEAP:";
            for(int i =0 ; i < m; i++)
            {
                cin>>b[i];
                h2.insertKey(b[i]);
            }

            h.Meld(h1,h2);
        }
        else if(ch==10)
        {
            cout<<"THE CURRENT SIZE OF HEAP "<<h.heapsize()<<endl;
        }
        else if(ch==11)
        {
            if(h.heap_is_empty() == true)
                cout<<"The heap is empty"<<endl;
            else
                cout<<"The heap is not empty"<<endl;
        }
        else if(ch==12)
        {
            int k,e;
            cout<<"ENTER THE KEY: ";
            cin>>k;
            cout<<"ENTER THE ELEMENT: ";
            cin>>e;
            h.increaseKey(k,e);
            cout<<"AFTER INCREASING : "<<endl;
            h.print();
        }
        else if(ch==13)
        {
            int k,e;
            cout<<"ENTER THE KEY: ";
            cin>>k;
            cout<<"ENTER THE ELEMENT: ";
            cin>>e;
            h.decreaseKey(k,e);
            cout<<"AFTER DECREASING : "<<endl;
            h.print();
        }
        else if(ch==14)
        {
            int key;
            cout<<"ENTER THE KEY YOU WANT TO DELETE: "<<endl;
            cin>>key;
            h.deleteKey(key);
            cout<<"AFTER DELETION OF THE KEY :"<<endl;
            h.print();
        }
        else if(ch==15)
        {
            h.siftup(2);
        }
        else if(ch==16)
        {
            h.siftdown(2);
        }
        else if(ch==17)
        {
            h.print();
        }
        else if(ch==18)
        {
            break;
        }

    }
    return 0;
}

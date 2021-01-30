#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

class nodes
{
    char item;
    int freq;
public:
    nodes *left, *right;
    nodes(char ch,int f)
    {
        this->item=ch;
        this->freq=f;
        left=right=NULL;
    }
    char getItem()
    {
        return item;
    }
    int getFrequency()
    {
        return freq;
    }
    void setItem(char ch)
    {
        this->item=ch;
    }
    void setFrequency(int f)
    {
        this->freq=f;
    }

};

class utilize
{
    public:
    bool operator()(nodes *l, nodes *r)
    {
        return (l->getFrequency()> r->getFrequency());
    }
};

class Huffman
{
    priority_queue<nodes* ,vector<nodes*>, utilize> sortedQ;

    public:
    nodes *left, *right, *front;

    void Insert(char item, int freq)
    {
        sortedQ.push(new nodes(item,freq));
    }
    void huffmanCode()
    {
        while(sortedQ.size() !=1)
        {
            left=sortedQ.top();
            sortedQ.pop();

            right=sortedQ.top();
            sortedQ.pop();

            front=new nodes('&' , left->getFrequency()+right->getFrequency());

            front->left=left;
            front->right=right;

            sortedQ.push(front);
         }
         print(sortedQ.top(),"");
    }
    void print(nodes *n, string s)
    {
        if(!n) return;
        if(n->getItem()!= '&')
        {
            cout << n->getItem() << ": " << s << "\n";
        }
        print(n->left, s+"0");
        print(n->right, s+"1");
    }
};


int main()
{
    int N;
    char item;
    int freq;

    Huffman h;
    cout << "Enter no of characters: "<<endl;
    cin >> N;

    for(int i=0;i<N;i++)
    {
        cout << "Enter the character : "<<endl;
        cin >> item;
        cout << "Enter it's frequency :"<< endl;
        cin >> freq;
        h.Insert(item,freq);
    }
    h.huffmanCode();
}






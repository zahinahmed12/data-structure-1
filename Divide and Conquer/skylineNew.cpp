#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > Merge(vector<vector<int> > l,vector<vector<int> > r)
{
    vector<vector<int> > v;
    int i,j;
    i=j=0;
    while(i<l.size() && j<r.size())
    {
        if(l[i][0]==r[j][0])
        {
            if(l[i][1]<=r[j][1])
            {
                v.push_back(l[i]);
                i++;
            }
            else
            {
                v.push_back(r[j]);
                j++;
            }
        }
        else if(l[i][0]<r[j][0])
        {
            v.push_back(l[i]);
            i++;
        }
        else
        {
            v.push_back(r[j]);
            j++;
        }
    }
    while(i<l.size())
    {
            v.push_back(l[i]);
            i++;
    }
    while(j<r.size())
    {
            v.push_back(r[j]);
            j++;
    }
    return v;
}

vector<vector<int> > Merge2(vector<vector<int> > l,vector<vector<int> > r)
{
    vector<vector<int> > v;
    int i,j;
    i=j=0;
    while(i<l.size() && j<r.size())
    {
        if(l[i][1]<=r[j][1])
        {
            v.push_back(l[i]);
            i++;
        }
        else
        {
            v.push_back(r[j]);
            j++;
        }
    }
    while(i<l.size())
    {
            v.push_back(l[i]);
            i++;
    }
    while(j<r.size())
    {
            v.push_back(r[j]);
            j++;
    }
    return v;
}

void mergeSort(vector<vector<int> >& v)
{
    int i;
    if(v.size()<2) return;
    size_t const median = v.size() / 2;
    vector<vector<int> > left1(v.begin(), v.begin() + median);
    vector<vector<int> > right1(v.begin() + median, v.end());
    mergeSort(left1);
    mergeSort(right1);
    v = Merge(left1,right1);
}

vector<vector<int> > skyline(vector<vector<int> > v)
{
    if(v.size()<2) return v;
    size_t const median = v.size() / 2;
    vector<vector<int> > left1(v.begin(), v.begin() + median );
    vector<vector<int> > right1(v.begin() + median, v.end());

    left1 = skyline(left1);
    int lowest = left1[0][1];
    /*for(int i = 0; i< left1.size(); i++)
    {
        cout << left1[i][0] << " " << left1[i][1] << " | ";
    }
    cout<< endl;*/

    right1 = skyline(right1);

    /*for(int i = 0; i< right1.size(); i++)
    {
        cout << right1[i][0] << " " << right1[i][1] << " | ";
    }
    cout<< endl;*/


    for(int i=0; i<right1.size(); i++){
        if(right1[i][1] >= lowest){
             right1.erase(right1.begin()+i, right1.end());
             break;
        }
    }
    /*for(int i = 0; i< right1.size(); i++)
    {
        cout << right1[i][0] << " " << right1[i][1] << " | ";
    }
    cout<< endl;*/

    return Merge2(left1,right1);
}

int main()
{
    vector<vector<int> > v;

	int r,c=2;

	printf("ENTER NO OF POINTS: ");
	cin>>r;
	int mid=r/2;

	for(int i=0;i<r;i++){
		vector<int> vt;
		int temp;

        for(int i=0;i<c;i++){
            if(i==0) printf("ENTER DISTANCE: ");
            else if(i==1) printf("ENTER COST: ");
			cin>>temp;
			vt.push_back(temp);
		}
		v.push_back(vt);
	}
	mergeSort(v);
	cout << "\nSorted:" << endl;
	for(int i = 0; i< v.size(); i++)
    {
        cout << v[i][0] << " " << v[i][1] << " | ";
    }
    cout << endl;
    v = skyline(v);
    cout << "\nAns:" << endl;
	for(int i = 0; i< v.size(); i++)
    {
        cout << v[i][0] << " " << v[i][1] <<endl;
    }

    return 0;

}


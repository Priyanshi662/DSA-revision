//  T T T T T P T T P T T   P  T  T  T   T
//  0 1 2 3 4 5 6 7 8 9 10 11 12 13 14   15
//  k=2
// police -> {11}
// Thief -> {6 7 9 10 12 13 14 15}
/*
ans =2
8,6 
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
priority_queue<int> heap;
unordered_map<int,int> mp;
for(int i=0;i<arr.size();i++)
{
    mp[arr[i]]++;
    heap.push(arr[i]);
}
while(heap.empty())
{
    int a=heap.top();//8
    heap.pop();
    int b=heap.top();//4
    heap.pop();
    if(mp.find(a)==mp.end() && mp.find(b)==mp.end())
    {
        int c=b-a;//4
        heap.push(c);//4
        heap.push(b);//4
        heap.push(b);//4
    }
    else
    {
        break;
    }
}

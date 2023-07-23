#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int directed_weighted()
{
    unordered_map<int,vector<pair<int,int>>> mp;
    // u, [{v1,wt1},{v2,wt2}]
    cout<<"Enter the number of vertices : ";
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the number of vertices connecting with - "<<i<<endl;
        int m;
        cin>>m;
        cout<<"Enter the vertices and weights of "<<m<<" vertices"<<endl;
        vector<pair<int,int>> temp;
        for(int j=0;j<m;j++)
        {   
            int e,wt;
            cin>>e>>wt;
            temp.push_back(make_pair(e,wt));
        }
        mp[i]=temp;
    }
    return 0;
}
int directed_noWeight()
{
    unordered_map<int,vector<int>> mp;
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    int findPlatform(int arr[], int dep[], int n)
    {
    	vector<pair<int,int>> train;
    	for(int i=0;i<n;i++)
    	{
    	    train.push_back({arr[i],dep[i]});
    	}
    	sort(train.begin(),train.end());
        priority_queue<int,vector<int>,greater<int>> pq;
        // priority queue stores the lowest departure time for a platform queue
        for(int i=0;i<n;i++)
        {
            pq.push(train[i].second);
            if(pq.top()<train[i].first)
            {
                // add the train to the same platform and pop previous time of train
                pq.pop();
            }
        }
        return pq.size();
    }
};

int main()
{
    int n;
    cout<<"Enter the number of trains:";
    cin>>n;
    int arr[n];
    int dep[n];
    cout<<"Enter the arrival and departure time of trains:";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int j=0;j<n;j++){
        cin>>dep[j];
    }
    Solution ob;
    cout <<ob.findPlatform(arr, dep, n)<<endl;
}
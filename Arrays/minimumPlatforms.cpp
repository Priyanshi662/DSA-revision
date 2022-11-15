#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
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
            // we are checking for the next train departure time
            if(pq.top()<train[i].first)
            {
                // if the already scheduled train's departure time < current train arrival
                // add the train to the same platform and pop previous time of train
                pq.pop();
            }
        }
        return pq.size();
    }
};

int main()
{
    cout<<"Enter number of trains to be scheduled : ";
    int n;
    cin>>n;
    int arr[n];
    int dep[n];
    cout<<"Enter arrival time of each train : ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter departure time of each train : ";
    for(int j=0;j<n;j++){
        cin>>dep[j];
    }
    Solution ob;
    cout <<ob.findPlatform(arr, dep, n)<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int kthLargest(vector<int> &arr,int n,int k){
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++)
        {
            int sum=0;
            // Start the subarray from the current element
            for(int j=i;j<n;j++)
            {
                sum+=arr[j];
                pq.push(sum);
                // apply logic of kth largest element here :
                while(pq.size()>k)
                    pq.pop();
            }
        }
        return pq.top();
    }
};

int main(){
    int N,K;
    cout<<"Enter Values of N and K : ";
    cin>>N;
    cin>>K;
    vector<int> Arr(N);
    cout<<"Enter elements in the array : ";
    for(int i=0;i<N;i++){
        cin>>Arr[i];
    }
    Solution ob;
    int ans=ob.kthLargest(Arr,N,K);
    cout<<"The kth largest sum in the array of a subarray is : ";
    cout<<ans<<endl;
    return 0;
}
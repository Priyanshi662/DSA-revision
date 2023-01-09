#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    int row;
    int col;
    
    node(int d , int r , int c){
        data = d;
        row = r;
        col = c;
    }
};

class compare{
    public:
    bool operator()(node *a , node *b)    {
        return a->data > b->data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
    int mini = INT_MAX;
    int maxi = INT_MIN;
    int k = nums.size();
    // int n = nums[0].size();
    
    priority_queue<node*,vector<node*>,compare> pq;
    
    //step 1 : insert the first element of each list into min heap and update mini/maxi
    for(int i = 0 ; i < k ; i++) {
        int element = nums[i][0];
        mini = min(mini , element);
        maxi = max(maxi , element);
        node *temp = new node(element , i , 0);
        pq.push(temp);
    }
    
    int start = mini;
    int end = maxi;
    
    while(pq.size() > 0){
        node *temp = pq.top();
        pq.pop();
        
        mini = temp->data;
        
        if(maxi-mini < end-start){
            start = mini;
            end = maxi;
        }
        // if any list ends:
        if(temp->col + 1 >= nums[temp->row].size())
            break;
        else
        {
            maxi = max(maxi , nums[temp->row][temp->col+1]);
            pq.push(new node(nums[temp->row][temp->col+1] , temp->row , temp->col + 1));
        }
    }
        return {start,end};
    }
};
int main(){
    int k,n;
    cout<<"Enter value of K : ";
    cin>>k;
    cout<<"Enter value of N - size of each list : ";
    cin>>n;
    vector<vector<int>> nums(k,vector<int>(n,0));
    for(int i=0;i<k;i++)
    {
        cout<<"Enter elements of {"<<i+1<<"} list :";
        for(int j=0;j<n;j++)
        {
            cin>>nums[i][j];
        }
    }
    Solution ob;
    vector<int> res= ob.smallestRange(nums);
    cout<<"The smallest range is  : "<<res[0]<<"-"<<res[1];
    return 0;
}
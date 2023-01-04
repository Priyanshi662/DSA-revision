#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void heapify(vector<int> &nums,int i)
    {
        int left=2*i+1;
        int right=2*i+2;
        int largest=i;
        if(left>=nums.size())
            return ;
        largest=left;
        if(right<nums.size() && nums[right]>nums[largest])
            largest=right;
        if(nums[i]<nums[largest])
        {
            swap(nums[i],nums[largest]);
        }
        heapify(nums,largest);
    }
    void buildHeap(vector<int> &nums)
    {
        int heapsize=nums.size();
        for(int i=heapsize/2-1;i>=0;i--)
        {
            heapify(nums,i);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        buildHeap(nums);
        for(int i=0;i<k-1;i++)
        {
            int heapsize=nums.size();
            swap(nums[0],nums[heapsize-1]);
            nums.pop_back();
            heapify(nums,0);
        }
        return nums[0];
    }
};
int main()
{
    int n;
    cout<<"Enter number of elements: ";
    cin>> n;
    vector<int> v(n);
    cout<<"Enter value of elements: ";
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<"Enter value of K :";
    int k;
    cin>>k;
    Solution ob;
    cout<<"The result is: "<<ob.findKthLargest(v,k)<<endl;
    return 0;
}
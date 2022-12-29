#include<bits/stdc++.h>

using namespace std;
class Solution{
    public:
    long long trappingWater(int arr[], int n)
    {
        long long res=0;
        int left=0;
        int right=n-1;
        int mxleft=0;
        int mxright=0;
        while(left<=right)
        {
            if(arr[left]<=arr[right])
            {
                if(mxleft<=arr[left])
                    mxleft=arr[left];
                else
                    res+=(mxleft-arr[left]);
                left++;
            }
            else if(arr[right]<arr[left])
            {
                if(mxright<=arr[right])
                    mxright=arr[right];
                else
                    res+=(mxright-arr[right]);
                right--;
            }
        }
        return res;
    }
};
int main(){
    int n;
    cout<<"Enter the size of the array:";
    cin >> n;
    int a[n];
    cout<<"Enter the elements of the array:";
    for(int i =0;i<n;i++){
        cin >> a[i];            
    }
    Solution obj;
    cout<<"The maximum water that can be trapped is:";
    cout << obj.trappingWater(a, n) << endl;
    return 0;
}

// Brute force - find min(arr[left],arr[right])+res - TC : O(n^2)
// Better - Using prefix and suffix array - keep track of maximum from left and right respectively - SC- O(n) and TC: O(n)
// Optimal - Using two pointer approach - TC :O(n) and SC- O(1)
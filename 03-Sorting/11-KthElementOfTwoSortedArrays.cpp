#include <vector>
#include <algorithm>
using namespace std;

// brute force :
int kElement1(vector<int> &arr1,vector<int> &arr2,int n,int m,int k)
{
    vector<int> temp;
    for(int i=0;i<n;i++)
        temp.push_back(arr1[i]);
    for(int i=0;i<m;i++)
        temp.push_back(arr2[i]);
    sort(temp.begin(),temp.end());
    return temp[k-1];
}
// using merge function of merge sort:
int kElement2(vector<int> &arr1,vector<int> &arr2,int n,int m,int k)
{
    int l=0,r=0;
    int count=0;
    while(l<n && r<m)
    {
        if(arr1[l]<arr2[r] && count!=k)
        {
            l++;
            count++;
        }
        else if(arr2[l]>arr2[r]&&count!=k)
        {
            r++;
            count++;
        }
        if(count==k)
            return min(arr1[l],arr2[r]);
    }
    while(l<n)
    {
        l++;
        count++;
        if(count==k)
            return arr1[l];
    }
    while(r<m)
    {
        r++;
        count++;
        if(count==k)
            return arr2[r];
    }
    return -1;
}
 int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int low=min(arr1[0],arr2[0]);
        int high=max(arr1[n-1],arr2[m-1]);
        while(low<high)
        {
            int mid=low+(high-low)/2;
            int x=upper_bound(arr1,arr1+n,mid)-arr1;
            int y=upper_bound(arr2,arr2+m,mid)-arr2;
            if(x+y<k)
                low=mid+1;
            else
                high=mid;
        }
        return low;
    }
// using binary search :

class Solution {
  long kthElement( int arr1[], int arr2[], int n, int m, int k) {
    if(m < n ) return kthElement(arr2, arr1, m, n, k);
    // assuming m is always less than n
    int low = max(0, k-m), high = min(n,k);

    while(low <= high) {
      int cut1 = (low+high) / 2;
      int cut2 = k - cut1;

    //   System.out.println(cut1 + "  "+ cut2);
      int left1 = cut1 == 0 ? INT_MIN : arr1[cut1-1];
      int left2 = cut2 == 0 ? INT_MIN : arr2[cut2-1];

      int right1 = cut1 >= n ?INT_MAX : arr1[cut1];
      int right2 = cut2 >= m ?INT_MAX : arr2[cut2];

    // left subarray is less than right
      if(left1 <= right2 && left2 <= right1) {
        return max(left1, left2);
      }
      
      else if (left1 > right2) {
        high = cut1 - 1;
      }
      else {
        low = cut1 + 1;
      }
    }
    return 0;
  }
};

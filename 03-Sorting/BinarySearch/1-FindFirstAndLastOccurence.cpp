#include <vector>
#include <algorithm>
using namespace std;

// normal approach
vector<int> find(int arr[], int n , int x )
{
    // left binary search
    // right binary search
    int low=0;
    int high=n-1;
    int left=-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]==x)
        {
            left=mid;
            high=mid-1;
        }
        else if(arr[mid]>x)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    low=0;
    high=n-1;
    int right=-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]==x )
        {
            right=mid;
            low=mid+1;
        }
        else if(arr[mid]>x)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return {left,right};
}

// using STL binary_search -> UPPER_BOUND and LOWER_BOUND

vector<int> find(int arr[], int n , int x )
{
    int first = lower_bound(arr,arr+n,x)-arr;
    if(arr[first]!=x) //if element not found
        return {-1,-1};
    int last = upper_bound(arr,arr+n,x)-arr-1;
        return {first,last};
}
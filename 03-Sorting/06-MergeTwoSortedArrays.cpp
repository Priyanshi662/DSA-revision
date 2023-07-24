#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// brute force -> add elements of arr1 and arr2 to arr3 and sort the arr3
// Time complexity : O(nlogn)
// space complexity: O(n+m)
void merge1(int arr1[],int arr2[],int n,int m)
{
    int k=0;
    vector<int> res;
    for(int i=0;i<n;i++)
        res.push_back(arr1[i]);

    for(int j=0;j<m;j++)
        res.push_back(arr2[j]);

    sort(res.begin(),res.end());
}
// Better approach : using merge function of mergeSort -> 
// time complexity : O(n+m)
// space complexity: O(n+m)
void merge(int arr1[],int arr2[],int n,int m)
{
    int i=0,j=0,k=0;
    int arr3[n+m];
    while(i<n && j<m)
    {
        if(arr1[i]<arr2[j])
        {
            arr3[k++]=arr1[i++];
        }
        else if(arr1[i]>arr2[j])
        {
            arr3[k++]=arr2[j++];
        }
    }
    while(i<n)
        arr3[k++]=arr1[i++];
    while(j<m)
        arr3[k++]=arr2[j++];
}

// Optimal approach : without using extra space - using insertion sort
void merge(long long arr1[], long long arr2[], int n, int m) 
{
    int gap=ceil((float)(n+m)/2);
    while(gap>=1){
        int i=0;
        int j=gap;
        while(j<(n+m))
        {
            //there will be three cases
            //1.j is in 1st array,i is in 1st array and swap is required
            if(j<n && arr1[i]>arr1[j]){
                swap(arr1[i],arr1[j]);
            }
            //2.j is in 2nd array, i is in 1st array and swap is required
            else if(j>=n && i<n && arr1[i]>arr2[j-n])
            {
                swap(arr1[i],arr2[j-n]);
            }
            //3.j is in 2nd array, i is in 2nd array and swap is required
            else if(j>=n && i>=n &&arr2[i-n]>arr2[j-n])
            {
                swap(arr2[i-n],arr2[j-n]);
            }
            i++;
            j++;
        }
        if(gap==1)
        gap=0;
        else
        {
            gap=ceil((float)gap/2);
        }
    }     
} 
int main()
{
    int arr1[]={2,8,9,10};
    int n=4;
    int arr2[]={3,5,6,11,12};
    int m=5;
    merge1(arr1,arr2,n,m);
    for(int i=0;i<n;i++)
        cout<<arr1[i]<<" ";
    for(int i=0;i<m;i++)
        cout<<arr2[i]<<" ";
    return 0;
}
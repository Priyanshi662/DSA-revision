//https://www.geeksforgeeks.org/searching-array-adjacent-differ-k/
#include <iostream>
#include <vector>
using namespace std;

int search(int arr[], int n, int x, int k)
{
    int i=0;
    while(i<n)
    {
        if(arr[i]==x)
            return i;
        int diff=abs(arr[i]-x);
        // if possible jump to + (diff/k) th element
        i=max(1,diff/k);
    }
    return -1;
}
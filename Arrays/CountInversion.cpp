#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
 void merge(long long arr[], long long low, long long mid, long long right, long long &ctr){
        long long i= low, j=mid+1, k=low, temp[right];
        while(i<=mid && j<=right){
            if(arr[i]<=arr[j]){
                temp[k]=arr[i];
                i++;
                k++;
            }
            else{
                ctr = ctr+ (mid-i+1);
                temp[k]=arr[j];
                j++;
                k++;
            }
        }
        while(i<=mid){
            temp[k] = arr[i];
            i++;
            k++;
        }
        while(j<=right){
            temp[k] = arr[j];
            j++;
            k++;
        }
        for(int p=low; p<=right; p++){
            arr[p] = temp[p];
        }
        
    }
    
    void mergeSort(long long arr[], long long low, long long right, long long &ctr){
        if(low<right){
            long long mid = (low+right)/2;
            mergeSort(arr, low, mid, ctr);
            mergeSort(arr, mid+1, right, ctr);
            merge(arr, low, mid, right, ctr);
        }
    }
    
    
    
    long long int inversionCount(long long arr[], long long n)
    {
        long long ctr = 0;
        mergeSort(arr, 0, n-1, ctr);
        return ctr;
    }
};

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
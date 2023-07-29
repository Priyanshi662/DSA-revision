/*
For a given array of integers, determine the
maximum value in the segment from each index to
the highest index element, inclusive. 
After that has been determined, determine the number of times
that highest value occurs in the segment. 
A number of queries will then be given, where each query
represents an index within the array. Create a
return array with one value for each query: the
number of times the maximum value occurs in a
segment starting at that index.
Example :
numbers = [5, 4, 5, 3, 2]
q= [1, 2, 3, 4, 5]
Note: The numbers array indexes are from 1 to
n where n is the length of the array.
For the first query, the index is 1. The segment
starting at index 1 is [5, 4, 5, 3, 2]. The highest
value is 5, and it occurs 2 times. result = [2]
For the second query, the index is 2. The segment
starting at index 2 is [4, 5, 3, 2]. The highest value is
5, and it occurs 1 time. result = [2, 1]
In each of the remaining segments queried, [5, 3,
2], [3, 2], and [2], there is only one occurrence of a
highest value so a 1 is appended to result for each
query.
*/

// brute force would be to find max element and count it for every segment O(n^2) solution
// optimal will be to start traversing from last and maintain a count array
#include <vector>
using namespace std;
vector<int> findFreq(vector<int> arr,int n,vector<int> q)
{
    vector<int> cnt(n);
    int maxval=-1;
    int count=1;
    for(int i=n-1;i>=0;i--)
    {
        if(arr[i]==maxval)
            count++;
        else if(arr[i]>maxval)
        {
            maxval=arr[i];
            count=1;
        }
        cnt[i]=count;
    }
    vector<int> res;
    for(int i=0;i<q.size();i++)
    {
        int ele=q[i];
        int freq=cnt[ele-1];
        res.push_back(freq);
    }   
    return res;
}
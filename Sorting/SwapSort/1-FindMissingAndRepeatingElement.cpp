#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


// Using map :
// cons: uses extra space
vector<int> findUsingMap()
{
	int arr[] = { 4, 3, 6, 2, 1, 1 };
	int n = 6;
	int x,y;
	unordered_map<int, bool> numberMap;
	
	for(int i : arr)
	{
		if (numberMap.find(i) ==numberMap.end())
		{
			numberMap[i] = true;
		}
		else
		{
            // repeating
			x=i;
			break;
		}
	}
	cout << endl;
	
	for(int i = 1; i <= n; i++)
	{
		if (numberMap.find(i) ==numberMap.end())
		{
            // missing
			y=i;
			break;
		}
	}
	return {x,y};
}

// using mathematical equations:
// cons : does not scale well - it will become complex and might not work for more than 1 missing or repeating number
vector<int>repeatedNumber(const vector<int> &A) {
	long long int len = A.size();
	long long int Sum_N = (len * (len+1) ) /2, Sum_NSq = (len * (len +1) *(2*len +1) )/6;
	long long int missingNumber=0, repeating=0;
	
	for(int i=0;i<A.size(); i++){
	Sum_N -= (long long int)A[i];
	Sum_NSq -= (long long int)A[i]*(long long int)A[i];
	}
	
	missingNumber = (Sum_N + Sum_NSq/Sum_N)/2;
	repeating= missingNumber - Sum_N;
	vector <int> ans;
	ans.push_back(repeating);
	ans.push_back(missingNumber);
	return ans;
	
}

// Cons : if the array is immutable then we cannot apply swap sort
vector<int> findTwoElement(vector<int> arr, int n) {
        vector<int> res;
        int rep,mis;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==i+1)
                continue;
            else
            {
                while(arr[i]!=arr[arr[i]-1])
                    swap(arr[i],arr[arr[i]-1]);
                if(i!=arr[i]-1)
                {
                    rep=arr[i];
                    mis=i+1;
                }
            }
        }
        res.push_back(rep);
        res.push_back(mis);
        return res;
    }
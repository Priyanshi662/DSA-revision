#include <deque>
#include <vector>

using namespace std;

vector<int> findMax(vector<int> & arr,int k)
{
    // stores the indices of max elements in the window of size k
        deque<int> in;  
        for(int i=0;i<k;i++)
        {
            while(!in.empty() && arr[i]>=arr[in.back()])
            {
                in.pop_back();
            }
            in.push_back(i);
        }
        vector<int> res;
        for(int i=k;i<arr.size();i++)
        {
            res.push_back(arr[in.front()]);
            while(!in.empty() && in.front()<=(i-k))
                in.pop_front();
            while(!in.empty() && arr[i]>=arr[in.back()])
                in.pop_back();
            in.push_back(i);
        }
        res.push_back(arr[in.front()]);
        return res;
}
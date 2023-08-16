#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector <int> calculateSpan(int arr[], int n)
{
    vector<int> ans(n,1);
    for(int i=0;i<n;i++)
    {
        int count=1;
        for(int j=i-1;j>=0;j--)
        {
            // count consecutive less than or equal to
            if(arr[j]<=arr[i])
            {
                count++;
            }
            else 
                break;
        }
        ans[i]=count;
    }
    return ans;
}

// using nearest greater to left
// from ngl to the current element , there will only be smaller or equal to elements present
vector <int> calculateSpan(int arr[], int n)
{
    stack<int> st;
    vector<int> ans(n,1);
    for(int i=0;i<n;i++)
    {
        //smaller elements are popped
        while(!st.empty() && arr[i]>=arr[st.top()])
            st.pop();
        if(!st.empty())
            ans[i]=(i-st.top());
        // reaching here means all are smaller than the element
        else
            ans[i]=i+1;
        st.push(i);
    }
    return ans;
}
#include <vector>
#include <stack>
using namespace std;
int isStackPermutation(int N,vector<int> &A,vector<int> &B){
    int j=0;
    int i=0;
    stack<int> st;
    for(;i<N;i++){
        st.push(A[i]);
        while(!st.empty() && st.top()==B[j])
        {
            st.pop();
            j++;
        }
    }
    if(j==N)
        return 1;
    return 0;
}
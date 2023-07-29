#include <vector>
#include <stack>
using namespace std;
// Using graph: O(n^2) and O(n) -> Brute Force
#define N 8
 
bool MATRIX[N][N] = { { 0, 0, 1, 0 },
                      { 0, 0, 1, 0 },
                      { 0, 0, 0, 0 },
                      { 0, 0, 1, 0 } };
 
bool knows(int a, int b) { return MATRIX[a][b]; }
 
int findCelebrity(int n)
{
    int indegree[n] = { 0 }, outdegree[n] = { 0 };
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x = knows(i, j);
 
            outdegree[i] += x;
            indegree[j] += x;
        }
    }
 
    for (int i = 0; i < n; i++)
        if (indegree[i] == n - 1 && outdegree[i] == 0)
            return i;
 
    return -1;
}

// Using stack: O(n) and O(n) -> Brute Force
int celebrity(vector<vector<int> >& M, int n) 
{
    stack<int> st;
    for(int i=0;i<n;i++)
    {
        //pushing all the candidates to stack
        st.push(i);
    }
    // if stack size becomes 1 , means we have found the celebrity 
    while(st.size()>=2)
    {
        int p=st.top(); st.pop();
        int q=st.top(); st.pop();
        if(M[p][q]==1)
            st.push(q);
        else 
            st.push(p);
    }
    int celeb=st.top();
    int i=st.top();
    for(int k=0;k<n;k++)
    {
        if(i!=k && (M[i][k]==1 || M[k][i]==0))
            return -1;
    }
    return celeb;
}
// Optimal : O(n) and O(1) -> Two pointer
int celebrity(vector<vector<int> >& M, int n) 
    {
        int i=0,j=n-1;
        while(i<j && i<n)
        {
            // if i knows j , it cant be celebrity
            if(M[i][j]==1)
                i++;
            // see if the celebrity candidate knows anyone
            else
                j--;
        }
        int celeb=i;
        for(int k=0;k<n;k++)
        {
            if(k!=i && (M[i][k]==1 || M[k][i]==0))
                return -1;
        }
        return celeb;
    }


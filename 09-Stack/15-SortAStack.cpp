#include <iostream>
#include <stack>
using namespace std;

void insertsorted(stack<int> & st,int x)
{
    if(st.empty() || x<=st.top())
    {
        st.push(x);
        return ;
    }
    else
    {
        // if the element is not in sorted postition , pop it and push the top element
        int y=st.top();
        st.pop();
        insertsorted(st,x);
        st.push(y);
    }
}
void sort(stack<int> &st)
{
    if(!st.empty())
    {
        int x=st.top();
        st.pop();
        sort(st);
        insertsorted(st,x);
    }
}
int main()
{
    stack<int> st, st2;
    // push elements into
    // the stack
    st.push(2);
    st.push(6);
    st.push(1);
    st.push(5);
    st.push(8);
    st2 = st;
 
    cout << "Original Stack" << endl;
    // printing the stack after reversal
    while (!st2.empty()) {
        cout << st2.top() << " ";
        st2.pop();
    }
    cout<<endl;
   
    sort(st);
    cout << "Sorted stack" << endl;
    // printing the stack after reversal
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}

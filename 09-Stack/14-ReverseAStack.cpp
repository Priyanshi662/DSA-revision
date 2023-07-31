#include <stack>
#include <iostream>

using namespace std;

void insertBottom(stack<int> &st,int x)
{
    if(st.empty())
    {
        st.push(x);
    }
    else
    {
        int y=st.top();
        st.pop();
        insertBottom(st,x);
        st.push(y);
    }
    return;
}
void reverse(stack<int> &st)
{
    if(!st.empty())
    {
        int x=st.top();
        st.pop();
        reverse(st);
        insertBottom(st,x);
    }
    return ;
}
int main()
{
    stack<int> st, st2;
    // push elements into
    // the stack
    for (int i = 1; i <= 4; i++) {
        st.push(i);
    }
 
    st2 = st;
 
    cout << "Original Stack" << endl;
    // printing the stack after reversal
    while (!st2.empty()) {
        cout << st2.top() << " ";
        st2.pop();
    }
    cout<<endl;
   
    // function to reverse
    // the stack
    reverse(st);
    cout << "Reversed Stack" << endl;
    // printing the stack after reversal
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int helper(int n,int r[],int k)
{
    int prev=1;
    while(k--)
    {
        prev=r[prev];
    }
    return prev;
}
int main()
{
    int n=6;
    // cin>>n;
    int reciever[n+1]={0,6, 5, 2, 5, 3, 2};
    // for(int i=1;i<=n;i++)
    // {
    //     int x;
    //     cin>>x;
    //     reciever[i]=x;
    // }
    int k=7;
    // cin>>k;
    int res= helper(n,reciever,k);
    cout<<res<<endl;
}
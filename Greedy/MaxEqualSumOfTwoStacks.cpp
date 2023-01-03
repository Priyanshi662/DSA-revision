#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int sumStack(vector<int> v)
    {
        int sum=0;
        for(int it=0;it<v.size();it++)
            sum+=v[it];
        return sum;
    }
    int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){
        // top index of all stacks
        int t1=0,t2=0,t3=0;
        int sum1,sum2,sum3;
        sum1=sumStack(S1);
        sum2=sumStack(S2);
        sum3=sumStack(S3);
        while(t1!=N1 && t2!=N2 &t3!=N3)
        {
            int maxsum=max(sum1,max(sum2,sum3));
            if(sum1==sum2 && sum2==sum3)
                return sum1;
            if(sum1==maxsum)
            {
                // we need to remove top element from stack 1:
                sum1-=S1[t1];
                t1++;
            }
            if(sum2==maxsum)
            {
                sum2-=S2[t2];
                t2++;
            }
            if(sum3==maxsum)
            {
                sum3-=S3[t3];
                t3++;
            }
        }
        return 0;
    }
};

int main()
{
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector<int> s1(n1),s2(n2),s3(n3);
        for(int i=0;i<n1;i++){
            cin>>s1[i];
        }
        for(int i=0;i<n2;i++){
            cin>>s2[i];
        }
        for(int i=0;i<n3;i++){
            cin>>s3[i];
        }
        Solution ob;
        int ans=ob.maxEqualSum(n1,n2,n3,s1,s2,s3);
        cout<<ans<<endl;
    return 0;
}
#include <iostream>

using namespace std;

int countCustomers(int n,string arrivals)
{
    char ch[26];
    int count=0;
    int res=0;
    for(int i=0;i<arrivals.size();i++)
    {
        int index=arrivals[i]-'A';
        if(ch[index]==0)
        {
            // if the character is seen 1st time;
            ch[index]=1;
            if(count<n)
            {
                // 1 computer gets occupied
                count++;
                // set occupied
                ch[index]=2;
            }
            else
            {
                res++;
            }
        }
        else 
        {
            if(ch[index]==2)
                count--;
            // if the customer returns without having a computer
            ch[index]=0;
        }
    }
    return res;
}
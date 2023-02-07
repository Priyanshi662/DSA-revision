// Count triplets in a double linked list that sums to a given number
#include <bits/stdc++.h>
using namespace std;
class ListNode {
public:
    int val;
    ListNode* prev;
    ListNode* next;
};
// brute force :
int countTripBrute(ListNode* head,int k)
{
    ListNode* first=head,*second=head->next,*third=head->next->next;
    int count=0;
    while(first!=NULL)
    {
        first=head;
        while(second!=NULL)
    {
        second=first->next;
        while(third!=NULL)
    {
        third=second->next;
        if(first->val+second->val+third->val == k)
            count++;
        third=third->next;
    }
        second=second->next;
    }
    first=first->next;
    }
    return count;
}
int countTriplets(ListNode* head,int k)
{
    unordered_map<int,ListNode*> mp;
    ListNode* p1;
    ListNode* p2;
    int count=0;
    // Add all elements in the map:
    for(p1=head;p1!=NULL; p1=p1->next)
    {
        mp[p1->val]++;
    }
    for(p2=head;p2!=NULL;p2=p2->next)
    {
        for(ListNode* p3=p2->next;p3!=NULL; p3=p3->next)
        {
            int sum=p3->val+p2->val;
            if(mp.find(k-sum)!=mp.end() && mp[k-sum]!=p2 && mp[k-sum]!=p3)
            {
                count++;
            }
        }
    }
    return count/3;
}
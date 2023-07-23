#include <bits/stdc++.h>
using namespace std;
class ListNode {
public:
    int val;
    ListNode* prev;
    ListNode* next;
};

void BRUTE_FORCE_sortKSortedDLL(ListNode* head,int k)
{
    vector<int> v;
    ListNode* temp=head;
    while(temp!=NULL)
    {
        v.push_back(temp->val);
        temp=temp->next;
    }
    sort(v.begin(),v.end());
    temp=head;
    int i=0;
    while(temp!=NULL && i<v.size())
    {
        temp->val=v[i];
        temp=temp->next;
        i++;
    }
}


struct compare{
    bool operator()(ListNode* p1,ListNode* p2)
    {
        // if greater then return true that we have to swap:
        return p1->val>p2->val;
    }
};
ListNode* MinHeapApproach(ListNode* head,int k)
{
    priority_queue<ListNode*,vector<ListNode*>,compare> hp;
    ListNode* temp=head;
    ListNode* prev=head;
    for(int i=0;i<k&&temp!=NULL;i++)
    {
        hp.push(temp);
        temp=temp->next;
    }
    ListNode* newHead=head;
    while(!hp.empty())
    {
        ListNode* t=hp.top();
        hp.pop();
        if(newHead==NULL)
        {
            // first node :
            newHead=t;
            newHead->prev=NULL;
            prev=newHead;
        }
        else
        {
            prev->next=t;
            t->prev=prev;
            prev=t;
        }
        if(head!=NULL)
        {
            hp.push(head);
            head=head->next;
        }
    }
    prev->next=NULL;
    return newHead;
}
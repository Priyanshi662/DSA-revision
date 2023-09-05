#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void SortedInsert(ListNode * newnode,ListNode* &res)
    {
        ListNode* curr;
        if(res==NULL || res->val>=newnode->val)
        {
            newnode->next=res;
            res=newnode;
        }
        else
        {
            curr=res;
            while(curr->next!=NULL && curr->next->val <newnode->val)
            {
                curr=curr->next;
            }
            newnode->next=curr->next;
            curr->next=newnode;
        }
    }
    ListNode* sortList(ListNode* head) {
        ListNode* curr=head;
        ListNode* sorted=NULL;
        while(curr!=NULL)
        {
            ListNode* next=curr->next;
            SortedInsert(curr,sorted);
            curr=next;
        }
        head=sorted;
        return head;
    }
};
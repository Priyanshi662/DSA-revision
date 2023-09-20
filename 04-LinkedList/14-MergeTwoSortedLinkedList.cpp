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
// Recursive:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)
            return list2;
        if(list2==NULL)
            return list1;
        if(list1->val <= list2->val)
        {
            list1->next=mergeTwoLists(list1->next,list2);
            return list1;
        }
        else
        {
            list2->next=mergeTwoLists(list1,list2->next);
            return list2;
        }
    }    
//    Iterative
    ListNode* TwoSortedListMerge(ListNode* p , ListNode* q)
    {
        if(p==NULL)
            return q;
        if(q==NULL)
            return p;
        ListNode* newHead=p;
        if(p->val>q->val)
        {
            newHead=q;
            q=q->next;
        }
        else
        {
            p=p->next;
        }
        ListNode* temp=newHead;
        while(p!=NULL && q!=NULL)
        {
            if(p->val<=q->val)
            {
                temp->next=p;
                p=p->next;
            }
            else
            {
                temp->next=q;
                q=q->next;
            }
            temp=temp->next;
        }
        if(p!=NULL)
            temp->next=p;
        else
            temp->next=q;
        return newHead;
    } 
};
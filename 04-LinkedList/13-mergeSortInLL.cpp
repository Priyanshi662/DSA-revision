// Heap Sort cannot be used in Linked List because it is not a random access data structure.
// Merge Sort is used in linked list because other sorting work slow for linked list
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
    ListNode* merge(ListNode* left,ListNode* right)
    {
        ListNode* res;
        ListNode* temp=new ListNode(-1);
        res=temp;
        while(left!=NULL && right!=NULL)
        {
            if(left->val <= right->val)
            {
                temp->next=left;
                left=left->next;
            }
            else
            {
                temp->next=right;
                right=right->next;
            }
            temp=temp->next;
        }
        if(left!=NULL)
        {
            temp->next=left;
            left=left->next;
        }
        if(right!=NULL)
        {
            temp->next=right;
            right=right->next;
        }
        return res->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* temp=NULL;
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        // to half the current list 
        temp->next=NULL;
        ListNode* l1=sortList(head);
        ListNode* l2=sortList(slow);
        ListNode* res=merge(l1,l2);
        return res;
    }
};
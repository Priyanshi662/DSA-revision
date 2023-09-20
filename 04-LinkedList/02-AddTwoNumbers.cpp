#include <bits/stdc++.h> 
using namespace std; 
// You are given two non-empty linked lists representing two non-negative integers. 
// The digits are stored in reverse order, and each of their nodes contains a single digit. 
// Add the two numbers and return the sum as a linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* prev;
        ListNode* nl=new ListNode(-1);
        prev=nl;
        int carry=0;
        while(carry>0||l1!=NULL||l2!=NULL)
        {
            carry+=(l1?l1->val:0)+(l2?l2->val:0);
            nl->next=new ListNode(carry%10);
            carry=carry/10;
            nl=nl->next;
            if(l1!=NULL) l1=l1->next;
            if(l2!=NULL) l2=l2->next;
        }
        return prev->next;
    }
    ListNode* rev(ListNode* root)
    {
        if(root==NULL)
            return NULL;
        ListNode* prev,*next,*curr;
        prev=NULL;
        curr=root;
        next=root->next;
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    void insertAtTail(ListNode* & head,ListNode* & tail,int val)
    {
        ListNode* temp=new ListNode(val);
        if(head==NULL)
        {
            head=temp;
            tail=temp;
            return;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
    }
    ListNode* AddTwoNumbers(ListNode* first,ListNode* second)
    {
        int carry=0;
        ListNode* head=NULL;
        ListNode* tail=NULL;
        while(first!=NULL || second!=NULL)
        {
            int dig=(first?first->val:0)+(second?second->val:0)+carry;
            carry=dig/10;
            dig=dig%10;
            insertAtTail(head,tail,dig);
            first=first->next;
            second=second->next;
        }
        if(carry!=0)
            insertAtTail(head,tail,1);
        return head->next;
    }
};
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
    ListNode* rev(ListNode* head)
    {
        if(head==NULL) 
            return head;
        ListNode* prev=NULL;
        ListNode* next=head->next;
        ListNode* curr=head;
        while(curr!=NULL && curr->next!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev->next;
        return head;
    }
};
#include <bits/stdc++.h>
using namespace std;
  
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// For the linked list :- 1->2->3->4->5 => It returns 3->4->5
// For 1->2->3->4 => it returns  3->4
ListNode* middle(ListNode* head)
{
    ListNode* fast=head;
    ListNode* slow=head;
    while(fast->next!=NULL && fast->next->next!=NULL) 
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
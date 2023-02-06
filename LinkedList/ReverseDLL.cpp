#include <bits/stdc++.h>
using namespace std;
class ListNode {
public:
    int val;
    ListNode* prev;
    ListNode* next;
};
void reverse(ListNode* head)
{
    if(head==NULL || head->next==NULL )
        return;
    ListNode* curr=head;
    while(curr!=NULL)
    {
        swap(curr->next,curr->prev);
        head=curr;
        curr=curr->prev;
    }
    // Head is the new head of the reversed doubly linked list
}
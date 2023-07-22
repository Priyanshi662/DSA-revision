#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void deleteAlternate(ListNode* head)
{
    if(head==NULL || head->next==NULL)
        return;
    // remove second node : 
    head->next=head->next->next;
    // start from the third node :
    ListNode * temp=head->next;
    // removes even positioned nodes in circular linked list
    while(temp!=head || temp->next!=head)
    {
        temp->next=temp->next->next;
        temp=temp->next;
    }
}
void deleteSpecific(ListNode* head,int key)
{
    if(head->val==key)
    {
        head=head->next;
        return;
    }
    ListNode* prev=head;
    ListNode* temp=head->next;
    while(temp!=head &&temp->next!=head)
    {
        if(temp->val==key)
        {   
            prev->next=temp->next;
        }
        prev=temp;
        temp=temp->next;
    }
}
void reverseCircularLinkedList(ListNode* head)
{
    ListNode* prev=head;
    ListNode* curr=head->next;
    ListNode* next;
    while(curr!=head)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    // prev is the new head after reversing so connect last node->next= head(prev)
    curr->next=prev;
    // change head to prev
    head=prev;
}
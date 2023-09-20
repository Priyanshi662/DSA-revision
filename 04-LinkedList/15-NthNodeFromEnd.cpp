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
    int getlength(ListNode* head)
    {
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp;
        temp=head;
        int m=getlength(head);
        if(n==m)
        {
            head=head->next;
            return head;
        }
        int prevpos=m-n;
        int count=1;
        while(count<prevpos && temp->next!=NULL)
        {   
            temp=temp->next;
            count++;
        }
        temp->next=temp->next->next;
        return head;
    }
    ListNode* removeOptimal(ListNode* head,int n)
    {
        // we can do this using fast and slow pointer concept
        // put fast pointer at nth node from starting
        // put slow at head
        // move the fast pointer until it becomes null and slow pointer by one distance
        // slow points to the previous node of nth from last
        ListNode* fast=head;
        ListNode* slow=head;
        for(int i=0;i<n;i++)
        {
            fast=fast->next;
        }
        if(fast==NULL)
        {
            // means sizeofLinkedList=n
            return head->next;
        }
        // the distance between slow and fast =n so when fast->next=NULL then
        // slow ->next is the nth node from the end
        while(fast!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        return head;
    }
};
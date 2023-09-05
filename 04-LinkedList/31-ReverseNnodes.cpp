#include <bits/stdc++.h>
using namespace std;
//   https://leetcode.com/problems/reverse-linked-list-ii/description/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverseNodes(ListNode* head,int left,int right)
    {
        if(head==NULL ||head->next==NULL)
            return head;
        ListNode* prev=NULL;
        ListNode* curr=head;
        // right is the count of nodes in the portion that is to be reversed
        right=right-left+1;
        while(left>1)
        {
            prev=curr;
            curr=curr->next;
            left--;
        }
        ListNode* headtemp=prev;
        ListNode* tail=headtemp->next;
        ListNode* next;
        while(right>0)
        {
            // reversing logic
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;

            right--;
        }

        // connect the first node of the portion reversed to the previous intersecting node
        if(headtemp==NULL)
        {
            // means the first node was the starting node
            head=prev;
        }
        else
        {
            headtemp->next=prev;
        }
        // connect the last node of the portion to the next nodes
        tail->next=curr;
        return head;
    }
};
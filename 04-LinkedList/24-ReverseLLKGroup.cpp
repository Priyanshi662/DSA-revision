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

ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL) 
            return NULL;
        ListNode* current=head;
        // check for the size of list
        // if the list is too short that is less than K then return head
        for(int i=0;i<k;i++)
        {
            if(current==NULL)
                return head;
            current=current->next;
        }
        
        int count=0;
        ListNode* prev=NULL;
        ListNode* next=head->next;
        ListNode* curr=head;
        while(curr!=NULL && count<k)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        head->next=reverseKGroup(curr,k);
        return prev;
    }
     ListNode* reverse(ListNode* head,ListNode* tail)
    {
        ListNode* prev=tail;
        while(head!=tail)
        {
            auto tmp=head->next;
            head->next=prev;
            prev=head;
            head=tmp;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* tail=head;
        for(int i=0;i<k;i++)
        {
            if(tail==NULL)
                return head;
            tail=tail->next;
        }
        ListNode* temp=reverse(head,tail);
        head->next=reverseKGroup(tail,k);
        return temp;
    }
};
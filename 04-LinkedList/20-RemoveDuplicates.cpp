#include <bits/stdc++.h>
using namespace std;
  
class Solution {
public:
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* p,*q;
        p=head;
        q=head->next;
        // checking adjacent nodes and skipping the duplicate ones by adjusting the next pointer of previous node
        while(q!=NULL && p->next!=NULL)
        {
            if(p->val==q->val)
            {
                q=q->next;
                p->next=q;
            }
            else
            {
                p=p->next;
                q=q->next;
            }
        }
        return head;
    }
};
/*
    // from sorted list
    Node* removeDuplicatesFromSortedLL(Node* head)
    {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* temp=head;
        while(temp!=NULL && temp->next!=NULL)
        {
            if(temp->val==temp->next->val)
            {
                ListNode* dupliNode=temp->next;
                temp->next=temp->next->next;
                delete dupliNode;
            }
            else
                temp=temp->next;
        }
        return head;
    }
    }
*/
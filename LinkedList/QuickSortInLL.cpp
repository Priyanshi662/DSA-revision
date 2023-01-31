#include <bits/stdc++.h>
using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

//Quick Sort takes the time complexity as O(nlogn) and SC as O(1) in arrays
// But here it will take Tc:O(nlogn) but space complexity as O(n) because of the sorted insert function
// It takes O(n^2) in worst case scenario
class Solution {
public:
    void SortedInsert(ListNode * newnode,ListNode* &res)
    {
        ListNode* curr;
        if(res==NULL || res->val>=newnode->val)
        {
            newnode->next=res;
            res=newnode;
        }
        else
        {
            curr=res;
            while(curr->next!=NULL && curr->next->val <newnode->val)
            {
                curr=curr->next;
            }
            newnode->next=curr->next;
            curr->next=newnode;
        }
    }
    ListNode* sortList(ListNode* head) {
        ListNode* curr=head;
        ListNode* sorted=NULL;
        while(curr!=NULL)
        {
            ListNode* next=curr->next;
            SortedInsert(curr,sorted);
            curr=next;
        }
        head=sorted;
        return head;
    }
};
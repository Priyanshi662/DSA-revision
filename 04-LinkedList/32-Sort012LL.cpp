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
    // brute force: count 0s 1s and 2s
    ListNode* sort012(ListNode* root)
    {
        if(root==NULL)
            return root;
        int zeroes=0;
        int ones=0;
        int twos=0;
        ListNode* temp=root;
        while(temp!=NULL)
        {
            if(temp->val==0)
                zeroes++;
            else if(temp->val==1)
                ones++;
            else 
                twos++;
        }
        temp=root;
        while(temp!=NULL)
        {
            if(zeroes!=0)
            {
                temp->val=0;
                zeroes--;
            }
            else if(ones!=0)
            {
                ones--;
                temp->val=1;
            }
            else if(twos!=0)
            {
                temp->val=2;
                twos--;
            }
            temp=temp->next;
        }
        return root;
    }
    // 2nd approach:
    void insertAtTail(ListNode* &tail,ListNode* temp)
    {
        tail->next=temp;
        tail=temp;
    }
    ListNode* Sort012(ListNode* root)
    {
        ListNode* zeroHead=new ListNode(-1);
        ListNode* oneHead=new ListNode(-1);
        ListNode* twoHead=new ListNode(-1);
        ListNode* zerotail=zeroHead;
        ListNode* onetail=oneHead;
        ListNode* twotail=twoHead;
        ListNode* temp=root;
        while(temp!=NULL)
        {
            if(temp->val==0)
            {
                insertAtTail(zerotail,temp);
            }
            if(temp->val==1)
            {
                insertAtTail(onetail,temp);
            }
            if(temp->val==2)
            {
                insertAtTail(twotail,temp);
            }
            temp=temp->next;
        }
        if(oneHead->next!=NULL)
        {
            zerotail->next=oneHead;
        }
        else
        {
            zerotail->next=twoHead;
        }
        onetail->next=twoHead;
        twotail->next=NULL;
        root=zeroHead;
        delete zeroHead;
        delete oneHead;
        delete twoHead;
        return root;
    }
};
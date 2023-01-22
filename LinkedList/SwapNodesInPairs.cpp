#include<bits/stdc++.h>
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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* temp=new ListNode(-1);
        ListNode* curr=head;
        ListNode* prev=temp;
        while(curr!=NULL && curr->next!=NULL)
        {
            prev->next=curr->next;
            curr->next=prev->next->next;
            prev->next->next=curr;
            prev=curr;
            curr=curr->next;
        }
        return temp->next;
    }
    // Space Optimized : However it takes Recursive stack space
    ListNode* swapPairsSpaceOp(ListNode* head) {
       if(head==NULL) return NULL;
        else{
            ListNode* prev=NULL;
            ListNode* cur=head;
            ListNode* temp;
            int cnt=1;
            while(cur!=NULL and cnt<=2){
                temp=cur->next;
                cur->next=prev;
                prev=cur;
                cur=temp;
                cnt++;
            } 
            if(temp!=NULL) head->next=swapPairs(temp);
            return prev;
        }
    }
};
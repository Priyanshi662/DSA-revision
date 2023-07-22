/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* p1=head;
        int count=0;
        while(p1!=NULL)
        {
            count+=1;
            p1=p1->next;
        }
        vector<ListNode*> res(k,NULL);
        int n=count/k;
        int r=count%k;
        p1=head;
        ListNode* prev=NULL;
        for(int i=0;p1&&i<k;i++,r--)
        {
            res[i]=p1;
            for(int j=0;j<(n+(r>0));j++)
            {
                prev=p1;
                p1=p1->next;
            }
            prev->next=NULL;
        }
        return res;
    }
};
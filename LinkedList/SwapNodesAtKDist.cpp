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
// BRUTE FORCE : O(n) and O(n)
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> arr;
        ListNode* temp=head;
        int n=1;
        while(temp!=NULL)
        {
            arr.push_back(temp->val);
            n++;
            temp=temp->next;
        }
        swap(arr[k-1],arr[n-k-1]);
        temp=head;
        int i=0;
        while(temp!=NULL && i<arr.size())
        {
            if(temp->val!=arr[i])
            {
                temp->val=arr[i];
            }
            i++;
            temp=temp->next;
        }
        return head;
    }
    // Optimized - SC:O(1):
    ListNode* swapNodesOp(ListNode* head, int k) {
        ListNode* first=head;
        ListNode* second=head;
        while(--k)
        {
            first=first->next;
        }
        ListNode* p=first;
        while(first->next!=NULL)
        {
            first=first->next;
            second=second->next;
        }
        swap(p,second);
        return head;
    }
};
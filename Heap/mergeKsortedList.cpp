#include <bits/stdc++.h>
using namespace std;
// This is a good question to practice for coding interviews
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
// using min heap:
    class comp_func{
        public:
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comp_func>pq;
        int n = lists.size();
        // we keep a dummy pointer which is considered just before start
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        for(int i = 0;i<n;i++){
            if(lists[i]!=NULL){
                pq.push(lists[i]);
            }
        }
        while(!pq.empty()){
            ListNode* minNode = pq.top();
            tail->next = minNode;
            tail = tail->next;
            // tail = minNode;
            pq.pop();

            // now increment pointer
            if(minNode->next!=NULL)
                pq.push(minNode->next);
            

        }
        return dummy->next;
        // i.e. head
    }
// Using 2 pointer technique:
    ListNode* merge(ListNode* first,ListNode* second)
    {
        ListNode* res=NULL;
        if(first==NULL)
            return second;
        if(second==NULL)
            return first;
        if(first->val < second->val)
            res=first;
        else
        {
            res=second;
            second=first;
            first=res;
        }
        while(first->next!=NULL)
        {
            if(first->next->val > second->val)
            {
                swap(first->next,second);
            }
            first=first->next;
        }
        first->next=second;
        return res;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        if(k==0)
            return NULL;
        for(int i=0;i<k-1;i++)
        {
            lists[i+1]=merge(lists[i],lists[i+1]);
        }
        return lists[k-1];
    }
    // Using Merge Sort technique:
    ListNode* mergeTwoLists(ListNode* left , ListNode* right) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* copyHead = dummyHead;\
    
        while(left and right) {
                int vleft = left -> val;
                int vright = right -> val;
                dummyHead -> next = vleft < vright ? new ListNode(vleft) : new ListNode(vright);
                left = vleft < vright ? left -> next : left;
                right = vleft < vright ? right : right -> next;
                dummyHead = dummyHead -> next;
            }
            while(left) {
                dummyHead -> next = new ListNode (left -> val);
                dummyHead = dummyHead -> next;
                left = left -> next;
            }
            while(right) {
                dummyHead ->next = new ListNode( right -> val);
                dummyHead = dummyHead -> next;
                right = right -> next;
            }
            return copyHead -> next;

        }
        ListNode* helper(int L, int R, vector<ListNode*> & lists) {
            if( L > R) return NULL;
            if( L  == R) return lists[L];
            int M = (L+R) / 2;
            auto left = helper(L, M , lists);
            auto right = helper( M+1 , R , lists);
            return mergeTwoLists(left , right);
        }
        ListNode* mergeKLists(vector<ListNode*> & lists) {
           return helper( 0 , lists.size() - 1, lists);

        }       

};
int main()
{
    ListNode* head1=new ListNode(1);
    ListNode* head2=new ListNode(1);
    ListNode* head3=new ListNode(2);
    head1->next=new ListNode(4);
    head1->next->next=new ListNode(5);
    head2->next=new ListNode(3);
    head2->next->next=new ListNode(4);
    head3->next=new ListNode(6);
    vector<ListNode*> lists;
    lists.push_back(head1);
    lists.push_back(head2);
    lists.push_back(head3);
    Solution s;
    ListNode* res=s.mergeKLists(lists);
    while(res!=NULL)
    {
        cout<<res->val<<" ";
        res=res->next;
    }
    return 0;
}
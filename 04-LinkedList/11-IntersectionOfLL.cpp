#include <bits/stdc++.h>
using namespace std;
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

ListNode *getIntersectionNodeBrute(ListNode *headA, ListNode *headB) {
        // Brute Force: TC: O(m*n) SC:O(1)
        ListNode* temp=headB;
        while(headA!=NULL)
        {
            // everytime B is fully traversed for one iteration of list A
            // B is brought back to headB
            temp=headB;
            while(temp!=NULL)
            {
                // if the current node of A is same as current node of B:
                if(headA==temp)
                return headA;
                temp=temp->next;
            }
            headA=headA->next;
        }
        return NULL;
    }
 ListNode *getIntersectionNodeBetter(ListNode *headA, ListNode *headB) {
        //Better : O(m+n) SC:O(n)
        unordered_map<ListNode*,int> mp;
        while(headA!=NULL)
        {
            mp[headA]++;
            headA=headA->next;
        }
        while(headB!=NULL)
        {
            if(mp[headB]!=0)
                return headB;
            headB=headB->next;
        }
        return NULL;
    }
int getLength(ListNode* a)
    {
        int n=0;
        while(a!=NULL)
        {
            n++;
            a=a->next;
        }
        return n;
    }
    ListNode *getIntersectionNode(ListNode *a, ListNode *b) {
        // Difference in length Solution:
        //  TC : O(m+n) SC:O(1)
        int n1=getLength(a);
        int n2=getLength(b);
        ListNode* p1=a;
        ListNode* p2=b;
        if(n1<n2)
            swap(p1,p2);
        int diff=abs(n1-n2);
        while(diff!=0 && p1!=NULL)
        {
            p1=p1->next;
            diff--;
        }
        while(p1!=NULL && p2!=NULL)
        {
            if(p1==p2)
            {
                return p1;
            }
            p1=p1->next;
            p2=p2->next;
        }
    return NULL;
    }
    ListNode *getIntersectionNode2Pointer(ListNode *a, ListNode *b) {
        ListNode* p1=a;
        ListNode* p2=b;
        //  TC : O(m+n) SC:O(1)
         // this condition will be first to check because if both null then the intersection is not there
        if(p1==NULL || p2==NULL) 
            return NULL;
        while(p1!=NULL && p2!=NULL && p1!=p2)
        {
            p1=p1->next;
            p2=p2->next;
            if(p1==p2)
                return p1;
            if(p1==NULL) 
                p1=b;
            if(p2==NULL)
                p2=a;
        }
        return p1;
    }
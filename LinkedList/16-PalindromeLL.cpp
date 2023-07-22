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
// Brute Force :
    bool isPalindromeBrute(ListNode * head)
    {
        vector<int> arr;
        ListNode * temp=head;
        while(temp!=NULL)
        {
            arr.push_back(temp->val);
            temp=temp->next;
        }
        int i=0;
        int j=arr.size()-1;
        while(i<j)
        {
            if(arr[i]!=arr[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
//  Optimal Solution :
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head, *prev, *temp;
        while (fast && fast->next)
        {
            // Finding the middle node : 
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow is middle 
        prev = slow, slow = slow->next, prev->next = NULL;
        // reversing from mid till end :
        while (slow)
        {
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        fast = head, slow = prev;
        while (slow)
        {
            if (fast->val != slow->val) 
                return false;
            else 
            {
                fast = fast->next, slow = slow->next;
            }
        }
        return true;
    }
};
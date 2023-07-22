// Split the given circular linked list in half :
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
    
    void splitList(ListNode *head, ListNode **head1_ref, ListNode **head2_ref)
    {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next!=head && fast->next->next!=head)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        *head2_ref=slow->next;
        slow->next=head;
        ListNode* temp=*head2_ref;
        while(temp->next!=head)
            temp=temp->next;
        temp->next=*head2_ref;
        *head1_ref=head;
    }  
};
int main()
{
    Solution ob;
    ListNode* head;
    ListNode **head1,**head2;
    cout<<"Enter number of nodes : ";
    int n;
    cin>>n;
    ListNode* temp;
    cout<<"Enter node values : ";
    int x;
    cin>>x;
    head=new ListNode(x);
    temp=head;
    for(int i=0;i<n-1;i++)
    {
        int x;
        cin>>x;
        temp->next=new ListNode(x);
        temp=temp->next;
    }
    temp->next=head;
    ob.splitList(head,head1,head2);
    cout<<"The heads of splitted list are : "<<head1<<" "<<head2;
    return 0;
}
#include <iostream>
using namespace std;

// Use Turtle and Hare Algorithm to detect loop and remove it 
struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
class Solution
{
    public:
      
    void removeloopUtil(Node* slow,Node* head)
    {
        Node* p1=slow;
        Node* p2=slow;
        //Count number of nodes in the loop
        int k=1;
        while(p1->next!=p2)
        {
            p1=p1->next;
            k++;
        }
        // Move k nodes from the starting 
        p1=head;
        p2=head;
        for(int i=0;i<k;i++)
        {
            p1=p1->next;
        }
         // p2 starts from head of linked list and move until it reaches the node p1
        // p1 stands at k nodes from starting and will traverse the loop till then
        // p1 and p2 will point to the same node i.e starting of the loop
        while(p1!=p2)
        {
            p1=p1->next;
            p2=p2->next;
        }
        while(p1->next!=p2)
        {
            p1=p1->next;
        }
        p1->next=NULL;
    }
    void removeLoop(Node* head)
    {
        Node* fast=head;
        Node* slow=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            // Detect Loop if loop exists remove it
            if(slow==fast)
                removeloopUtil(slow,head);
        }
    }
};
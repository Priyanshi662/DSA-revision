#include <iostream>
#include <bits/stdc++.h>
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
    bool detectLoop(Node* head)
    {
        Node* slow=head;
        Node* fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            if(slow==fast)
                return true;
            slow=slow->next;
            fast=fast->next->next;
        }
        return false;
    }
    // BRUTE FORCE : O(N) SC
    void bruteForceRemoveLoop(Node *head)
    {
        unordered_map<Node*,int> mp;
        Node* tail=NULL;
        while(head!=NULL)
        {
            if(mp.find(head)==mp.end())
            {
                mp[head]++;
                tail=head;
                head=head->next;
            }
            else
            {
                tail->next=NULL;
                break;
            }
        }
    }
    // Better Approach -COunting Nodes:
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
        // 
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
    // Best Approach :
     void removeLoopOptimal(Node* head)
    {
        Node* fast=head;
        Node* slow=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
                break;
        }
        if(slow==fast)
        {
            slow=head;
            if(slow==fast)
            {
                while(fast->next!=slow)
                    fast=fast->next;
            }
            else
            {
                while(slow->next!=fast->next)
                {
                    slow=slow->next;
                    fast=fast->next;
                }
            }
        }
        fast->next=NULL;
    }
};
void printll(Node* head)
{
    while(head->next!=NULL)
        cout<<head->data<<"->";
    cout<<"/0"<<endl;
}
void InsertLoopHere(Node* head,Node* tail,int pos)
{
    if(pos==0)
        return;
    
    Node* temp=head;
    for(int i=1;i<pos;i++)
        temp=temp->next;
    tail->next=temp;
}
int main(){
    Node* head;
    Node* temp;
    head=temp;
    cout<<"Enter number of elements in the linked list : ";
    int n;
    cin>>n;
    cout<<"Enter elements of the linked list : ";
    int x;
    cin>>x;
    temp=new Node(x);
    for(int i=1;i<n;i++)
    {
        cin>>x;
        Node* p=new Node(x);
        temp->next=p;
        temp=temp->next;
    }
    temp->next=NULL;
    cout<<"Enter position of the loop : ";
    int pos;
    cin>>pos;
    InsertLoopHere(head,temp,pos);
    cout<<"Linked List is : ";
    printll(head);
    Solution ob;
    ob.bruteForceRemoveLoop(head);
    bool res=ob.detectLoop(head);
    if(res)
    {
        printll(head);
    }
    else
    {
        cout<<"Wrong answer!"<<endl;
    }
    return 0;
}
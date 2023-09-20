#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


class Solution
{
    public:
    Node* reverse(Node* head)
    {
        Node* prev=NULL;
        Node* curr=head;
        Node* next;
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    Node* addOneUtil(Node* head)
    {
        int sum=0;
        int carry=1;
        Node* prev;
        Node* temp=head;
        while(head!=NULL)
        {
            sum=head->data+carry;
            carry=(sum>=10)? 1:0;
            sum=sum%10;
            head->data=sum;
            prev=head;
            head=head->next;
        }
        if(carry>0)
            prev->next=new Node(1);
        return temp;
    }
    Node* addOne(Node *head) 
    {
        head=reverse(head);
        head=addOneUtil(head);
        head=reverse(head);
        return head;
    }
};
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
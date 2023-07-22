#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* findIntersection(Node* head1, Node* head2)
{
    Node* res=new Node(-1);
    Node* t=res;//initializing with a null node
    Node* v=t;
    Node* r1=head1;
    Node* r2=head2;
    while(r1&&r2)
    {
        if((r1->data)<(r2->data))
        {
            r1=r1->next;
        }
        else if((r1->data)>(r2->data))
        {
            r2=r2->next;
        }
        else if((r1->data)==(r2->data))
        {
            Node* temp=new Node(r1->data);
            t->next=temp;
            t=t->next;
            r1=r1->next;
            r2=r2->next;
        }
    }
    return v->next;
}
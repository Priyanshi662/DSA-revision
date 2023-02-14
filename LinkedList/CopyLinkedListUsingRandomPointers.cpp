#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
// Brute Force using a hashmap
// O(n) and O(n)
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> mp;
        Node* temp;
        for(temp=head;temp!=NULL;temp=temp->next)
        {
            Node* cpyNode=new Node(temp->val);
            // mapping old nodes to the copy of them
            mp[temp]=cpyNode;
        }
        temp=head;
        while(temp!=NULL)
        {
            Node* copyNode=mp[temp];
            // setting pointers of copynode
            // copynode->next=nextcopyNode
            copyNode->next=mp[temp->next];
            // copy->random=original node ->random
            copyNode->random=mp[temp->random];
            temp=temp->next;
        }
        return mp[head];
    }
    // Using no extra space:
    
    Node* copyRandomListOptimal(Node* head) {
        Node* temp;
        if(head==NULL)
        {
            return NULL;
        }
        for(temp=head;temp!=NULL;temp=temp->next->next)
        {
            Node* cpy=new Node(temp->val);
            cpy->next=temp->next;
            temp->next=cpy;
        }
        // set the random pointers
        for(temp=head;temp!=NULL;temp=temp->next->next)
        {
            // temp->random->next=copy node of node where temp->random is pointing to
            // temp->next->random =copy node of current node->random
            if(temp->random!=NULL)
                temp->next->random=temp->random->next;
        }
        Node* newHead=head->next;
        for(temp=head;temp!=NULL;temp=temp->next)
        {
            // temp->next=copy node
            Node* cpy=temp->next;
            temp->next=cpy->next;
            if(cpy->next!=NULL)
            {
                // if it is not the last node
                cpy->next=cpy->next->next;
            }
        }
        return newHead;
    }
};
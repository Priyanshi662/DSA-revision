//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void print(Node *root)
{
Node *temp = root;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}

class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.

    // Brute Force -> O(n^2) but space O(1)
    Node* removeDuplicates1(Node* head)
    {
        // without using extra space:
        Node* temp=head;
        while(temp!=NULL && temp->next!=NULL)
        {
            Node* temp2=temp->next;
            while(temp2!=NULL && temp2->next!=NULL)
            {
                if(temp2->data==temp->data)
                {
                    temp2=temp2->next->next;
                    temp->next=temp2;
                }
                else
                {
                    temp2=temp2->next;
                }
            }
        }
        return head;
    }
    // Using sorting - O(nlogn)

    
    // Optimal - using map -O(n) and O(n)
    Node * removeDuplicates( Node *head) 
    {
        unordered_map<int,int> mp;
        Node* temp=head;
        mp[temp->data]=1;
        while(temp->next!=NULL)
        {
             if(mp.find(temp->next->data)!=mp.end())
             {
                Node* dupliNode=temp->next;
                delete dupliNode;
                temp->next=temp->next->next;
             }
             else
             {
                 temp=temp->next;
                 ++mp[temp->data];
             }
        }
        return head;
    }
};

int main() {
	int T;
	cin>>T;
	
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
 
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
	    Solution ob;
		Node *result  = ob.removeDuplicates(head);
		print(result);
		cout<<endl;
		
	}
	return 0;
}
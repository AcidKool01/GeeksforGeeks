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


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
    Node* Reverse(Node *head)
    {
        Node *p = head, *q = NULL, *r = NULL;
        while (p!=NULL)
        {
            r=q;
            q=p;
            p=p->next;
            q->next =r;
        }
        
        head = q;
        return head;
    }
    
    Node* addOne(Node *head) 
    {
        Node *p=Reverse(head);
        Node *q=p;
        while(p!=NULL)
        {
            p->data+=1;
            if(p->data==10 && p->next!=NULL)
            {
                p->data=0;
                p=p->next;
            }
            else
                break;
        }
        return Reverse(q);
    }
};

// { Driver Code Starts.

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
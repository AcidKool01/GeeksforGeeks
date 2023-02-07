// { Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    
    struct Node* reverse(struct Node* l1)
    {
        Node *p=l1, *q=NULL, *r=NULL;
        while (p)
        {
            r = q;
            q = p;
            p=p->next;
            
            q->next = r;
        }
        l1 = q;
        
        return l1;
    }
    
    
    struct Node* addTwoLists(struct Node* l1, struct Node* l2)
    {
        Node *res = new Node(0);
        Node *curr = res;
        
        Node* t1 = reverse(l1);
        Node* t2 = reverse(l2);
        
        int sum = 0;
        int carry = 0;
        
        while (t1 || t2)
        {
            if (t1)
            {
                sum += t1->data;
                t1 = t1->next;
            }
            
            if (t2)
            {
                sum += t2->data;
                t2 = t2->next;
            }
            
            carry = (sum>=10)?1:0;
            
            curr->next = new Node(sum%10);
            curr = curr->next;
            sum /=10;
        }
        
        if (carry>0)
        {
            Node* temp = new Node(carry);
            curr->next = temp;
            curr = temp;
        }
        
        return reverse(res->next);
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends
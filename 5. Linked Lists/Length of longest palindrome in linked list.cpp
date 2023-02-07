#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void append(struct Node** head_ref, struct Node **tail_ref,
            int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Function to get the middle of the linked list*/
int maxPalindrome(Node *);


/* Driver program to test above function*/
int main()
{
    int T,n,l;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        for (int i=1; i<=n; i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
      

       cout << maxPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends

int countpalindrome(Node *a,Node *b)
{
    int c=0;
    for(;a&&b;a=a->next,b=b->next)
    {
        if(a->data==b->data)
            c++;
        else 
            break;        
    }
    return c;
}

int maxPalindrome(Node *head)
{
    Node *prev=NULL;
    int res=0;
    while(head){
        Node *nxt=head->next;
        head->next=prev;
        res=max(res,2*countpalindrome(prev,nxt)+1);
        res=max(res,2*countpalindrome(head,nxt));
        prev=head;
        head=nxt;
    }
    return res;
}
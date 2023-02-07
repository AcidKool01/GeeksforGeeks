#include <stdio.h>
#include <stdlib.h>
#include <iostream>
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

void reorderList(struct Node* head);

/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }

        reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}
// } Driver Code Ends


/* Following is the Linked list node structure */

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

Node* reverse (Node* head)
{
    Node* p = head, *q = NULL, *r = NULL;
    while (p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next = r;
    }
    
    head = q;
    
    return head;
}

void reorderList(Node* head) {

    Node *slow=head,*fast=head,*prev;
    
    while(fast!=NULL&&fast->next!=NULL)
    {
        fast=fast->next->next;
        prev=slow;
        slow=slow->next;
    }
    
    if(fast!=NULL)
    {
        prev=slow;
        slow=slow->next;
    }
    
    prev->next=NULL;
    slow=reverse(slow);
    Node *curr=head;
    
    while(slow!=NULL)
    {
        Node *temp=curr->next;
        Node *temp2=slow->next;
        curr->next=slow;
        slow->next=temp;
        slow=temp2;
        curr=temp;
    }
    
}
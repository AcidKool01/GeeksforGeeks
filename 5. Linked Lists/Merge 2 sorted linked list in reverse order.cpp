#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}

struct Node * mergeResult(struct Node *node1,struct Node *node2);

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }

        struct Node* result = mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}
// } Driver Code Ends


/*

The structure of linked list is the following

struct Node
{
int data;
Node* next;
};

*/

Node *reverse (Node* head)
{
    Node *p = head, *q= NULL, *r= NULL;
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

struct Node * mergeResult(Node *first,Node *second)
{
    Node *last = NULL, *third = NULL;
    
    if (first->data <second->data)
    {
        last = third = first;
        first = first->next;
        last->next = NULL;
    }
    
    else
    {
        last = third = second;
        second = second->next;
        last->next = NULL;
    }
    
    while (first && second)
    {
        if (first->data <second->data)
        {
            last->next = first;
            last = first;
            first = first->next;
            last->next = NULL;
        }
        else
        {
            last->next = second;
            last = second;
            second = second->next;
            last->next = NULL;
        }
    }
    
    if (first!=NULL)
        last->next = first;
        
    else
        last->next = second;
        
    Node *res = reverse(third);
    
    return res;
}
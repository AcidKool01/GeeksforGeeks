#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



Node *swapkthnode(Node* head, int num, int K);

void addressstore(Node **arr, Node* head)
{
    Node* temp = head;
    int i = 0;
    while(temp){
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

bool check(Node ** before, Node **after, int num, int K)
{
    if(K > num)
        return 1;
    return (before[K-1] == after[num - K]) && (before[num-K] == after[K-1]);
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        int num, K , firstdata;
        cin>>num>>K;
        int temp;
        cin>>firstdata;
        Node* head = new Node(firstdata);
        Node* tail = head;
        for(int i = 0; i<num - 1; i++){
            cin>>temp;
            tail->next = new Node(temp);
            tail = tail->next;
        }
        
        Node *before[num];
        addressstore(before, head);
        
        head = swapkthnode(head, num, K);
        
        Node *after[num];
        addressstore(after, head);
        
        if(check(before, after, num, K))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends


//User function Template for C++

/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
     Node(int x) {
        data = x;
        next = NULL;
  }
  }
*/

//Function to swap Kth node from beginning and end in a linked list.
Node *swapkthnode(Node* head, int num, int K)
{
    // Your Code here
    if (K>num)
        return head;
        
    if (K==num-K+1)
        return head;
        
    Node *temp1 = head;
    Node *temp2 = head;
    
    Node *prev1 = NULL;
    Node *prev2 = NULL;
    
    int temp = num-K+1;
    
    for (int i=1; i<temp; i++)
    {   
        prev1 = temp1;
        temp1 = temp1->next;
    }
    for (int i=1; i<K; i++)
    {   
        prev2 = temp2;
        temp2 = temp2->next;
    }
    
    if (prev1)
        prev1->next = temp2;
    if (prev2)
        prev2->next = temp1;
    
    Node* rex = temp1->next;
    temp1->next = temp2->next;
    temp2->next = rex;
    
    if(K==1)
        head=temp1;
    if(K==num)
        head=temp2;
    
    return head;
}

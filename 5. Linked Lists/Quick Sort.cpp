#include <iostream>
#include <cstdio>
using namespace std;
 
/* a node of the singly linked list */
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node = new node(new_data);
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* A utility function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void quickSort(struct node **headRef);
int main()
{
	int t,n,x;
	cin>>t;
	while(t--){
		
        
        cin>>n;n=n-1;
		cin>>x;
        node *temp,*head = new node(x);
        temp=head;
        while(n--)
        {
			cin>>x;
          temp->next=new node(x);
          temp=temp->next;
			}
    
    quickSort(&head);
 
    printList(head);
 while(head!= NULL){
     temp=head;
     head=head->next;
     free(temp);
     
 }
	}
    return 0;
}// } Driver Code Ends

struct node *quick(struct node *head){
    if(head->next==NULL){
        struct node *hare;
        hare=head;
        return(hare);
    }
    
    struct node *hare= quick(head->next);
    struct node *temp1=hare;
    
    while(temp1->next!=NULL)
        temp1=temp1->next;
    
    if(head->data>hare->data){
        temp1->next=head;
        head->next=NULL;
        return(hare);
    }
    
    else{
        struct node *ptr=head;
        ptr->next=hare;
        hare=ptr;
        return(hare);
    }
}

void quickSort(struct node **headRef) {
    struct node *head=*headRef;
    struct node *temp=head,*def;
    int count=0;
    
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    
    int sum=0;
    def=quick(head);
    
    while(count--)
        def= quick(def);
    
    *headRef=def;
}
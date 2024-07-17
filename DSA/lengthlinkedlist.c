// WAP to print the length of LinkedList in O(n/2).
#include<stdio.h>
#include<stdlib.h>
struct node *createNode(int data);
struct node *insertAtEnd(struct node *head, int data);
struct node* insertAtBeg(struct  node* temp,int data);
int  lengthoflist(struct node* head);
void display(struct node *temp);
typedef struct node{
    int data;
    struct node *next;
}sll;
struct node* createNode(int data){
    struct node* newNode=(struct node* )(malloc(sizeof(sll)));
    newNode->next=NULL;
    newNode->data=data;

    return newNode;
}
struct node* insertAtEnd(struct node *head, int data){
    if(head == NULL){
        return createNode(data);
    }
    else{
        struct node *temp=head;
        while(temp->next != NULL){
            temp=temp->next;
        }
        temp->next=createNode(data);
    }
    return head;
}
//pass by reference
int lengthoflist(struct node* head){
    struct node* temp=head;
    int count=1;
    if(temp==NULL){
        return 0;
    }
    while(temp != NULL && temp->next != NULL){
        count=count+2;
        temp=temp->next->next;
    }
    if(temp==NULL){
        return count-1;
    }
    else if(temp->next == NULL){
        return count;
    }
}
void display(struct node *temp){
    while (temp != NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    
}
struct node* insertAtBeg(struct  node* head,int data)
{
     if(head ==NULL)
         return createNode(data);
    struct node *temp = createNode(data);
     temp->next=head;
    return temp;
}
int sum(struct node * temp,int k){
    int s=0;
    while(temp != NULL && k > 0){
        s=s+temp->data;
        temp=temp->next;
        k--;
    }
    if(k == 0)
        return s;
    else
       return 0;
}
int main(){
    struct node *head=NULL;
    head=insertAtEnd(head,10);
    insertAtEnd(head,20);
    insertAtEnd(head,30);
    insertAtEnd(head,40);
    insertAtEnd(head,50);
    insertAtEnd(head,60);
    insertAtEnd(head,70);
    insertAtEnd(head,80);
    insertAtEnd(head,90);
    insertAtEnd(head,100);
    display(head);
    //head=insertAtBeg(head,5);
    printf("\n");
    display(head);
    printf("\n");
    int size=lengthoflist(head);
    printf("%d",size);
    printf("\n");

    printf("%d",sum(head,8));
    return 0;
}
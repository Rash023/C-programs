#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;

};

struct node *head,*newnode,*temp=NULL;


void create()
{
    int n;
    printf("enter length of the linkedlist:");
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter %d element:",(i+1));
        scanf("%d",&newnode->data);
        if (head==NULL){
            head=newnode;

        }
        else{
            temp=head;
            while (temp->next!=NULL){
                temp=temp->next;

            }
            temp->next=newnode;

        }
    }

}



void linkedlisttraversal(struct node *ptr)
{
    while (ptr!=NULL){
        printf("element : %d\n",ptr->data);
        ptr= ptr->next;
    }

}

//insertion of first element

struct node *insertionatfirst(struct node *head,int data){
    struct node *ptr= (struct node*)malloc(sizeof(struct node));
    ptr->next= head;
    ptr->data=data;
    return ptr;
}

//inserting elements at any index

struct node *insertionatindex(struct node *head,int data, int index){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    struct node *p=head;

    int i=0;

    while (i!=index-1){
        p= p->next;
        i++;
    }

    ptr->data=data;
    ptr->next=p->next;
    p->next= ptr;
    return head;    
}

//inserting element at the end of the linked list

struct node *insertionatend(struct node *head,int data){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    struct node *p=head;
    while (p->next!=NULL){
        p=p->next;

    }

    p->next=ptr;
    ptr->next=NULL;
    return head;

}

//insertion after a node

struct node * insertionafternode(struct node *head,struct node *prevnode,int data){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;

    ptr->next=prevnode->next;
    prevnode->next=ptr;
    
    return head;


}

//deleting the first node of the linked list

struct node *deletefirst(struct node *head){
    struct node *ptr=head;
    head= head->next;
    free(ptr);
    return head;

}

//deleting the element at a patrticular index
struct node *deleteatindex(struct node *head,int index){
    struct node *p=head;
    struct node *q= head->next;
    for (int i=0;i<index-1;i++){
        p=p->next;
        q=q->next;

    }

    p->next = q->next;
    free(q);
    return head;

}

//deleting the last element

struct node *deleteatlast(struct node *head){
    struct node *p=head;
    struct node *q=head->next;
    while (q->next!=NULL){
        p=p->next;
        q=q->next;

    }
    p->next= NULL;
    free(q);

    return head;
}

//deleting the element with a given value in the linked list

struct node *deletethevalue(struct node *head,int value){
    struct node *p=head;
    struct node *q= head->next;
    while (q->data!=value & q->next!=NULL){
        p=p->next;
        q= q->next;

    }

    if (q->data==value){
        p->next= q->next;
        free(q);

    }

}

int main()
{
    create();

    printf("linked list before traversal is:\n");
    linkedlisttraversal(head);
    head=insertionatfirst(head,56);
    //head=insertionatindex(head,56,3);
    //head=insertionatend(head,99);
    //head=insertionafternode(head,third,45);
    //head=deletefirst(head);
    //head=deleteatindex(head,2);
    //head=deletethevalue(head,71);
    printf("\nlinked list after traversal is:\n");
    linkedlisttraversal(head);
    return 0;



}
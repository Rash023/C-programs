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
    int n,val=0;
    int count=0;
    printf("enter no of nodes you want:");
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("enter value of the %d node:",(i+1));
        scanf("%d",&val);
        newnode->data=val;
        newnode->next=NULL;
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

void linkedlisttraversal(){
    struct node *ptr=head;
    while (ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;

    }
}


struct node *insertatfirst(struct node *head,int data){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->next=head;
    ptr->data=data;
    return ptr;

}


int main()
{
    create();
    linkedlisttraversal();
    head=insertatfirst(head,4);
    linkedlisttraversal();


}
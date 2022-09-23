#include <stdio.h>
#include <stdlib.h>


struct node
{
    int data;
    struct node *next,*prev;

};

struct node *head,*newnode,*temp=NULL;

//creating doubly linked list
void create()
{
    int n,val=0;
    printf("enter the length of the linkedlist:");
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("enter element %d of the linkedlist:",(i+1));
        scanf("%d",&val);
        newnode->data=val;
        newnode->next=NULL;
        newnode->prev=NULL;
        if (head==NULL){
            head=temp=newnode;
        }

        else{
            temp->next=newnode;
            temp->prev=temp;
            temp=newnode;


        }
    }
}

//displaying doubly linked list
void display(){
    struct node *it=head;
    while (it!=NULL){
        printf("%d\n",it->data);
        it=it->next;


    }
}


int main()
{
    create();
    display();
    
}
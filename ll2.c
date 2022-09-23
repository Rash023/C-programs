#include <stdio.h>
#include <stdlib.h>


struct node
{
    int data;
    struct node *next;

};

struct node *head=NULL,*newnode,*temp=NULL;

//creating the linked list
void create()
{
    int n;
    printf("enter the length of the linkedlist:");
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter %d element\n",(i+1));
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if (head==NULL){
            head=newnode;

        }
        else
        {
            temp=head;
            while (temp->next!=NULL){
                temp=temp->next;

            }
            temp->next=newnode;

        }

    }
}


//displaying the linked list
void display()
{
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


#include <stdio.h>
#include <stdlib.h>
#define SIZE 100



struct queue
{
    int front,rear;
    int arr[SIZE];

};


//creating a queue
struct queue *create()
{
    struct queue *q=(struct queue *)malloc(sizeof(struct queue));
    q->front=0;
    q->rear=-1;
    return q;

}


//checking if the queue is empty
int isempty(struct queue *t)
{
    return t->rear==-1;

}

//checking if the queue is full
int isfull(struct queue *it)
{
    return it->rear==SIZE-1;

}


//removing elements from the queue
int dequeue(struct queue *q)
{
    if (isempty(q))
    {
        return -1;

    }

    else
    {
        return q->arr[q->front++];

    }
}


//inserting elements to the queue
void enqueue(struct queue *it,int val)
{
    if (isfull(it))
    {
        printf("cannot insert %d queue is full",val);


    }
    else{
        it->arr[++it->rear]=val;

    }

}


//displaying elements of the queue
void display(struct queue *t)
{
    if (t->rear==-1)
    {
        printf("queue is full");


    }
    else{
        for (int i=t->front;i<=t->rear;i++)
        {
            printf("%d\n",t->arr[i]);

        }
        printf("\n");

    }
}




int main()
{
    struct queue *q=create();
    int data,choice,ans;
    while (1)
    {
        printf("enter your choice:");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                printf("enter data to insert in queue:");
                scanf("%d",&data);
                enqueue(q,data);
                break;
            case 2:
                ans=dequeue(q);
                ans!=-1? printf("dequeued element is %d\n",ans) : printf("queue is empty\n");
                break;
            case 3:
                display(q);
                break;
            case 4:
                isfull(q) ? printf("queue is full\n") : printf("queue is not full\n");
                break;
            case 5:
                isempty(q) ? printf("queue is empty\n") : printf("queue is not empty\n");
                break;
            case -1:
                exit(1);


        }
    }
    return 0;

}
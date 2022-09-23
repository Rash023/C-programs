#include <stdio.h>
#include <stdlib.h>



struct stack
{
    int size;
    int top;
    int *arr;
};

//checking if the stack is empty
int isEmpty(struct stack *p)
{
    if (p->top==-1){
        return 1;

    }
    return 0;
}


//checking if the stack is full
int isFull(struct stack *ptr)
{
    if (ptr->top==ptr->size-1){
        return 1;

    }
    return 0;
}


//inserting element into the stack
int push(struct stack *it,int val)
{
    if (isFull(it)){
        printf("STACK OVERFLOW!, %d cannot be pushed",val);

    }

    else
    {
        it->top++;
        it->arr[it->top]=val;

    }
}


//deleting a item from the stack
int pop(struct stack *ptr)
{
    if (isEmpty(ptr)){
        printf("UNDERFLOW!,the stack is empty\n");

    }

    else{
        int val=0;
        val=ptr->arr[ptr->top];
        ptr->top--;
        printf("%d element deleted succesfully\n",val);


    }
}

//returning the top value of the stack
int peek(struct stack *p,int i)
{
    int arrayind=p->top-i+1;
    if (arrayind<0)
    {
        printf("not a valid position for the stack\n");
        return -1;
    }

    else{
        return p->arr[arrayind];


    }

}



int main()
{
    struct stack *st=(struct stack*)malloc(sizeof(struct stack));
    int n;
    printf("enter the size of the stack:");
    scanf("%d",&n);
    st->size=n;
    st->top=-1;
    st->arr=(int *)malloc(st->size*sizeof(int));
    push(st,14);
    push(st,15);
    push(st,16);
    push(st,17);
    printf("items added succesfully\n");
    for (int j=1;j<=st->top;j++){
        printf("the value at position %d is %d\n",j,peek(st,j));


    }



    return 0;

    


}

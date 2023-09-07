# include <stdio.h>
# include <stdlib.h>
struct stack{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack * ptr){
    if(ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack * ptr){
    if(ptr->top == (ptr->size)-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, int data)
{
    if(isFull(ptr))
    {
        printf("Stack overflow...\nCould not push %d to the stack.\n",data);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = data;
    }
}

int pop(struct stack *ptr)
{
    if(isEmpty(ptr))
    {
        printf("Stack Underflow...\n");
        return -1;
    }
    else
    {
        int x = ptr->arr[ptr->top];
        ptr->top = (ptr->top)-1;
        return x;
    }
}
int peek(struct stack *sp, int i)
{
    int arrInd = sp->top-i+1;
    if(arrInd < 0 || i > sp->size)
    {
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else
    {
        return sp->arr[arrInd];
    }
}

int stackTop(struct stack *sp)
{
    return sp->arr[sp->top];
}

int stackBottom(struct stack *sp)
{
    return sp->arr[0];
}
int main()
{
    
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 5;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size*sizeof(int));
    
    push(sp,46);
    push(sp,546);
    push(sp,48);
    push(sp,36);
    push(sp,454);
    push(sp,85);
    
    printf("Stack top = %d\n",stackTop(sp));
    printf("Stack bottom = %d",stackBottom(sp));
    return 0;
}
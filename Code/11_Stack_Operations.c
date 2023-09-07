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
        printf("Stack overflow...\nCould not push %d to the stack.",data);
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
int main()
{
    struct stack *sp;
    sp->size = 5;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size*sizeof(int));
    printf("Stack has been created successfully...");
    printf("\nBefore Pushing, Is Empty = %d",isEmpty(sp));
    printf("\nBefore Pushing, Is Full = %d\n",isFull(sp));
    push(sp,46);
    push(sp,546);
    push(sp,48);
    push(sp,36);
    push(sp,454);
    push(sp,85);
    printf("\nAfter pushing, Is Empty = %d",isEmpty(sp));
    printf("\nAfter pushing, Is Full = %d\n",isFull(sp));
    while(sp->top != -1)
    {
        printf("Popped %d from stack.\n",pop(sp));
    }
    pop(sp);
    
    printf("After popping, Is Empty = %d",isEmpty(sp));
    printf("\nAfter popping, Is Full = %d\n",isFull(sp));
    return 0;
}
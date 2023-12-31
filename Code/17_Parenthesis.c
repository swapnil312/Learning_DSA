# include <stdio.h>
# include <stdlib.h>
# include <string.h>
struct stack{
    int size;
    int top;
    char *arr;
};

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
void push(struct stack *ptr, char data)
{
    if(isFull(ptr))
    {
        printf("Stack overflow...\nCould not push %c to the stack.",data);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = data;
    }
}

char pop(struct stack *ptr)
{
    if(isEmpty(ptr))
    {
        printf("Stack Underflow...\n");
        return -1;
    }
    else
    {
        char x = ptr->arr[ptr->top];
        ptr->top = (ptr->top)-1;
        return x;
    }
}




int parenthesis(char *exp)
{
     
    struct stack * sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size*sizeof(char));
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '(')
        {
            push(sp,'(');
        }
        else if(exp[i] == ')')
        {
            if(isEmpty(sp))
            {
                return 0;
            }
            pop(sp);
        }
    }
    if(isEmpty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
int main()
{
    char *exp = "()(@#$76)";
    if (parenthesis(exp))
    {
        printf("The parenthesis is matching.");
    }
    else
    {
        printf("The parenthesis is not matching.");
    }
    
    return 0;
}
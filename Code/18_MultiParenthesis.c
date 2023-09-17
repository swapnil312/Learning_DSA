# include <stdio.h>
# include <stdlib.h>
# include <string.h>
struct stack{
    int size;
    int top;
    char *arr;
};

char stackTop(struct stack *sp)
{
    return sp->arr[sp->top];
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

int match(char a, char b)
{
    if((a == '{' && b == '}')||(a == '(' && b == ')')||(a == '[' && b == ']'))
    {
        return 1;
    }
    else{
        return 0;
    }
}


int parenthesis(char *exp)
{
    
    struct stack * sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size*sizeof(char));
    char popped_ch;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(sp,exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if(isEmpty(sp))
            {
                return 0;
            }
            popped_ch = pop(sp);
            if(!match(popped_ch,exp[i]))
            {
                return 0;
            }
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
    char *exp = "(98+{65)*/(6]-54)";
    if (parenthesis(exp))
    {
        printf("The parenthesis is balanced.");
    }
    else
    {
        printf("The parenthesis is not balanced.");
    }
    
    return 0;
}
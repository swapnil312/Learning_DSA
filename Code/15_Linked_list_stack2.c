# include <stdio.h>
# include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct Node *top = NULL;

int isEmpty(struct Node * top)
{
    if(top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Node * top)
{
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    if(p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

struct Node* push(struct Node *top, int x)
{
    if(!isFull(top))
    {
        struct Node *n = (struct Node*)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
    else
    {
        printf("Stack Overflow ...\n");
    }
}

int pop(struct Node *tp)
{
    if(!isEmpty(tp))
    {
        struct Node *n = tp;
        top = tp->next;
        int x = n->data;
        free(n);
        return x;

    }
    else
    {
        printf("Stack Underflow ...\n");
        return -1;
    }
}

void linkedListTraversal(struct Node * ptr)
{
    while(ptr != NULL)
    {
        printf("Data = %d\n",ptr->data);
        ptr = ptr->next;
    }
}

int main(){
    
    linkedListTraversal(top);
    top = push(top, 54);
    top = push(top, 67);
    linkedListTraversal(top);
    printf("Element1 : %d\n",pop(top));
    printf("Element2 : %d\n",pop(top));

    
    linkedListTraversal(top);
    return 0;
}
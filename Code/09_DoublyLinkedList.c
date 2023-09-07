# include <stdio.h>
# include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};
void frwrdTraversal(struct Node *ptr)
{
    do
    {
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    }
    while(ptr != NULL);
}

void bckwrdTraversal(struct Node *ptr)
{
    do
    {
        printf("%d\t",ptr->data);
        ptr = ptr->prev;
    }
    while(ptr != NULL);
}
int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *end = (struct Node *)malloc(sizeof(struct Node));

    head->prev = NULL;
    head->data = 14;
    head->next = second;

    second->prev = head;
    second->data = 78;
    second->next = third;

    third->prev = second;
    third->data = 34;
    third->next = end;

    end->prev = third;
    end->data = 45;
    end->next = NULL;   
    printf("Forward Traversal...\n");
    frwrdTraversal(head); 
    printf("\nBackward Traversal...\n");
    bckwrdTraversal(end);
    return 0;
}
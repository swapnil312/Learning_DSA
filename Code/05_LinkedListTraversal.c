# include <stdio.h>
# include <stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};
void linkedListTraversal(struct Node * ptr)
{
    while(ptr != NULL)
    {
        printf("Data = %d\n",ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    head->data = 7;
    head->next = second;
    second->data = 10;
    second->next = third;
    third->data = 45;
    third->next = fourth;
    fourth->data = 985;
    fourth->next = NULL;
    linkedListTraversal(head);
    return 0;
}
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
struct Node * deleteFirst(struct Node * head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
struct Node * deleteAtIndex(struct Node * head, int index)
{
    struct Node *p = head;
    struct Node *ptr;
    int i = 0;
    while(i != index-1)
    {
        p = p->next;
        i++;
    }
    ptr = p->next;
    p->next = ptr->next;
    free(ptr);
    
    return head;
}
struct Node * deleteAtLast(struct Node * head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->next != NULL)
    {
        p = p->next;
        q = q->next;

    }
    
    p->next = NULL;
    free(q);
    
    return head;
}
struct Node * deleteNodeWithValue(struct Node * head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->data!=value && q->next!=NULL)
    {
        p = p->next;
        q = q->next;

    }
    if(q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    else
    {
        printf("Node with value %d not found..\n",value);
    }
    return head;
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
    head->data = 4;
    head->next = second;
    second->data = 3;
    second->next = third;
    third->data = 8;
    third->next = fourth;
    fourth->data = 5;
    fourth->next = NULL;
    printf("Linked List before deletion.\n");
    linkedListTraversal(head);
    // head = deleteFirst(head);
    // head = deleteAtIndex(head, 1);
    // head = deleteAtLast(head);
    head = deleteNodeWithValue(head,30);
    printf("Linked List after deletion.\n");
    linkedListTraversal(head);
    return 0;
}
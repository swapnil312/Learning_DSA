# include <stdio.h>
# include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void linkedListTraversal(struct Node * ptr)
{
    while(ptr != NULL)
    {
        printf("Data = %d\n",ptr->data);
        ptr = ptr->next;
    }
}
struct Node * insertatFirst(struct Node *head, int data)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;

}
struct Node * insertatIndex(struct Node *head, int data, int index)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head;
    int i = 0;
    while(i != index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = NULL;
    p->next = ptr;
    return head;
    
}
struct Node * insertatEnd(struct Node *head, int data)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p;
    p = head;
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}
struct Node * insertafterNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;
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
    head->data = 7;
    head->next = second;
    second->data = 10;
    second->next = third;
    third->data = 45;
    third->next = fourth;
    fourth->data = 985;
    fourth->next = NULL;
    // linkedListTraversal(head);
    // head = insertatFirst(head,312);
    // head = insertatIndex(head,24,2);
    printf("\nLinked list before insertion\n");
    linkedListTraversal(head);
    // head = insertatEnd(head,3152);
    head = insertafterNode(head, third, 677);
    printf("\nLinked list after insertion\n");
    linkedListTraversal(head);
    return 0;
}
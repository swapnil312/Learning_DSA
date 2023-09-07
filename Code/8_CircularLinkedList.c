# include <stdio.h>
# include <stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};
void linkedListTraversal(struct Node * head)
{
    struct Node * ptr;
    struct Node * p;
    ptr = head;
    p = head;
    printf("Data = %d\n",ptr->data);
    ptr = ptr->next;
    do
    {
        printf("Data = %d\n",ptr->data);
        ptr = ptr->next;
    }
    while(ptr != p);
}
struct Node * insertAtFirst(struct Node *head, int data)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head->next;
    while(p->next != head)
    {
        p = p->next;
    }
    ptr->data = data;
    ptr->next = head;
    p->next = ptr;
    head = ptr;    
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
    
    fourth->next = head;
    head = insertAtFirst(head,56);

    linkedListTraversal(head);
    return 0;
}
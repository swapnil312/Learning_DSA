# include <stdio.h>
# include <stdio.h>
# include <stdlib.h>

struct circularQueue
{
    int size;
    int f;
    int r;
    int *arr;
};
int isFull(struct circularQueue *q)
{
    if(((q->r+1)%q->size) == q->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct circularQueue *q)
{
    if(q->r == q->f )
    {
        
       
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(struct circularQueue *q, int val)
{
    if(isFull(q))
    {
        printf("Can't enqueue %d, override condition...\n",val);
    }
    else
    {
        printf("Enqueued element %d\n",val);
        q->r = ((q->r)+1)%q->size;
        q->arr[q->r] = val;
        
    }    
}

int dequeue(struct circularQueue *q)
{
    int a = -1;
    if(isEmpty(q))
    {
        printf("Can't dequeue, underride condition...\n");
        
    }
    else
    {
        q->f = (q->f+1)%q->size;
        a = q->arr[q->f];
        
        
    }
    return a;    
}

int main()
{
    struct circularQueue q;
    q.size = 4;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size*sizeof(int));
    if(isEmpty(&q))
    {
        printf("Queue is empty.\n");
    }
    if(isFull(&q))
    {
        printf("Queue is full.\n");
    }
    enqueue(&q,78);
    enqueue(&q,28);
    enqueue(&q,98); 
    enqueue(&q,99);
    enqueue(&q,28); 
    if(isEmpty(&q))
    {
        printf("Queue is empty.\n");
    }
    if(isFull(&q))
    {
        printf("Queue is full.\n");
    }
    
    
    printf("Dequeued value = %d\n",dequeue(&q));
    printf("Dequeued value = %d\n",dequeue(&q));
    printf("Dequeued value = %d\n",dequeue(&q));
    printf("Dequeued value = %d\n",dequeue(&q));
    
    
    
    if(isEmpty(&q))
    {
        printf("Queue is empty.\n");
        
    }
    if(isFull(&q))
    {
        printf("Queue is full.\n");
    }

    enqueue(&q,43);
    enqueue(&q,87);
    enqueue(&q,34); 
    enqueue(&q,93);

    if(isEmpty(&q))
    {
        printf("Queue is empty.\n");
        
    }
    if(isFull(&q))
    {
        printf("Queue is full.\n");
    }
    return 0;
}

# include <stdio.h>
# include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};
int isFull(struct queue *q)
{
    if(q->r == (q->size)-1 )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct queue *q)
{
    if(q->r == q->f )
    {
        
        q->r = q->f = -1;    //This statement is written because after dequeueing everyhting q->r = q->f = size-1 ==> satisfies both isEmpty and isFull condition. So after queue becomes empty q->r = q->f = -1 is done...
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(struct queue *q, int val)
{
    if(isFull(q))
    {
        printf("Can't enqueue %d, override condition...\n",val);
    }
    else
    {
        q->r = (q->r)+1;
        q->arr[q->r] = val;
        
    }    
}

int dequeue(struct queue *q)
{
    int a = -1;
    if(isEmpty(q))
    {
        printf("Can't dequeue, underride condition...\n");
        
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
        
        
    }
    return a;    
}

int main()
{
    struct queue q;
    q.size = 4;
    q.f = q.r = -1;
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
    return 0;
}
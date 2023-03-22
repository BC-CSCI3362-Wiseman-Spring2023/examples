#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "bbq.h"

bbq *init_queue()
{
    bbq *q = (bbq *)malloc(sizeof(bbq));
    if (q == NULL)
    {
        perror("malloc");
        exit(1);
    }

    // start at slot 0
    q->next_item = 0;
    q->next_free = 0;

    // create the lock
    if (pthread_mutex_init(&q->lock, NULL) != 0)
    {
        perror("pthread_mutex_init");
        exit(1);
    }

    // create the condition vars
    if (pthread_cond_init(&q->item_enqueued, NULL) != 0)
    {
        perror("pthread_cond_init");
        exit(1);
    }
    if (pthread_cond_init(&q->item_dequeued, NULL) != 0)
    {
        perror("pthread_cond_init");
        exit(1);
    }

    return q;
}

void enqueue(bbq *q, int value)
{
    // grab the lock, block until it's available
    if (pthread_mutex_lock(&q->lock) != 0)
    {
        perror("pthread_mutex_lock");
        pthread_exit(NULL);
    }

    // if the queue is full, block until a spot opens
    while (q->next_free - q->next_item == QUEUE_SLOTS)
    {
        //printf("queue full\n");
        if (pthread_cond_wait(&q->item_dequeued, &q->lock) != 0)
        {
            perror("pthread_cond_wait");
            pthread_exit(NULL);
        }
    }

    // here, we know the queue is not full and we hold the lock
    q->queue[q->next_free % QUEUE_SLOTS] = value;
    q->next_free += 1;

    // signal that an item has been added
    if (pthread_cond_signal(&q->item_enqueued) != 0)
    {
        perror("pthread_cond_signal");
        pthread_exit(NULL);
    }

    // release the lock
    if (pthread_mutex_unlock(&q->lock) != 0)
    {
        perror("pthread_mutex_unlock");
        pthread_exit(NULL);
    }
}

int dequeue(bbq *q)
{
    // grab the lock, block until it's available
    if (pthread_mutex_lock(&q->lock) != 0)
    {
        perror("pthread_mutex_lock");
        pthread_exit(NULL);
    }

    // if the queue is empty, block until an item is added
    while (q->next_item == q->next_free)
    {
        //printf("queue empty\n");
        if (pthread_cond_wait(&q->item_enqueued, &q->lock) != 0)
        {
            perror("pthread_cond_wait");
            pthread_exit(NULL);
        }
    }

    // here, we know that the queue is not empty and we hold the lock
    int value = q->queue[q->next_item % QUEUE_SLOTS];
    q->next_item += 1;

    // signal that an item has been removed
    if (pthread_cond_signal(&q->item_dequeued) != 0)
    {
        perror("pthread_cond_signal");
        pthread_exit(NULL);
    }

    // release the lock
    if (pthread_mutex_unlock(&q->lock) != 0)
    {
        perror("pthread_mutex_unlock");
        pthread_exit(NULL);
    }

    return value;
}

void cleanup_queue(bbq *q)
{
    if (q->next_item != q->next_free)
    {
        printf("Warning, destroying non-empty queue!\n");
    }

    // cleanup the lock
    if (pthread_mutex_destroy(&q->lock) != 0)
    {
        perror("pthread_mutex_destroy");
        exit(1);
    }

    // cleanup the condition vars
    if (pthread_cond_destroy(&q->item_enqueued) != 0)
    {
        perror("pthread_cond_destroy");
        exit(1);
    }
    if (pthread_cond_destroy(&q->item_dequeued) != 0)
    {
        perror("pthread_cond_destroy");
        exit(1);
    }

    free(q);
}

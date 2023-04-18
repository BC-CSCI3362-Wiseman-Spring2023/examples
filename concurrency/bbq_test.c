#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "bbq.h"

#define NUM_PRODS 4
#define NUM_CONS 4

// the "tasks" are the numbers 0 to NUM_TASKS-1
#define NUM_TASKS 1000

typedef struct _thread_args {
    bbq *q;
    int id;
} thread_args;

// function for each thread that adds data to the queue
void *producer(void *arg)
{
    // get the arguments from the main thread
    thread_args *targs = (thread_args *)arg;

    // divide tasks as equally as possible across threads
    int min_tasks_per_thread = NUM_TASKS / NUM_PRODS;
    int extra_tasks = NUM_TASKS % NUM_PRODS;

    int my_start_task = min_tasks_per_thread * targs->id;
    int my_num_tasks = min_tasks_per_thread;
    if (extra_tasks > targs->id)
    {
        my_start_task += targs->id;
        ++my_num_tasks;
    }
    else
    {
        my_start_task += extra_tasks;
    }

    //printf("%d: %d,%d\n", targs->id, my_start_task, my_start_task+my_num_tasks-1);
    for (int i=my_start_task; i<my_start_task+my_num_tasks; ++i)
    {
        //printf("%d putting: %d\n", targs->id, i);
        enqueue(targs->q, i);
    }

    return NULL;
}

// function for each thread that removes data to the queue
void *consumer(void *arg)
{
    // get the arguments from the main thread
    thread_args *targs = (thread_args *)arg;

    // have to allocate heap memory for the return value
    // don't forget to free in main()!
    int *my_total = (int *)malloc(sizeof(int));
    if (my_total == NULL)
    {
        return NULL;
    }
    *my_total = 0;

    // divide tasks as equally as possible across threads
    int my_num_tasks = NUM_TASKS / NUM_CONS;
    if (NUM_TASKS % NUM_CONS > targs->id)
    {
        ++my_num_tasks;
    }

    //printf("%d: %d\n", targs->id, my_num_tasks);
    for (int i=1; i<=my_num_tasks; ++i)
    {
        //*my_total += dequeue(targs->q);
        int value = dequeue(targs->q);
        //printf("%d got: %d\n", targs->id, value);
        *my_total += value;
    }

    return my_total;
}

int main(int argc, char *argv[])
{
    // make the queue
    bbq *q = init_queue();

    // make the producer arguments
    thread_args *prod_args = (thread_args *)malloc(NUM_PRODS*sizeof(thread_args));
    if (prod_args == NULL)
    {
        perror("malloc");
        exit(1);
    }

    // make the consumer arguments
    thread_args *con_args = (thread_args *)malloc(NUM_CONS*sizeof(thread_args));
    if (con_args == NULL)
    {
        perror("malloc");
        exit(1);
    }

    // track each producer thread ID
    pthread_t *prods = (pthread_t *)malloc(NUM_PRODS*sizeof(pthread_t));
    if (prods == NULL)
    {
        perror("malloc");
        exit(1);
    }

    // track each consumer thread ID
    pthread_t *cons = (pthread_t *)malloc(NUM_CONS*sizeof(pthread_t));
    if (cons == NULL)
    {
        perror("malloc");
        exit(1);
    }

    // start the producers
    for (int i=0; i<NUM_PRODS; ++i)
    {
        prod_args[i].q = q;
        prod_args[i].id = i;
        if (pthread_create(&prods[i], NULL, producer, &prod_args[i]) != 0)
        {
            perror("pthread_create");
            exit(1);
        }
    }

    // start the consumers
    for (int i=0; i<NUM_CONS; ++i)
    {
        con_args[i].q = q;
        con_args[i].id = i;
        if (pthread_create(&cons[i], NULL, consumer, &con_args[i]) != 0)
        {
            perror("pthread_create");
            exit(1);
        }
    }

    // wait on all producers to complete
    for (int i=0; i<NUM_PRODS; ++i)
    {
        if (pthread_join(prods[i], NULL) != 0)
        {
            perror("pthread_join");
            exit(1);
        }
    }

    // wait on all consumers and get their results
    int total = 0;
    for (int i=0; i<NUM_CONS; ++i)
    {
        int *res;
        if (pthread_join(cons[i], (void **)&res) != 0)
        {
            perror("pthread_join");
            exit(1);
        }
        total += *res;
        free(res);
    }

    // clean up
    free(prod_args);
    free(con_args);
    free(prods);
    free(cons);
    cleanup_queue(q);

    printf("Total final value: %i\n", total);

    return 0;
}

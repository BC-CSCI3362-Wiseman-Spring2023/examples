#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include <pthread.h>

// global variable that all threads will incremenet
int shared_counter;

// each thread runs this function
void *thread_main(void *arg)
{
    // the number of loops for this thread is passed in as an argument
    int num_loops = *((int *)arg);

    // increment the shared counter as indicated
    for (int i=0; i<num_loops; ++i)
    {
        ++shared_counter;
    }

    // exit this thread
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("usage: %s num_threads num_loops\n", basename(argv[0]));
        exit(1);
    }

    int num_threads = atoi(argv[1]);
    if (num_threads < 1)
    {
        printf("error: must have at least one thread\n");
        printf("usage: %s num_threads num_loops\n", basename(argv[0]));
        exit(1);
    }

    int num_loops = atoi(argv[2]);
    if (num_loops < 1)
    {
        printf("error: must do at least one loop\n");
        printf("usage: %s num_threads num_loops\n", basename(argv[0]));
        exit(1);
    }

    // initialize the shared count to zero before spawning threads
    shared_counter = 0;

    // track each thread ID
    pthread_t *tids = (pthread_t *)malloc(num_threads*sizeof(pthread_t));
    if (tids == NULL)
    {
        printf("out of memory!?\n");
        exit(1);
    }

    for (int i=0; i<num_threads; ++i)
    {
        // create the ith thread to run thread_mean(num_loops)
        if (pthread_create(&tids[i], NULL, thread_main, &num_loops) != 0)
        {
            perror("pthread_create");
            exit(1);
        }
    }

    for (int i=0; i<num_threads; ++i)
    {
        // wait on the ith thread to complete
        if (pthread_join(tids[i], NULL) != 0)
        {
            perror("pthread_join");
            exit(1);
        }
    }

    printf("Expected final value: %i\n", num_loops*num_threads);
    printf("Actual final value: %i\n", shared_counter);

    return 0;
}

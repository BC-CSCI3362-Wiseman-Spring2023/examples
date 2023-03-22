#define QUEUE_SLOTS 16

// blocking bounded queue of ints
typedef struct _bbq {
    /* state variables */

    // bounded queue
    int queue[QUEUE_SLOTS];

    // index of next available item
    int next_item;

    // index of next free slot
    int next_free; 

    /* synchronization variables */

    // lock the queue during all operations
    pthread_mutex_t lock;

    // condition var to know if an added has been added
    pthread_cond_t item_enqueued;

    // condition var to know if an added has been removed
    pthread_cond_t item_dequeued;
} bbq;

bbq *init_queue();
void enqueue(bbq *q, int value);
int dequeue(bbq *q);
void cleanup_queue(bbq *q);

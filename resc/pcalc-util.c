
#include <stdbool.h>

#include "pcalc-err.h"

/** Error code used for when access is attempted when queue is empty */
#define ERR_EMPTY_QUEUE 101
/** Error code used for when queue capacity is reached */
#define ERR_QUEUE_AT_CAPACITY 102

/** The maximum capacity of a queue */
#define QUEUE_CAP 16

typedef struct {            // technically a circular array-based queue, doesn't really circle back
    int head, tail, size;   // integer values for storing head and tail indeces, and the queue size
    long list[QUEUE_CAP];   // the array for storing queue values, in this case long signed integers
} queue;

void init_queue(queue* q) {
    q->head = 0;    // initialize the head index to 0
    q->tail = 0;    // initialize the tail index to 0
    q->size = 0;    // initialize the size to 0
}

queue new_queue() {
    queue q;        // declare a new queue
    init_queue(&q); // initialize the queue values
    return q;       // return the new queue
}

void enqueue(queue* q, long val) {
    // cannot enqueue more elements if the queue capacity is reached
    if (q->tail == QUEUE_CAP)
        escape(ERR_QUEUE_AT_CAPACITY);

    q->list[q->tail++] = val;   // set the value at the tail and increment the tail index
    q->size++;                  // increment the queue size
}

long dequeue(queue* q) {
    // cannot dequeue elements if the queue is empty
    if (q->size == 0)
        escape(ERR_EMPTY_QUEUE);

    q->size--;                  // decrement the queue size
    return q->list[q->head++];  // return the element at the head index, and increment the head index
}

long peek(queue q) {
    // cannot peek an element if the queue is empty
    if (q.size == 0)
        escape(ERR_EMPTY_QUEUE);

    return q.list[q.front];     // return the element at the head index
}

bool is_empty(queue q) {
    return q.size == 0;     // the queue is empty if it contains no items, i.e., the size is 0
}
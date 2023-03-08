
#include "pcalc-err.h"
#include "pcalc-opers.h"
#include "pcalc-util.h"

/** Error code used for when access is attempted when queue is empty */
#define ERR_EMPTY_QUEUE 101
/** Error code used for when queue capacity is reached */
#define ERR_QUEUE_AT_CAPACITY 102
/** Error code used for when too few arguments are on a queue for an operation type */
#define ERR_TOO_FEW_QUEUE_ARGS 103
/** Error code used for when too many arguments are on a queue for an operation type */
#define ERR_TOO_MANY_QUEUE_ARGS 104

void init_opqueue(opqueue *q) {
    q->head = 0;    // initialize the head index to 0
    q->tail = 0;    // initialize the tail index to 0
}

opqueue new_opqueue() {
    opqueue nq;        // declare a new queue
    init_opqueue(&nq); // initialize the queue values
    return nq;         // return the new queue
}

void enqueue(opqueue *q, long val) {
    // cannot enqueue more elements if the queue capacity is reached
    if (q->tail == QUEUE_CAP)
        escape(ERR_QUEUE_AT_CAPACITY);

    q->list[q->tail++] = val;   // set the value at the tail and increment the tail index
}

long dequeue(opqueue *q) {
    // cannot dequeue elements if the queue is empty
    if (!has_items(q))
        escape(ERR_EMPTY_QUEUE);

    return q->list[q->head++];  // return the element at the head index, and increment the head index
}

long peek(opqueue *q) {
    // cannot peek at an element if the queue is empty
    if (!has_items(q))
        escape(ERR_EMPTY_QUEUE);

    return q->list[q->head];     // return the element at the head index
}

int has_items(opqueue *q) {
    return q->tail - q->head;    // returns the number of items left in the queue (tail index - head index)
}

void monadic_op(opqueue *q, long (*op)(long)) {
    // cannot perform an operation if the queue is empty
    if (!has_items(q))
        escape(ERR_EMPTY_QUEUE);
    // cannot perform an operation if there are too many arguments on the queue
    else if (has_items(q) > 1)
        escape(ERR_TOO_MANY_QUEUE_ARGS);

    long n = dequeue(q);    // dequeue the sole operand

    init_opqueue(q);        // reinitialize the queue to be empty again
    enqueue(q, (op)(n));    // calculate the operation of the value, and enqueue the result
}

void dyadic_op(opqueue *q, long (*op)(long, long)) {
    // cannot perform an operation if the queue is empty
    if (!has_items(q))
        escape(ERR_EMPTY_QUEUE);
    // cannot perform an operation if there are not enough arguments on the queue
    else if (has_items(q) == 1)
        escape(ERR_TOO_FEW_QUEUE_ARGS);
    // cannot perform an operation if there are too many arguments on the queue
    else if (has_items(q) > 2)
        escape(ERR_TOO_MANY_QUEUE_ARGS);

    long a = dequeue(q);    // dequeue the first operand
    long b = dequeue(q);    // dequeue the second operand

    init_opqueue(q);        // reinitialize the queue to be empty again
    enqueue(q, (op)(a, b)); // calculate the operation of both values, and enqueue the result
}

void polyadic_op(opqueue *q, long (*op)(long, long)) {
    // cannot perform an operation if the queue is empty
    if (!has_items(q))
        escape(ERR_EMPTY_QUEUE);
    // cannot perform an operation if there are not enough arguments on the queue
    else if (has_items(q) == 1)
        escape(ERR_TOO_FEW_QUEUE_ARGS);

    long val = dequeue(q);   // initialize the value to operate on by dequeueing the first operand

    // while the queue still has items, keep dequeueing them and changing the value
    while (has_items(q))
        val = (op)(val, dequeue(q));

    init_opqueue(q);    // reinitialize the queue to be empty again
    enqueue(q, val);    // enqueue the newly-calculated value
}

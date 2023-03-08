
/** The maximum capacity of a queue */
#define QUEUE_CAP 16

/**
    An Operand Queue (opqueue for short), stores operands that come before the next operator, including
    the evaluation of the last operation performed at the front.
*/
typedef struct {            // technically a circular array-based queue, doesn't really circle back
    int head, tail;         // integer values for storing head and tail indeces
    long list[QUEUE_CAP];   // the array for storing queue values, in this case long signed integers
} opqueue;

/**
    Initializes an Operand Queue by resetting the head and tail indeces to 0.

    @param q reference to the queue to initialize
*/
void init_opqueue(opqueue *q);

/**
    Constructs a new Operand Queue with zeroed head and tail indeces, and an empty array
    to store operand values.

    @return a new empty Operand Queue
*/
opqueue new_opqueue();

/**
    Enqueues a value onto an Operand Queue, by assigning the value to the current tail index, 
    and then incrementing the tail index.

    @param q reference to the queue to enqueue onto
    @param val the value to enqueue
*/
void enqueue(opqueue *q, long val);

/**
    Dequeues the top value off of an Operand Queue, by fetching and returning the value
    currently at the head index, after incrementing the head index.

    @param q reference to the queue to dequeue from
    @return the value dequeued from the head index
*/
long dequeue(opqueue *q);

/**
    Returns the current value at the head index of an Operand Queue, does not affect
    the head index.

    @param q reference to the queue to peek on
    @return the current value at the head index
*/
long peek(opqueue *q);

/**
    Returns the difference between the tail and head indeces of an Operand Queue, giving 
    what is effectively the number of items left on the queue, where a value of zero indicates 
    that the queue is currently empty, i.e., the head and tail indeces are the same.

    @param q reference to the queue to check
*/
int has_items(opqueue *q);

/**
    Performs a monadic operation using whatever operand is currently on an Operand
    Queue, then resets the queue and enqueues the resulting value.

    @param q reference to the queue to operate on
    @param op reference to the operation to perform
*/
void monadic_op(opqueue *q, long (*op)(long));

/**
    Performs a monadic operation using whatever two operands are currently on an 
    Operand Queue, then resets the queue and enqueues the resulting value.

    @param q reference to the queue to operate on
    @param op reference to the operation to perform
*/
void dyadic_op(opqueue *q, long (*op)(long, long));

/**
    Performs a polyadic operation using whatever operands are currently on an 
    Operand Queue, then resets the queue and enqueues the resulting value.

    @param q reference to the queue to operate on
    @param op reference to the operation to perform
*/
void polyadic_op(opqueue *q, long (*op)(long, long));

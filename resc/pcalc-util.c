
#define QUEUE_CAP 16

typedef struct {
    int head, tail, size;
    long list[QUEUE_CAP];
} queue;


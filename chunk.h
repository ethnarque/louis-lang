#ifndef louis_chunk_h
#define louis_chunk_h

#include "common.h"
#include "memory.h"
#include "value.h"

typedef enum {
    OP_CONSTANT,
    OP_RETURN,
} OpCode;

typedef struct {
    int count;
    int capacity;
    uint8_t *code;
    int *lines;
    ValueArray constants;
} Chunk;

void initChuck(Chunk *chunk);
void freeChuck(Chunk *chunk);
void writeChuck(Chunk *chunk, uint8_t byte, int line);
int addConstant(Chunk *chunk, Value value);

#endif

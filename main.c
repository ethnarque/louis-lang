#include <stdlib.h>

#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"

int main(int argc, const char *argv[]) {
    initVM();

    Chunk chunk;
    initChuck(&chunk);

    int constant = addConstant(&chunk, 1.2);
    writeChuck(&chunk, OP_CONSTANT, 123);
    writeChuck(&chunk, constant, 123);

    writeChuck(&chunk, OP_RETURN, 123);
    disassembleChunk(&chunk, "test chunk");
    interpret(&chunk);
    freeVM();
    freeChuck(&chunk);
    return 0;
}

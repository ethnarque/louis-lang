#include <stdio.h>

#include "debug.h"
#include "value.h"

void disassembleChunk(Chunk *chuck, const char *name) {
    printf("== %s ==\n", name);

    for (int offset = 0; offset < chuck->count;) {
        offset = disassembleInstruction(chuck, offset);
    }
}

static int constantInstruction(const char *name, Chunk *chunk, int offset) {
    uint8_t constant = chunk->code[offset + 1];
    printf("%-16s %4d '", name, constant);
    printValue(chunk->constants.values[constant]);
    printf("'\n");
    return offset + 2;
}

static int simpleInstruction(const char *name, int offset) {
    printf("%s\n", name);
    return offset + 1;
}

int disassembleInstruction(Chunk *chuck, int offset) {
    printf("%04d ", offset);

    if (offset > 0 && chuck->lines[offset] == chuck->lines[offset - 1]) {
        printf("   | ");
    } else {
        printf("%4d ", chuck->lines[offset]);
    }

    uint8_t instruction = chuck->code[offset];
    switch (instruction) {
    case OP_CONSTANT:
        return constantInstruction("OP_CONSTANT", chuck, offset);
    case OP_RETURN:
        return simpleInstruction("OP_RETURN", offset);
    default:
        printf("Unknown opcode %d\n", instruction);
        return offset + 1;
    }
}

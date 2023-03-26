#ifndef FILE_READ_H
#define FILE_READ_H

#include <stdbool.h>
#include "../coding/coding.h"

typedef struct readChar {
    int character;
    char code[256];
} readChar;

extern long int last_pos;

int read_number();
void read_char(int chars_number, readChar **nodes);
void read_tree(int nodes_number, huffman_node **nodes);
char *read_code();

#endif
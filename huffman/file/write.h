#ifndef FILE_WRITE_H
#define FILE_WRITE_H

#include <stdbool.h>
#include "../coding/coding.h"

bool writeHuffmanData(huffman_node *tree, character **nodes ,const char *message, int char_number);
bool print_chars(character **node);
void print_huffman_tree(huffman_node *root, FILE *file);

#endif
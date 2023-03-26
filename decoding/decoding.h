#ifndef DECODING_DECODING_H
#define DECODING_DECODING_H

#include "../file/read.h"
#include "../coding/coding.h"


char *generateDecoding();
huffman_node* rebuild_huffman_tree(huffman_node **treeNodes, int *current_node);
char *decode_message(char *code, huffman_node *root);
void freeTree1(huffman_node **tree);
void freechars(readChar **nodes);


#endif
#ifndef DECODING_DECODING_H
#define DECODING_DECODING_H

#include "../file/read.h"
#include "../coding/coding.h"

/**
 * Generate the decoding process
 * 
 * @return char* the original message after decoding the huffman code
 */
char *generateDecoding();

/**
 * Rebuild the huffman tree
 * 
 * @param treeNodes array that store the nodes readed from the file
 * @param current_node to know the current node
 * @return huffman_node* 
 */
huffman_node* rebuild_huffman_tree(huffman_node **treeNodes, int *current_node);

/**
 * Decode the huffman code to a human readble text
 * 
 * @param code the huffman code
 * @param root the root node of the huffman tree
 * @return char* the original message
 */
char *decode_message(char *code, huffman_node *root);

/**
 * free the huffman tree built in this file
 * 
 * 
 */
void freeTree1(huffman_node **tree);

/**
 * free the list of the charcters
 * 
 * 
 */
void freechars(readChar **nodes);


#endif
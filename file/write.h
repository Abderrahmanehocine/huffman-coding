#ifndef FILE_WRITE_H
#define FILE_WRITE_H

#include <stdbool.h>
#include "../coding/coding.h"

/**
 * Generate the writes of the Huffman data to a file, including the Huffman tree, the characters
 * and their corresponding Huffman codes, and the message to be encoded.
 *
 * @param tree The root node of the Huffman tree.
 * @param nodes An array of character nodes containing their corresponding Huffman codes.
 * @param message The message to be encoded.
 * @param char_number The number of unique characters in the message.
 * */
bool writeHuffmanData(huffman_node *tree, character **nodes ,const char *message, int char_number);

/**
 * Write the characters and there huffman code in a file
 * 
 * @param node the array that stored the list of characters
 */
bool print_chars(character **node);

/**
 * Write the nodes of the huffman tree in a file
 * 
 * @param root the root node of the huffman tree
 * @param file file pointer
 */
void print_huffman_tree(huffman_node *root, FILE *file);

#endif
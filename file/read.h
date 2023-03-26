#ifndef FILE_READ_H
#define FILE_READ_H

#include <stdbool.h>
#include "../coding/coding.h"

typedef struct readChar {
    int character;
    char code[256];
} readChar;

extern long int last_pos;

/* 
 * This function reads the number from file. 
 * The number describes the number of lines to be used in the file.
 */
int read_number();

/**
 * Reads the characters and their Huffman codes from a file.
 *
 * This function reads `chars_number` lines from the file, where each line contains
 * a character and its corresponding Huffman code, separated by a space. The readChar
 * struct is used to store each character and its code as a node in a linked list.
 *
 * @param chars_number The number of lines to read from the file.
 * @param nodes A pointer to a linked list of readChar nodes to store the characters and codes.
 * @return void
 */
void read_char(int chars_number, readChar **nodes);

/**
 * Reads a Huffman tree from a file and stores the nodes in an array.
 *
 * @param nodes_number the number of nodes in the Huffman tree
 * @param nodes an array of pointers to Huffman nodes
 */
void read_tree(int nodes_number, huffman_node **nodes);

/**
 * This function reads the Huffman code from a file and returns it as a string.
 *
 * @return A pointer to the string containing the Huffman code.
 */
char *read_code();

#endif
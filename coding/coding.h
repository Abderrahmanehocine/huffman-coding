#ifndef CODING_CODING_H
#define CODING_CODING_H

#define MAX_TEXT_SIZE 1024
#define ASCII_SIZE 256
#define MAX_BITS 9 

extern int charachter_number;
extern int node_number;

typedef struct huffman_node{
    int character;
    int freqency;
    struct huffman_node *left_child;
    struct huffman_node *right_child;
} huffman_node;

typedef struct character{
    int character;
    char code[MAX_BITS];
} character;
/**
 * build the huffman tree
 * 
 * @param freq array that contain the freqeuncy of each character
 * @return huffman_node* the root node of the tree
 */
huffman_node *build_huffman_tree(int *freq);
/**
 * Create the code of each character 
 * 
 * @param root the root node of the huffman tree
 * @param char_nodes array that store the character
 */
void Create_code(huffman_node *root, character **char_nodes, char *code);

/**
 * Create the huffman code
 * 
 * @param text 
 * @param nodes 
 * @return char* 
 */
char *Create_message_code(char *text, character **nodes);

/**
 * free the memory
 * 
 * @param root 
 */
void freeTree(huffman_node* root);
void freeTree2(character **nodes);

#endif
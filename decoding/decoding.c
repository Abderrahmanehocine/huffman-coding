#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "decoding.h"


char *generateDecoding(){
    int chars_number = read_number();

    readChar *charsNodes[chars_number];
    read_char(chars_number, charsNodes);

    int node_number = read_number();

    huffman_node *treeNodes[node_number];
    read_tree(node_number, treeNodes);
    int current_node = 0;
    huffman_node *root = rebuild_huffman_tree(treeNodes, &current_node);
    
    char *code = read_code();

    char *message = decode_message(code,root);

    freechars(charsNodes);
    freeTree1(treeNodes);

    return message;
}

huffman_node* rebuild_huffman_tree(huffman_node **treeNodes, int *current_node) {
    if (*current_node < 0) 
        return NULL;
    
    huffman_node *node = treeNodes[(*current_node)++];
    
    if (node->character != -1)
        //Leaf node
        return node;
    
    // Build left child
    node->left_child = rebuild_huffman_tree(treeNodes, current_node);
    
    // Build right child
    node->right_child = rebuild_huffman_tree(treeNodes, current_node);
    
    return node;
}

char *decode_message(char *code, huffman_node *root) {
    huffman_node *temp1 = root;
    char message[256] = "";
    int i = 0;

    while (code[i] != '\0') {
        if (code[i] == '0') {
            temp1 = temp1->left_child;
        } else if (code[i] == '1') {
            temp1 = temp1->right_child;
        } else {
            // Invalid character in code
            return NULL;
        }
        if (temp1->character != -1) {
            char character = (char)temp1->character;
            strncat(message, &character, 1);
            
            temp1 = root; // Reset temp1 to root for next code
        }
        i++;
    }
    message[i] = '\0';

    return strdup(message);
}


void freeTree1(huffman_node **tree){
    int i;
    for(i=0 ; i<charachter_number ; i++)
        free(tree[i]);
}

void freechars(readChar **nodes){
    int i;
    for(i=0 ; i<charachter_number ; i++)
        free(nodes[i]);
}
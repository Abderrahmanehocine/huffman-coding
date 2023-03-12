// Huffman coding program (the program didn't finish yet)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_SIZE 1024
#define ASCII_SIZE 256

typedef struct huffman_node{
    int character;
    int freqency;
    struct huffman_node *left_child;
    struct huffman_node *right_child;
} huffman_node;

huffman_node *build_huffman_tree(int *freq){
    huffman_node *tree_node[ASCII_SIZE];
    int node_index = 0;

    int i;
    for(i = 0 ; i < ASCII_SIZE ; i++){
        if(freq[i] > 0){
            huffman_node *node = (huffman_node*)malloc(sizeof(huffman_node));
            node->character = i;
            node->freqency  = freq[i];
            node->left_child= NULL;
            node->right_child= NULL;
            tree_node[node_index++] = node;
        }
    }

    while(node_index > 1){
        int min_index1 = -1;
        int min_index2 = -2;
        for(i=0 ; i < node_index ; i++){
            if(min_index1 == -1 || tree_node[i]->freqency < tree_node[min_index1]->freqency){
                min_index2 = min_index1;
                min_index1 = i;
            }
            else if(min_index2 == -1 || tree_node[i]->freqency < tree_node[min_index2]->freqency)
                min_index2 = i;
        }

        huffman_node *new_node = (huffman_node*)malloc(sizeof(huffman_node));
        new_node->character = -1;
        new_node->freqency  = tree_node[min_index1]->freqency + tree_node[min_index2]->freqency;
        new_node->left_child = tree_node[min_index1];
        new_node->right_child = tree_node[min_index2];

        if (min_index1 < min_index2) {
            tree_node[min_index1] = new_node;
            tree_node[min_index2] = tree_node[node_index-1];
        } else {
            tree_node[min_index2] = new_node;
            tree_node[min_index1] = tree_node[node_index-1];
        }
        node_index--;
    }

    // Return the root of the tree
    return tree_node[0];
}

void freeTree(huffman_node* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left_child);
    freeTree(root->right_child);
    free(root);
}

int main(int *argc, char **argv){

    int i;

    // Scan the text from the user
    char text[MAX_TEXT_SIZE];
    printf("Enter the text: ");
    scanf("\n");
    scanf("%[^\n]", text);

    // Calculate the freqeuncy of each char
    int freq[ASCII_SIZE] = {0};
    for (i = 0; i < strlen(text); i++) {
        freq[(int)text[i]]++;
    }

    // Build the huffman tree
    huffman_node *root = build_huffman_tree(freq);
    freeTree(root);
    printf("\n\n End of the prog\n");

    return 0;
}
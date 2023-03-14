#include <stdio.h>
#include "write.h"

bool writeHuffmanData(huffman_node *tree, character **nodes ,const char *message, int char_number) {
    FILE *file = fopen("huffman_data.txt","w");
    if(file == NULL){
        perror("Error opening file in writeHuffmanData()\n");
        return 1;
    }

    // Write the number of characters
    fprintf(file,"%d\n", char_number);
    fclose(file);
    
    if(print_chars(nodes)){
        perror("Error writing characters in the file in print_char()\n");
        return 1;
    }

    file = fopen("huffman_data.txt","a+");
    if(file == NULL){
        perror("Error openinh file of printing huffman tree");
        return 1;
    }

    fprintf(file,"%d\n",node_number+charachter_number);
    print_huffman_tree(tree,file);
    fprintf(file,"%s",message);
    fclose(file);
    return 0;
}

bool print_chars(character **node){
    FILE *fileName = fopen("huffman_data.txt","a+");
    if(fileName == NULL){
        perror("Error opening file in print_char()\n");
        return 1;
    }
    int i;
    for(i=0 ; i<ASCII_SIZE ; i++){
        if(node[i] == NULL)
            continue;
        else{
            fprintf(fileName,"%d  %s\n", node[i]->character, node[i]->code);
        }
    }
    fclose(fileName);
    return 0;
}

void print_huffman_tree(huffman_node *root, FILE *file){
    if (root == NULL) 
        return;
    fprintf(file,"(%d,%d)\n", root->character,root->freqency);
    print_huffman_tree(root->left_child, file);
    print_huffman_tree(root->right_child, file);
}
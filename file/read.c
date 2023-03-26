#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read.h"

long int last_pos = 0;

int read_number(){
    FILE *file = fopen("file/huffman_data.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(0);
    }

    fseek(file, last_pos, SEEK_SET);

    char line[100];
    int number = 0;

    fgets(line, sizeof(line), file);
    sscanf(line,"%d",&number);

    last_pos = ftell(file);
    fclose(file);

    return number;
}

void read_char(int chars_number, readChar **nodes) {
    FILE *file = fopen("file/huffman_data.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(0);
    }

    char line[256];

    fseek(file, last_pos, SEEK_SET);

    int i;
    for(i=0 ; i < chars_number ; i++){
        fgets(line, sizeof(line), file);
        nodes[i] = (readChar*)malloc(sizeof(readChar));
        sscanf(line,"%d %s",&nodes[i]->character,nodes[i]->code);
    }

    last_pos = ftell(file);
    fclose(file);
}

void read_tree(int nodes_number, huffman_node **nodes) {
    FILE *file = fopen("file/huffman_data.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(0);
    }

    char line[256];

    fseek(file, last_pos, SEEK_SET);

    int i;
    for(i=0 ; i < nodes_number ; i++){
        fgets(line, sizeof(line), file);
        nodes[i] = (huffman_node*)malloc(sizeof(huffman_node));
        sscanf(line, "(%d,%d)", &nodes[i]->character, &nodes[i]->freqency);
        nodes[i]->left_child = nodes[i]->right_child = NULL;
    }

    last_pos = ftell(file);
    fclose(file);
}

char *read_code(){
    FILE *file = fopen("file/huffman_data.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(0);
    }
    char line[256];

    fseek(file, last_pos, SEEK_SET);
    fgets(line, sizeof(line), file);

    fclose(file);

    return strdup(line);
}


#include <stdio.h>
#include <string.h>
#include "coding/coding.h"
#include "file/write.h"
#include "decoding/decoding.h"

int main(int argc, char **argv) {

    int i;

    // Scan the text from the user
    char text[MAX_TEXT_SIZE];
    printf("\n\nEnter the text: ");
    scanf("\n");
    scanf("%[^\n]", text);

    // Calculate the freqeuncy of each char
    int freq[ASCII_SIZE] = {0};
    for (i = 0; i < strlen(text); i++) {
        freq[(int)text[i]]++;
    }

    // Build the huffman tree
    huffman_node *root = build_huffman_tree(freq);
    huffman_node *head = root;

    // Create the code of each char in the message
    char code[MAX_BITS] = "";
    character *char_nodes[ASCII_SIZE];
    memset(char_nodes, 0, sizeof(char_nodes));
    Create_code(root, char_nodes, code);

    // Create the huffman code
    char *message = Create_message_code(text, char_nodes);

    printf("\n\n");


    // Print each character with his code
    for(i=0 ; i<ASCII_SIZE ; i++){
        if(char_nodes[i] == NULL)
            continue;
        else{
            printf("Character: %c  | Code: %s\n", char_nodes[i]->character, char_nodes[i]->code);
        }
    }

    // Write the charecters with there code and the huffman tree and the code of the message in a file
    writeHuffmanData(head, char_nodes, message, charachter_number);

    // Print the text entered by the user with the final code result
    printf("Code: %s\n\n\n", message);

    // Decode the code of the text to get the original message
    char *original_message = generateDecoding();
    printf("original message: %s\n",original_message);

    // Free the memory
    freeTree(root);
    freeTree2(char_nodes);

    return 0;
}
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
    
#define BUFSIZE 256
    
// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) { 
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "The specified file does not exist.\n");
        return -1;
    }
    fclose(file);

    char cmd[BUFSIZE] = "wc -c < ";
    strncat(cmd, argv[1], BUFSIZE - strlen(cmd) - 1);
    system(cmd);
}

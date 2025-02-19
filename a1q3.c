#include <stdio.h>
#include <stdlib.h>

#define BUFFSIZE 256
    
int read_file(const char *filename) {
    FILE* ptr = fopen(filename, "r");
    
    if (ptr == NULL) {
        printf("File cannot be opened.\n");
        return(-1);
    }
    
    char buff[BUFFSIZE];
    
    while (fgets(buff, BUFFSIZE, ptr) != NULL) {
        printf("%s", buff);
    }
    
    return 0; 
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    
    return read_file(argv[1]);
}

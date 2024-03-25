#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "read_id.h"
#include "structure.h"
#define MAX 1024
char* readAnimal(const char *file_path) {
    int id = read_id(); //reading animal's
    FILE *file = fopen(file_path, "r");
    char line[MAX];
    
    while (fgets(line, sizeof(line), file) != NULL) {
        int id;
        
        if (id == Animal_id) {
            char *content = malloc(strlen(line) + 1);
            strcpy(content, line);
            return content;
        }
    }

    fclose(file);
    return NULL;
}

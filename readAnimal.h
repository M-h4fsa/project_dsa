#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structure.h"
#define MAX 1024
char* readAnimal(const char *file_path, int id) {
    FILE *file = fopen(file_path, "r");
    char line[MAX];
    char *content = NULL;

    while (fgets(line, sizeof(line), file)) {
        int i=0,id_line=0;
        char ident[5];
        while (line[i]!=',')
        {
            ident[i] = line [i];
            i++;
        }
        ident[i] = '\0';
        id_line = atoi(ident);
        if (id_line==id)
        {
            content = malloc(strlen(line)+1);
            if (content)
            {
                strcpy(content, line);
            }
            
        }
        
    }
    fclose(file);
    return content;
}

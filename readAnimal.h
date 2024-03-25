#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "read_id.h"
#include "structure.h"
#define MAX 1024
char* readAnimal(const char *file_path) {
    int id = read_id(); //reading animal's id
    FILE *file = fopen(file_path, "r");
    char line[MAX];
    char *content = NULL;
    int i=0,id_line;
    char ident[5];
    while (fgets(line, sizeof(line), file) != NULL) {
        while (line[i]!=',' && line[i]!='\0' && i<sizeof(ident)- 1)
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

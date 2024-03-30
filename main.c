#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "readAnimal.h"
#include "choices.h"
#include "read_id.h"
#include "password.h"
#include "structure.h"
#define ANIMALSMAX 30

int main() {
    pass();
    const char *path="/home/hafsa/Animals_list.txt";
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        printf("Failed to open file\n");
        return 1;
    }
    animal animals[ANIMALSMAX]; //array: number of animals available (struct)
    int i = 0, day, year;
    char month[4];
    while (1) {
        int readCount = fscanf(file, "%d,%79[^,],%79[^,],%d,%f,%f,", &animals[i].ID, animals[i].name, animals[i].breed, &animals[i].quantity, &animals[i].weight, &animals[i].price);
        if (readCount == EOF) break; //Reaching End of file
        if (fscanf(file, "%2d%3s%4d,", &day, month, &year) == 3) { //3 fields assigned(dd-mmm-yyyy)
            //existent date
            animals[i].vax_date.day = day;
            strcpy(animals[i].vax_date.month, month);
            animals[i].vax_date.year = year;
        } else {
            //inexistent date
            fscanf(file, "%*s"); // Skip the "NA," using *
            animals[i].vax_date.day = 0;
            strcpy(animals[i].vax_date.month, "NA");
            animals[i].vax_date.year = 0;
        }
        i++;
        if (i >= ANIMALSMAX) break; //prevent overflow
    }
    fclose(file);
    return 0;
}
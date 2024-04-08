#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structures.h" 
void PopStruct(const char *path, animal *animals, int maxAnimals) {
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        printf("Failed to open file\n");
        return; // Exit if file can't be opened
    }

    int i = 0, day, year;
    char month[4];
    while (i < maxAnimals) {
        int readCount = fscanf(file, "%d,%79[^,],%79[^,],%d,%f,%f,", &animals[i].ID, animals[i].name, animals[i].breed, &animals[i].quantity, &animals[i].weight, &animals[i].price);
        if (readCount == EOF) break; // Reaching End of file

        if (fscanf(file, "%2d%3s%4d,", &day, month, &year) == 3) {
            animals[i].vax_date.day = day;
            strcpy(animals[i].vax_date.month, month);
            animals[i].vax_date.year = year;
        } else {
            fscanf(file, "%*s"); // Skip the "NA," using *
            animals[i].vax_date.day = 0;
            strcpy(animals[i].vax_date.month, "NA");
            animals[i].vax_date.year = 0;
        }
        i++;
    }
    fclose(file);
}
void DisplayAnimals(animal *animals, int size) {
    for (int i = 0; i < size; i++) {
        if (animals[i].ID == 0) break; //end of useful data at ID=0

        printf("ID: %d\n", animals[i].ID);
        printf("Name: %s\n", animals[i].name);
        printf("Breed: %s\n", animals[i].breed);
        printf("Quantity: %d\n", animals[i].quantity);
        printf("Weight: %.2f\n", animals[i].weight);
        printf("Price: %.2f\n", animals[i].price);
        printf("Vaccination Date: %d-%s-%d\n\n",
               animals[i].vax_date.day,
               animals[i].vax_date.month,
               animals[i].vax_date.year);
    }
}
//description:
//************
/*the Header "PopulateStruct" contains two important functions, which are:
1."PopStruct": a function used to populate the structure "animal" contained in the header "structures.h", it has a system of
parsing vaccination date which helps the user know which animal requires a vaccination date or not (NA case), and for that
we use a condition that will set the 'vax_date' to '00NA0000' as a way to know that the animal does not require a vaccination
date (NOT APPLICABLE) when the 'while' loop encounters 'NA' sign instead of a valid date.
2."DisplayAnimals": is a function related to "PopStruct", this one will use a simple 'for' loop to display all animals in the
data file according to their place in the structure "animal".*/
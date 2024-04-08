#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structures.h"
#define BUFFER_SIZE 1024
//Function to add an animal to the file
void addAnimalToFile(const char *filePath, animal newAnimal) {
    FILE *file = fopen(filePath, "a");
    if (file != NULL) {
        fprintf(file, "%d,%s,%s,%d,%.2f,%.2f,%d%s%d\n",
                newAnimal.ID, newAnimal.name, newAnimal.breed, newAnimal.quantity,
                newAnimal.weight, newAnimal.price, newAnimal.vax_date.day,
                newAnimal.vax_date.month, newAnimal.vax_date.year);
        fclose(file);
    } else {
        perror("Unable to open file for appending");
    }
}
//Function to delete an animal to the file
void deleteAnimalFromFile(const char* filename, const char* id) {
    FILE *srcFile, *tempFile;
    char buffer[BUFFER_SIZE];
    char tempName[] = "tempfile.tmp";
    int idLen = strlen(id);

    // Open the original file for reading
    srcFile = fopen(filename, "r");
    if (srcFile == NULL) {
        perror("Error opening source file");
        return;
    }

    // Open the temporary file for writing
    tempFile = fopen(tempName, "w");
    if (tempFile == NULL) {
        perror("Error opening temporary file");
        fclose(srcFile);
        return;
    }

    // Read from source file and write to temp file, skip the line with the given ID
    while (fgets(buffer, BUFFER_SIZE, srcFile) != NULL) {
        // Check if the beginning of the line matches the ID
        if (strncmp(buffer, id, idLen) != 0 || buffer[idLen] != ',') {
            fputs(buffer, tempFile);
        }
    }

    // Close the open files
    fclose(srcFile);
    fclose(tempFile);

    // Delete the original file
    if (remove(filename) != 0) {
        perror("Error deleting original file");
        return;
    }

    // Rename the temporary file to the original file name
    if (rename(tempName, filename) != 0) {
        perror("Error renaming temporary file");
        return;
    }
}
//function to edit a line by a given id
void editLineById(const char* filename, const char* id, const char* newContent) {
    FILE *srcFile, *tempFile;
    char buffer[BUFFER_SIZE];
    char tempName[] = "tempfile.tmp";
    int idLen = strlen(id);

    // Open the original file for reading
    srcFile = fopen(filename, "r");
    if (srcFile == NULL) {
        perror("Error opening source file");
        return;
    }

    // Open the temporary file for writing
    tempFile = fopen(tempName, "w");
    if (tempFile == NULL) {
        perror("Error opening temporary file");
        fclose(srcFile);
        return;
    }

    // Read from source file and write to temp file, replace the line with the given ID
    while (fgets(buffer, BUFFER_SIZE, srcFile) != NULL) {
        if (strncmp(buffer, id, idLen) == 0 && buffer[idLen] == ',') {
            //write new content instead of the original line
            fprintf(tempFile, "%s\n", newContent);
        } else {
            // Copy line as is
            fputs(buffer, tempFile);
        }
    }

    // Close the open files
    fclose(srcFile);
    fclose(tempFile);

    // Delete the original file
    if (remove(filename) != 0) {
        perror("Error deleting original file");
        return;
    }

    // Rename the temporary file to the original file name
    if (rename(tempName, filename) != 0) {
        perror("Error renaming temporary file");
        return;
    }
}
//description:
//************
/*"CRUD", which stands for "create, read, update, delete", is a name chosen for this header file to allow it to run crucial functions
in the program. The functions are:
1."addAnimalToFile": this function will first open the data file in "append" mode before using the "fprintf" function to fill the 
structure "animal", it will then add these informations at the bottom of the data file, which results to the addition of a new animal
to our animals list.
2."deleteAnimalFromFile": the function will open the temporary file in writing mode after reading the data file given, it will then
use a loop to write the content of the data file in the temporary file, while making sure to skip the line that contains the ID 
wished to be deleted, and after closing the files and finishing the operation, we make sure to delete the previous data file and rename
the temporary file the same name as the data file deleted, thus it will result to having a new file that does not contain
the animal we wished to delete.
3."editLineById": this function works the same way as "deleteAnimalFromFile", although, the extra step is when the loop finally ends 
up finding the ID contained in the line wished to edit, the program asks for the new content that will replace that line, and for that,
we'll copy the new content inputted (located in a buffer) to the location of the line desired to edit.*/
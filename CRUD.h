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
/**/
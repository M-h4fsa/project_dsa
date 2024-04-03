#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structures.h"
#include "PopulateStruct.h"
#include "CRUD.h"
#include "ReadFromUsr.h"
#define ANIMALSMAX 30

int main() {
    const char *path="/home/hafsa/Animals_list.txt";
    PopStruct(path); // Assuming this populates a structure with file data

    int operation;
    printf("Select an operation:\n");
    printf("1. Add a new animal\n");
    printf("2. Delete an animal\n");
    printf("3. Edit an animal\n");
    printf("Your choice: ");
    scanf("%d", &operation);
    while(getchar() != '\n'); // Clear the input buffer

    switch(operation) {
        case 1: { // Add
            animal newAnimal = ReadUsr(); // Read animal details from user
            addAnimalToFile(path, newAnimal); // Add the new animal to the file
            printf("New animal added.\n");
            break;
        }
        case 2: { // Delete
            const char *idToDelete = readIdFromUser(); // Read ID to delete from user
            deleteAnimalFromFile(path, idToDelete); // Delete the animal from the file
            printf("Entry with ID %s has been deleted.\n", idToDelete);
            free((void*)idToDelete); // Free dynamically allocated memory
            break;
        }
        case 3: { // Edit
            const char *idToEdit = E_readIdFromUser(); // Read ID to edit from user
            const char *newContent = readNewContentFromUser(); // Read new content for the line
            editLineById(path, idToEdit, newContent); // Edit the line in the file
            printf("Entry with ID %s has been edited.\n", idToEdit);
            free((void*)idToEdit); // Free dynamically allocated memory for idToEdit
            free((void*)newContent); // Free dynamically allocated memory for newContent
            break;
        }
        default:
            printf("Invalid operation selected.\n");
    }

    return 0;
}


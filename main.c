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
    PopStruct(path);
    /*animal newAnimal = ReadUsr();
    const char *idToDelete = readIdFromUser();
    addAnimalToFile(path, newAnimal);
    readIdFromUser(idToDelete, sizeof(idToDelete));
    deleteAnimalFromFile(path, idToDelete);
    printf("Entry with ID %s has been deleted.\n", idToDelete); */
    const char *idToEdit = E_readIdFromUser(); // Example ID to edit
    // Example new content for the line. Ensure it matches your data format.
    const char *newContent = readNewContentFromUser();
    editLineById(path, idToEdit, newContent);
    printf("Entry with ID %s has been edited.\n", idToEdit);
    return 0;
}

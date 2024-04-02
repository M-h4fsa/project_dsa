#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structures.h"
#include "PopulateStruct.h"
#include "CRUD.h"
#define ANIMALSMAX 30

int main() {
    const char *path="/home/hafsa/Animals_list.txt";
    PopStruct(path);
    /*animal newAnimal = {131, "THING", "thing", 5, 25.0, 26700.00, {7, "sep", 2022}};
    addAnimalToFile(path, newAnimal);*/

    /*const char* idToDelete = "125"; // The ID you want to delete
    deleteAnimalFromFile(path, idToDelete);
    printf("Entry with ID %s has been deleted.\n", idToDelete);*/

    /*const char* idToEdit = "103"; // Example ID to edit
    // Example new content for the line. Ensure it matches your data format.
    const char* newContent = "103,thing,THING,90,10.9,4450.50,15apr2024,";

    editLineById(path, idToEdit, newContent);

    printf("Entry with ID %s has been edited.\n", idToEdit);*/
    return 0;
}
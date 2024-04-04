#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structures.h"
animal ReadUsr(void)
{
    animal newAnimal;
    char buffer[256]; // Buffer for fgets

    printf("Enter ID: ");
    scanf("%d", &newAnimal.ID);
    while(getchar() != '\n'); // Clear the input buffer

    printf("Enter name: ");
    fgets(newAnimal.name, sizeof(newAnimal.name), stdin);
    newAnimal.name[strcspn(newAnimal.name, "\n")] = 0; // Remove newline character

    printf("Enter breed: ");
    fgets(newAnimal.breed, sizeof(newAnimal.breed), stdin);
    newAnimal.breed[strcspn(newAnimal.breed, "\n")] = 0;

    printf("Enter quantity: ");
    scanf("%d", &newAnimal.quantity);
    while(getchar() != '\n'); // Clear the input buffer

    printf("Enter weight: ");
    scanf("%f", &newAnimal.weight);
    while(getchar() != '\n'); // Clear the input buffer

    printf("Enter price: ");
    scanf("%f", &newAnimal.price);
    while(getchar() != '\n'); // Clear the input buffer

    // For vaccination date, assuming you want the month as a string and day, year as integers
    printf("Enter vaccination day: ");
    scanf("%d", &newAnimal.vax_date.day);
    while(getchar() != '\n'); // Clear the input buffer

    printf("Enter vaccination month (3 characters): ");
    fgets(buffer, sizeof(buffer), stdin);
    strncpy(newAnimal.vax_date.month, buffer, 3); // Copy only first 3 characters
    newAnimal.vax_date.month[3] = '\0'; // Ensure null termination

    printf("Enter vaccination year: ");
    scanf("%d", &newAnimal.vax_date.year);
    while(getchar() != '\n'); // Clear the input buffer
    return newAnimal;
}
const char* readIdFromUser(void) {
    char buffer[256]; // Temporary buffer to read the input
    printf("Enter the ID to delete: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove the newline character

    // Allocate memory for the returned string
    char* id = malloc(strlen(buffer) + 1); // +1 for the null terminator
    if (id != NULL) {
        strcpy(id, buffer); // Copy the string from buffer to dynamically allocated memory
    }

    return id; // Return the dynamically allocated memory holding the ID
}
const char* readNewContentFromUser(void) {
    printf("Enter the new content (format: ID,name,breed,quantity,weight,price,date,): \n");

    char buffer[1024]; // Adjust the buffer size based on expected input length
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove the newline character if present

    // Allocate memory for the returned string
    char* content = malloc(strlen(buffer) + 1); // +1 for the null terminator
    if (content != NULL) {
        strcpy(content, buffer); // Copy the string from buffer to dynamically allocated memory
    }

    return content; // Return the dynamically allocated memory holding the content
}
const char* E_readIdFromUser(void) {
    char buffer[256]; // Temporary buffer to read the input
    printf("Enter the ID to edit: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove the newline character

    // Allocate memory for the returned string
    char* id = malloc(strlen(buffer) + 1); // +1 for the null terminator
    if (id != NULL) {
        strcpy(id, buffer); // Copy the string from buffer to dynamically allocated memory
    }

    return id; // Return the dynamically allocated memory holding the ID
}
//description:
//************
/*"ReadFromUser" header file contains 4 important functions, these functions are used to fetch user input to perform a
specific task.
1."ReadUsr" is a function that will allow the user to enter all the necessary informations to fill an array (newAnimal) of type
"animal" (which is a struct) to then use this array as parameters for the function "addAnimalToFile" from header "CRUD" (see main()).
2."readIdFromUser" is a function that we will use its return value as a parameter for the function "deleteAnimalFromFile" from header
 "CRUD" (see main()) to allow it to perform its task, this function returns a value of type const char* (id).
3."readNewContentFromUser" is a function used to read a string of informations (about the animal) and gives a free restriction service
for the user to allow him/her to edit the animal's informations as long as they respect the format and delimiter position (the comma).
4."E_readIdFromUser" is basically the exact copy of "readIdFromUser" except for one change: instead of asking for an id to delete
it asks for an id to edit.
NOTE: these functions are very necessary for the functions in "CRUD.h" header file to work*/
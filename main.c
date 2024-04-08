#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "PopulateStruct.h"
#include "CRUD.h"
#include "ReadFromUsr.h"
#include "readAnimal.h"
#include "read_id.h"
#include "password.h"
#include "invoice.h"
#define ANIMALSMAX 100

int main() {
   printf("\n🔐 Please enter the password to access the Pet&Co. Animal Management System: ");
    if (!checkPassword()) {
        printf("Incorrect password. Exiting program.\n");
        return 1;
    }
    const char *path = "/home/hafsa/Animals_list.txt";
    animal animals[ANIMALSMAX];
    PopStruct(path,animals,ANIMALSMAX);

    printf("\n=============================================\n");
    printf("  Welcome to Pet&Co. Animal Management System\n");
    printf("=============================================\n\n");

    int operation;
    do {
        printf("\nPlease select an operation to perform:\n");
        printf("  1. Add a new animal 🐾\n");
        printf("  2. Delete an animal 🗑️\n");
        printf("  3. Edit an animal's information 🖊️\n");
        printf("  4. Print an animal's information by ID 🔍\n");
        printf("  5. Display all animals 📚\n");
        printf("  6. Process animal purchases and generate invoice 📝\n");
        printf("  7. Exit 🚪\n");
        printf("\nEnter your choice (1-7): ");
        scanf("%d", &operation);
        while (getchar() != '\n'); // Clear the input buffer
        printf("\nYou selected option %d\n", operation);
        switch (operation) {
            case 1: {
                printf("\n-- Add New Animal --\n");
                animal newAnimal = ReadUsr();
                addAnimalToFile(path, newAnimal);
                printf("\n✅ New animal added successfully!\n");
                break;
            }
            case 2: {
                printf("\n-- Delete An Animal --\n");
                const char *idToDelete = readIdFromUser();
                deleteAnimalFromFile(path, idToDelete);
                printf("\n🗑️ Entry with ID %s has been deleted.\n", idToDelete);
                break;
            }
            case 3: {
                printf("\n-- Edit an Animal's Information --\n");
                const char *idToEdit = E_readIdFromUser();
                const char *newContent = readNewContentFromUser();
                editLineById(path, idToEdit, newContent);
                printf("\n🖊️ Animal with ID %s has been updated successfully.\n", idToEdit);
                break;
            }
            case 4: {
                printf("\n-- Print an Animal's Information by ID --\n");
                int id = read_id();
                char *content = readAnimal(path, id);
                if (content != NULL) {
                    printf("\n🔍 id %d content:\n%s\n", id, content);
                } else {
                    printf("\n❌ Failed to read the file or animal ID does not exist.\n");
                }
                break;
            }
            case 5: {
                printf("\n-- Display All Animals --\n");
                DisplayAnimals(animals, ANIMALSMAX);
                printf("\n");
                break;
            }
            case 6: {
                printf("\n-- Process Animal Purchases and Generate Invoice --\n");
                processAnimalPurchases(path);
                printf("\n❗NOTE: make sure to edit your file after purchases (operation 3)❗\n");
                break;
            }
            case 7:
                printf("\n🚪 Exiting Pet&Co.\n");
                break;
            default:
                printf("\n❌ Invalid choice. Please enter a number between 1 and 7.\n");
        }
    } while (operation != 7);
    printf("\n🐾 Thank you for using Pet&Co Animal Management System. Goodbye! 🐾\n");
    return 0;
}




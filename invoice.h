#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#define N 80
#define MAX_ANIMALS 30 
void processAnimalPurchases(const char* filePath) {
    FILE *file;
    char line[256];
    animal available_animals[MAX_ANIMALS];
    int animal_count = 0;

    file = fopen(filePath, "r");
    if (!file) {
        perror("Error: Failed to open the file. Please make sure the file path is correct.");
        return;
    }

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%d,%[^,],%[^,],%*d,%f,%f,%d,%3s,%d", 
               &available_animals[animal_count].ID, 
               available_animals[animal_count].name, 
               available_animals[animal_count].breed, 
               &available_animals[animal_count].weight, 
               &available_animals[animal_count].price, 
               &available_animals[animal_count].vax_date.day, 
               available_animals[animal_count].vax_date.month, 
               &available_animals[animal_count].vax_date.year);
        animal_count++;
        if(animal_count >= MAX_ANIMALS) break;
    }

    fclose(file);
    //displaying invoice
    printf("\n🐾 Welcome to the Pet&Co. Purchase System! 🐾\n");
    printf("----------------------------------------------\n\n");

    int num_purchases;
    float total_cost = 0.0;

    printf("🛒 How many different types of animals would you like to purchase? ");
    scanf("%d", &num_purchases);

    printf("\n");
    animal purchases[num_purchases];
    for(int i = 0; i < num_purchases; i++) {
        int id, quantity;
        printf("🐶 For animal #%d, enter the ID and quantity (e.g., 101 2): ", i + 1);
        scanf("%d %d", &id, &quantity);

        for(int j = 0; j < animal_count; j++) {
            if(available_animals[j].ID == id) {
                purchases[i] = available_animals[j];
                purchases[i].quantity = quantity;
                total_cost += purchases[i].price * purchases[i].quantity;
                break;
            }
        }
    }

    printf("\n--- Your Invoice ---\n\n");
    for(int i = 0; i < num_purchases; i++) {
        printf("%d x %s (%s) @ %.2f da each\n", 
               purchases[i].quantity, 
               purchases[i].name, 
               purchases[i].breed, 
               purchases[i].price);
        printf("Subtotal for this item: %.2f da\n\n", 
               purchases[i].price * purchases[i].quantity);
    }
    printf("Total cost of all purchases: %.2f da\n", total_cost);
    printf("-----------------------------\n");
    printf("🐾 Thank you for your purchase! 🐾\n");
}
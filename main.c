#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "readAnimal.h"
#include "choices.h"
#include "read_id.h"
#include "structure.h"
#define ANIMALSMAX 30
int main()
{
    const char *path="/home/hafsa/Animals_list.txt";
    //int ch = choices();
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        printf("Failed to open file\n");
        return 1;
    }
    animal animals[30]; //number of animals available
    char tempDate[10]; // Temporary buffer for date
    int i = 0;
    while(fscanf(file, "%d,%79[^,],%79[^,],%d,%f,%f,%9s,\n", &animals[i].ID, animals[i].name, animals[i].breed, &animals[i].quantity, &animals[i].weight, &animals[i].price, tempDate) != EOF) {
        if (strcmp(tempDate,"NA") == 0) { //in case there is no vaccination date

            animals[i].vax_date.day = 0; // Indicating inexistant date
            strcpy(animals[i].vax_date.month,"NA");
            animals[i].vax_date.year = 0;
        } else {
            // indicating exitent date
            sscanf(tempDate, "%2d%3s%4d", &animals[i].vax_date.day, animals[i].vax_date.month, &animals[i].vax_date.year);
        }
        i++;
    }
    fclose(file);
    printf("%d\n",i);
        for (int j = 0; j < i; j++) {
        printf("\nID: %d, Name: %s, Breed: %s, Quantity: %d, Weight: %.2f, Price: %.2f", animals[j].ID, animals[j].name, animals[j].breed, animals[j].quantity, animals[j].weight, animals[j].price);
        if (strcmp(animals[j].vax_date.month, "NA") != 0) {
            printf(", Vax Date: %02d%s%d\n", animals[j].vax_date.day, animals[j].vax_date.month, animals[j].vax_date.year);
        } else {
            printf(", Vax Date: None\n");
        }
        printf("\n______________________________________________________________________________________________________________________\n");
    }
    return 0;
    /*if(ch==1)
    {
    int id = read_id(); //reading animal's id
    char *content = readAnimal(path,id); //reading an element according to the id
    if(content != NULL)
    {
        printf("id content:\n%s\n",content);
    }else{
        printf("failed to read the file.\n");
    }
    }
    else if(ch==2)
    {

    char* animals_arr[ANIMALSMAX];
    for (int j = 0; j < ANIMALSMAX; j++) //filling the array of articles
    {
        animals_arr[j]=readAnimal(path,j+101);
    }
    printf("\n");
    for(int i=0;i<=ANIMALSMAX;i++) //printing out all elements
    {
        printf("Animal:%s\n", animals_arr[i]);
    }
    return 0;
    }*/
}
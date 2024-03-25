#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "read_id.h"
#include "readAnimal.h"
#include "choices.h"
#define ANIMALSMAX 30
int main()
{
    const char *path="/home/hafsa/Animals_list.txt";
    int ch = choices();
    if(ch==1)
    {
    int id = read_id(); //reading pet's id
    char *content = readAnimal(path, id); //reading an element according to the id
    if(content != NULL)
    {
        printf("id %d content:\n%s\n",id,content);
    }else{
        printf("failed to read the file.\n");
    }
    }
    else if(ch==2)
    {
    char* animals_arr[ANIMALSMAX];
    for (int i = 0; i < ANIMALSMAX; i++) //filling the array of articles
    {
        animals_arr[i]=readAnimal(path,i+1);
    }
    for(int i=0;i<ANIMALSMAX;i++) //printing out all elements
    {
        printf("Animal %d: %s\n", i + 1, animals_arr[i]);
    }
    return 0;
    }
}


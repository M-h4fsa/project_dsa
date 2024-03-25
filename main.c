#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "readAnimal.h"
#include "choices.h"
#include "read_id.h"
#define ANIMALSMAX 130
int main()
{
    const char *path="/home/hafsa/Animals_list.txt";
    int ch = choices();
    int id = read_id(); //reading animal's id
    if(ch==1)
    {
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
    for (int i = 101; i < ANIMALSMAX; i++) //filling the array of articles
    {
        animals_arr[i]=readAnimal(path,i+1);
    }
    for(int i=0;i<=ANIMALSMAX;i++) //printing out all elements
    {
        printf("Animal %d: %s\n", i + 1, animals_arr[i]);
    }
    return 0;
    }
}
#include <stdio.h>
int read_id()
{
    int n;
        printf("\n please enter your pet's id [starting from 101]:");
        scanf("%d",&n);
    return n;
}
//description:
//************
/*This basic function to read an integer is used to allow the user of the program to enter a specific integer
(starting from 101 as shown) using scanf,to then return it for a specific use (as a parameter for readAnimal function)*/
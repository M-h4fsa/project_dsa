#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structures.h"
#include "PopulateStruct.h"
#define ANIMALSMAX 30

int main() {
    const char *path="/home/hafsa/Animals_list.txt";
    PopStruct(path);
    return 0;
}
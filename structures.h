#include <string.h>
#include <stdlib.h>
#define N 80
#ifndef STRUCTURES_H
#define STRUCTURES_H
//vaccination date structure
    typedef struct
    {
      int day;
      char month[4];
      int year;
     }vaxdate;
//main structure: Animal structure
    typedef struct
    {
        int ID;
        char name[N];
        char breed[N];
        int quantity;
        float weight;
        float price;
        vaxdate vax_date;//element of type struct "vaxdate"
    }animal;
#endif // STRUCTURES_H

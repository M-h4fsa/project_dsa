#include <string.h>
#include <stdlib.h>
#define N 80
    typedef struct
    {
      int day;
      char month[4];
      int year;
     }vaxdate;
    typedef struct
    {
        int ID;
        char name[N];
        char breed[N];
        int quantity;
        float weight;
        float price;
        vaxdate vax_date;
    }animal;
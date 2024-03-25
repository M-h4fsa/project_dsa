#include <stdio.h>
int read_num()
{
    int n;
    do
    {
        printf("\n please enter your pet's id [101<id<130]:");
        scanf("%d",&n);
    } while ((n<101)||(n>130));
    return n;
}
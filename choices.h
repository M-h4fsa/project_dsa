#include<stdio.h>
int choices()
{
    int c;

     printf("in this program, you have the choice between two results\n1:display a line from your list\n2:display the whole list");
     printf("\nchoose a number: 1 or 2?");
     scanf ("%d",&c);

    return c;
}
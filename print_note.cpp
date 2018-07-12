
#include <stdio.h>

struct note
{
    char name[25];
    char surname[50];
    double phone;

    struct note *next; 
};
 
void print_note(struct note *nn)
{
    printf("\nName:    %s\n",nn->name);
    printf("Surname: %s\n", nn->surname);
    printf("Phone:   %7.0lf\n", nn->phone);
}
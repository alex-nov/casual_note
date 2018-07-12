#ifdef STRUCTNOTE
#define STRUCTNOTE

#include <stdio.h>

struct note
{
    char name[25];
    char surname[50];
    double phone;

    struct note *next; 
} *head;

// STRUCTNOTE
#endif /*STRUCTNOTE*/

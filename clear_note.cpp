#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "print_note.h"

struct note
{
    char name[25];
    char surname[50];
    double phone;

    struct note *next; 
};

extern struct note *head;

void clear_note()
{
    struct note * next_note;
    
    if(head == NULL)
        return;
    
    
    while(head != NULL)
    {
        next_note = head->next;
        free(head);
        head = next_note;
    }
}

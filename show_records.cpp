#include <stdio.h>
#include "print_note.h"

struct note
{
    char name[25];
    char surname[50];
    double phone;

    struct note *next; 
};

extern struct note *head;

int show_records()
{
    struct note *hhead = head;
    char c;
    
    if(hhead == NULL)
    {
        return 1;
    }
    
    while(hhead != NULL )
    {
        print_note(hhead);
        hhead = hhead->next;
    }
    printf("\n");
   
    return 0;
   
}
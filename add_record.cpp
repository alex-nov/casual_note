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

int  add_record()
{
    struct note *hhead;
    struct note *new_note;
    
    new_note = (struct note*)malloc(sizeof(struct note));
        
    printf("Enter name (25 symbols): \n");
    scanf("%s",new_note->name);
    
    printf("Enter surname (50 symbols): \n");
    scanf("%s",new_note->surname);
    
    printf("Enter phone (25 symbols): \n");
    scanf("%lf",&new_note->phone);
    
    new_note->next = NULL;
    
    if(head == NULL)
    {
        head = new_note;
        return 0;
    }
    else
    {
        hhead = head;
    }

    
    while(hhead->next != NULL)
    {
        hhead = hhead->next;
    }
   
    hhead->next = new_note;
    
    return 0;
}
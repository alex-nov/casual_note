#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct_note.h" 
#include "print_note.h"

struct note
{
    char name[25];
    char surname[50];
    double phone;

    struct note *next; 
};

extern struct note *head;

void delete_note()
{
    struct note *previous, *hhead;
    
    int input = 0;
    
    double search_phone = 0.0;
    char search_text[50];
    
    bool found = false;
    
    previous = hhead = head;
    
    printf("1 - Delete by name\n");
    printf("2 - Delete by surname\n");
    printf("3 - Delete by phone\n");
    printf("4 - cancel\n\n");
    
    scanf("%d",&input);
    
    if(input == 1 || input == 2)
    {
        printf("Enter value: ");
        scanf("%s",search_text);
    }
    else if(input == 3)
    {
        printf("Enter value: ");
        scanf("%lf",&search_phone);
    }
    else
    {
        return;
    }
    
    
    while(hhead != NULL)
    {
        switch(input)
        {
            case 1 : 
                
                if(strcmp (search_text, hhead->name) == 0)
                {
                    found = true;
                }
                break;
                
            case 2 :
                
                if(strcmp (search_text, hhead->surname) == 0)
                {
                    found = true;
                }
                break;
                
            case 3 :
                
                if(search_phone == hhead->phone)
                {
                    found = true;
                }
                break;
                
            default:
                
                break;
        }        
    
    
        if(found)
        {
            if(hhead == head)
            {
                head = head->next;
                previous = head;
            }
            else
            {
                previous->next = hhead->next;
            }
            printf("Deleting note: \n");
            print_note(hhead);
            free(hhead);
            
            hhead = previous->next;
            found = false;
            continue;
        }
        
   
        previous = hhead;
        hhead = hhead->next;  
    }
    
}
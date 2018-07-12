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

void search_notes()
{
    struct note * hhead = head;
    
    int input = 0;
    
    double search_phone = 0.0;
    char search_text[50];
    bool found = false;
    
    printf("1 - Search by name\n");
    printf("2 - Search by surname\n");
    printf("3 - Search by phone\n");
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
                    print_note(hhead);
                    found = true;
                }
                break;
                
            case 2 :
                
                if(strcmp (search_text, hhead->surname) == 0)
                {
                    print_note(hhead);
                    found = true;
                }
                break;
                
            case 3 :
                
                if(search_phone == hhead->phone)
                {
                    print_note(hhead);
                    found = true;
                }
                break;
                
            default:
                
                break;
        }
        
   
    
    hhead = hhead->next;  
    }
    
    printf("\n");
    if(!found)
    {
        printf("Not found!\n");
    }
    
}
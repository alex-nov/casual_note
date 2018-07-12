#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "add_record.h"
#include "clear_note.h"
#include "delete_note.h"
#include "print_note.h"
#include "search_notes.h"
#include "show_records.h"

struct note
{
    char name[25];
    char surname[50];
    double phone;

    struct note *next; 
};


struct note *head;


int main()
{
    int input_n = 0, ret = 0;
    char c;
    head = NULL;

    
    while(1)
    {
        system("clear");
        printf("Hello! It's casual notebook\n");
        printf("1 - Show all records\n");
        printf("2 - Add new record\n");
        printf("3 - Search records\n");
        printf("4 - Delete records\n");
        printf("5 - Exit\n\n");
        
        scanf("%d",&input_n);
       
        switch(input_n)
        {
            case 1 :
                
                ret = show_records();
                
                if(ret == 1)
                {
                    printf("NO records!\n\n");
                    
                    
                }
                else
                {
                    printf("\npress any key\n");
                    
                    c = getchar();
                    if(c = 0) c = getchar();
                }
                
                break;
                      
            case 2 :
                
                ret = add_record();
                break;
                
            case 3 :
                
                search_notes();
                break;                
            
            case 4 :
                
                delete_note();
                break;                
                
            case 5 :
                break;
                
            default:
                printf("Unknown command\n");
                break;
        }
        
        if(input_n == 5)
        {
            break;
        }
        
        sleep(3);
    }
    
    clear_note();
    
    return 0;
}

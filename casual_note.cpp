#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct note
{
    char name[25];
    char surname[50];
    double phone;

    struct note *next; 
};


struct note *head;


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
        printf("Name:    %s\n",hhead->name);
        printf("Surname: %s\n", hhead->surname);
        printf("Phone:   %7.0lf\n\n", hhead->phone);
        
        hhead = hhead->next;
    }
    printf("\n");
   
    return 0;
   
}


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

int main()
{
    int input_n = 0, ret = 0;
    char c;
    head = NULL;

    
    while(1)
    {
//         system("clear");
        printf("Hello! It's casual notebook\n");
        printf("1 - Show all records\n");
        printf("2 - Add new record\n");
        printf("5 - Exit\n\n");
        
        scanf("%d",&input_n);
       
        switch(input_n)
        {
            case 1 :
                
                ret = show_records();
                
                if(ret == 1)
                {
                    printf("NO records!\n\n");
                    
                    sleep(3);
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
                
            case 5 :
                break;
                
            default:
                printf("Unknown command\n");
                break;
        }
    
//         printf("%c\n",input_ch);
        
        if(input_n == 5)
        {
            break;
        }
    }
    
    clear_note();
    
    return 0;
}
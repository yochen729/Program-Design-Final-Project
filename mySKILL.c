#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mySKILL.h"

typedef struct basic_account* USER;
typedef struct Information* INFORMATION;

struct basic_account{ //personal information

    int total_money;
    char name[MAX_NAME],phone[MAX_PHONE],birth[MAX_DATE],email[MAX_EMAIL],password[MAX_PASSWORD];
    INFORMATION trade_record;
    USER next;
};
USER head = NULL;

struct Information{//single trade record
    int used_money;
    char trade_type[MAX_TYPE]; // deposit or withdrawal or transfer
    char date[MAX_DATE]; //  XXXX/XX/XX
    INFORMATION next;
};


// this function is for user.
void insert_user(char *name, char *phone, char *birth, char *email, char *password)
{
    if(head==NULL)
    {
        head = calloc(1, sizeof(struct basic_account));
        head->total_money = -1;
        strcpy(head->name, "default");
        strcpy(head->phone, "default");
        strcpy(head->birth, "default");
        strcpy(head->email, "default");
        strcpy(head->password, "default");
        head->trade_record = NULL;
        head->next = NULL;
    }
    USER new_user = calloc(1, sizeof(struct basic_account));
    new_user->total_money = 0;
    strcpy(new_user->name, name);
    strcpy(new_user->phone, phone);
    strcpy(new_user->birth, birth);
    strcpy(new_user->email, email);
    strcpy(new_user->password, password);
    new_user->trade_record = NULL;
    new_user->next = NULL;
    USER ptr;
    for(ptr = head; ptr->next; ptr = ptr->next){}
    ptr->next = new_user;
}

// this function isn't for user.
void insert_trade_record(char* user_name, int money, char* type)
{
    
}

// this function is for user.
// correct -> return TRUE,  incorrect -> return FALSE
int check_password(char* name, char* password)
{

}

void print_all_account()
{
    USER ptr;
    ptr = head;
    printf("name\tmoney\n");
    while(ptr)
    {
        ptr = ptr->next;
        printf("%s\t%d\n", ptr->name, ptr->total_money);
    }
}

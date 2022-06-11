#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mySEVER.h"
#include "mySKILL.h"

void build_account_sever()
{
    char name[MAX_NAME],phone[MAX_PHONE],birth[MAX_DATE],email[MAX_EMAIL],password[MAX_PASSWORD];
    char key[16];

    printf("/***********************************/\n");
    printf("/*         build a account         */\n");
    printf("/***********************************/\n");

    printf("If you want to back to home, enter \"quit\".\n");
    printf("If you want to build a account, enter \"continue\".\n");
    printf("your input:");
    scanf("%s", key);
    while(strcmp(key, "continue")!=0)
    {
        if(strcmp(key, "quit")==0) return;
        else printf("illegal input!!!\n");
        printf("If you want to back to home, enter \"quit\".\n");
        printf("If you want to build a account, enter \"continue\".\n");
        printf("your input:");
        scanf("%s", key);
    }
    
    printf("Please enter your name(account), phone, birthday, email, password.\n");
    printf("name(account):");
    scanf("%s", name);
    printf("phone:");
    scanf("%s", phone);
    printf("birthday():");
    scanf("%s", birth);
    printf("email:");
    scanf("%s", email);
    printf("password:");
    scanf("%s", password);
    printf("\nCheck for your account and password.\n");
    printf("account:%s\npassword:%s\n", name, password);
    printf("Enter \"OK\" to build your account.\n");
    printf("your input:");
    scanf("%s", key);
    while(strcmp(key, "OK")!=0)
    {
        printf("incorrect!!!\n");
        printf("your input:");
        scanf("%s", key);
    }
    insert_user(name, phone, birth, email, password);
    return;
}

void delete_account_sever()
{
    printf("/***********************************/\n");
    printf("/*        delete a account         */\n");
    printf("/***********************************/\n");
    return;
}

void view_account_sever()
{
    printf("/***********************************/\n");
    printf("/*   view all existing accounts    */\n");
    printf("/***********************************/\n");
    print_all_account();
    return;
}

void sort_account_sever()
{
    printf("/***********************************/\n");
    printf("/*        sort all accounts        */\n");
    printf("/***********************************/\n");
    return;
}

void manage_account_sever()
{
    int choice = 0;
    while(choice!=6)
    {
        printf("/***********************************/\n");
        printf("/*      Manage your own account    */\n");
        printf("/***********************************/\n");
        printf("1.Make a deposit\n");
        printf("2.Make a withdrawal\n");
        printf("3.Transfer money to other account\n");
        printf("4.List all trade record\n");
        printf("5.Modify personal information");
        printf("6.Back to home.\n");
        printf("Please enter your choice(1~6):");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                return;
            default:
                printf("illegal input!!!\n");
        }
    }
    return;
}

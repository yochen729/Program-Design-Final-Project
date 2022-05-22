#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mySEVER.h"

int main()
{
    int choice = 0;
    printf("This is a simple bank system,\nthe following are something you can do in this system:\n");
    while(choice!=6)
    {
        printf("/***********************************/\n");
        printf("/*              HOME               */\n");
        printf("/***********************************/\n");
        printf("1.Bulid a new account.\n");
        printf("2.Delete a account.\n");
        printf("3.View all existing accounts.\n");
        printf("4.Sort all accounts.\n");
        printf("5.Manage your own account.\n");
        printf("6.Quit this system.\n");
        printf("Please enter your choice(1~6):");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                build_account_sever();
                break;
            case 2:
                delete_account_sever();
                break;
            case 3:
                view_account_sever();
                break;
            case 4:
                sort_account_sever();
                break;
            case 5:
                manage_account_sever();
                break;
            case 6:
                printf("This system is closed.\n");
                break;
            default:
                printf("illegal input!!!\n");
        }
    }
    return 0;
}
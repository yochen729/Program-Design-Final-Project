#include "basic.h"
#include "base_operator.h"
#include "trade.h"

extern int num;

void my_trade(struct basic_account* HEAD, char *Name){
    if(PasswordCheck(HEAD,Name)!=TRUE) return;
    struct basic_account *list=AccountCheck(HEAD,Name);
    struct Information  *new_data;
    struct Information  *first=list->trade;
    struct Information  *tail = first;
    while(tail->nt) {tail = tail->nt;}
    int status,dollar;
    char DAY[MAX_DATE];
    printf("---1:IMPORT 2:WITHDRAW 3:TRANSFER---\n");
    scanf("%d",&status);
    new_data=malloc(sizeof(struct Information));
    switch(status){
      case 1:
        printf("$$\tYYYY/MM/DD\n");
        scanf("%d %s",&dollar,DAY);
        strcpy(new_data->ST,"IMPORT"),strcpy(new_data->date,DAY);
        new_data->used_money=dollar;
        list->money = new_data->total = list->money + dollar;
        tail->nt=new_data,new_data->nt=NULL;
        break;

      case 2://金額不足問題
        printf("$$\tYYYY/MM/DD\n");
        scanf("%d %s",&dollar,DAY);
        if(list->money>=dollar){
            strcpy(new_data->ST,"WITHDRAW"),strcpy(new_data->date,DAY);
            new_data->used_money=dollar;
            list->money = new_data->total = list->money - dollar;
            tail->nt=new_data,new_data->nt=NULL;
        }
        else
            printf("you aren't enough money.\n");
        break;

      case 3://同上
        printf("$$\tYYYY/MM/DD\n");
        scanf("%d %s",&dollar,DAY);
        if(list->money>=dollar){
            char given_name[MAX_NAME];
            printf("Transfer to :");
            scanf("%s",given_name);
            struct basic_account *GIVEN=AccountCheck(HEAD,given_name);
            struct Information *GIVEN_inform_tail=GIVEN->trade;
            while(GIVEN_inform_tail->nt) {GIVEN_inform_tail = GIVEN_inform_tail->nt;}
            struct Information  *new=malloc(sizeof(struct Information));

            strcpy(new_data->ST,"TRANSFER"),strcpy(new_data->date,DAY);
            new_data->used_money=dollar;
            list->money = new_data->total = list->money - dollar;
            tail->nt=new_data,new_data->nt=NULL;

            strcpy(new->ST,"TRANSFER FROM"),strcpy(new->date,DAY);
            new->used_money=dollar;
            GIVEN->money = new->total = GIVEN->money + dollar;
            GIVEN_inform_tail->nt=new,new->nt=NULL;
        }
        else
            printf("you aren't enough money.\n");
        break;

        default:
          printf("invalid input.\n");
    }
}
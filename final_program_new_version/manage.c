#include "basic.h"
#include "base_operator.h"
#include "manage.h"
#include "print.h"

extern int num;

void my_manage(struct basic_account* HEAD, char *Name)
{
    if(PasswordCheck(HEAD,Name)!=TRUE) return;
    printf("---1:VIEW PERSONAL DATA  2:VIEW TRADE DATA  3:MODIFY PERSONAL DATA---\n");
    struct basic_account *list=AccountCheck(HEAD,Name);
    struct Information  *new_data;
    struct Information  *first=list->trade;
    int status;
    scanf("%d",&status);
    switch(status){
      case 1:
        printf("NAME:%s\nBIRTH:%s\nPHONE:%s\nEMAIL:%s\nPASSWORD:%s\n", list->name, list->birth, list->phone, list->email, list->password);
        printf("DATE FOR CREATE:%s\nCURRENT REMAINING MONEY:%d\n", first->date, list->money);
        break;

      case 2:
        my_print_inform(first);
        break;

      case 3:
        printf("---1.NAME 2.BIRTH 3.PHONE 4.EMAIL 5.PASSWORD 6.ALL---\n");
        printf("Enter your choose:");
        int status2;
        char name[MAX_NAME], birth[MAX_DATE], phone[MAX_PHONE], email[MAX_EMAIL], password[MAX_PASSWORD];
        scanf("%d",&status2);
        switch(status2)
        {
          case 1:
            printf("NAME:");
            scanf("%s", name);
            strcpy(list->name, name);
            break;
          case 2:
            printf("BIRTH:");
            scanf("%s", birth);
            strcpy(list->birth, birth);
            break;
          case 3:
            printf("PHONE:");
            scanf("%s", phone);
            strcpy(list->phone, phone);
            break;
          case 4:
            printf("EMAIL:");
            scanf("%s", email);
            strcpy(list->email, email);
            break;
          case 5:
            printf("PASSWORD:");
            scanf("%s", password);
            strcpy(list->password, password);
            break;
          case 6:
            printf("NAME:");
            scanf("%s", name);
            printf("BIRTH:");
            scanf("%s", birth);
            printf("PHONE:");
            scanf("%s", phone);
            printf("EMAIL:");
            scanf("%s", email);
            printf("PASSWORD:");
            scanf("%s", password);
            strcpy(list->name, name);
            strcpy(list->birth, birth);
            strcpy(list->phone, phone);
            strcpy(list->email, email);
            strcpy(list->password, password);
          default:
            break;
        }
        break;

        default:
          printf("invalid input.\n");
    }
}
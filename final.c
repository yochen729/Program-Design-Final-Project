#include "basic.h"
#include "mySYS.h"

int main(){


  struct basic_account *ACCOUNT;
  ACCOUNT=initial(ACCOUNT);
  int status;
  char NAME[MAX_NAME];
  while(1){
    printf("1.create 2.delete 3.view 4.sort 5.manage account\n");
    scanf("%d",&status);
    switch(status){
        case 1:
            my_create(ACCOUNT);
            break;
        case 2:
            printf("Enter your name:");
            scanf("%s",NAME);
            my_delete(ACCOUNT,NAME);
            break;
        case 3:
            my_print(ACCOUNT);
            break;
        case 4://name , money , date
          printf("4\n");break;
        case 5:
            printf("Enter your name:");
            scanf("%s",NAME);
            MYmanage(ACCOUNT,NAME);
            break;
        default:
            printf("Please enter the correct information.\n");
          break;

    }
  }

}


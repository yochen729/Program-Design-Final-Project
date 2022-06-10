#include "basic.h"
#include "mySYS.h"

int main(){


  struct basic_account *ACCOUNT;
  ACCOUNT=initial(ACCOUNT);
  int status;

  while(1){
    printf("1.create 2.delete 3.view 4.sort 5.trade 6.manage\n");
    scanf("%d",&status);
    switch(status){
        case 1:
            //printf("NAME,BIRTH,PHONE,EMAIL,&ORIGINAL,DATE,PASSWORD\n");
            //scanf("%s %s %s %s %d %s %s",NAME,BIRTH,PHONE,EMAIL,&ORIGINAL,DATE,PASSWORD);
            //my_create(ACCOUNT,NAME,BIRTH,PHONE,EMAIL,ORIGINAL,DATE,PASSWORD);
            my_create(ACCOUNT);
            break;
        case 2:
            my_delete(ACCOUNT);
            break;
        case 3:
            my_print(ACCOUNT);
            break;
        case 4://name , money , date
       //     my_sort(ACCOUNT);
            break;
        case 5:
            my_trade(ACCOUNT);
            break;
        case 6:
            my_manage(ACCOUNT);
            break;
        default:
            printf("Please enter the correct information.\n");
          break;

    }
  }

}


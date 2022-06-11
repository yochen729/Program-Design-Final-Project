#include "basic.h"
#include "base_operator.h"

int num = 1; // user_num = num -1

struct basic_account *initial(struct basic_account *initial){

      initial=malloc(sizeof(struct basic_account));
      strcpy(initial->name,"EXAMPLE"),strcpy(initial->phone,"0901010101");
      strcpy(initial->birth,"1999/01/01"),strcpy(initial->email,"CCUCCU123123@gmail.com");
      strcpy(initial->password,"CCUCCU123123");
      initial->trade=malloc(sizeof(struct Information));
      strcpy(initial->trade->ST,"IMPORT");
      strcpy(initial->trade->date,"2022/05/21");
      initial->trade->used_money=0;
      initial->trade->total=0;
      initial->trade->nt=NULL;
      initial->next=NULL;
      initial->money=0;

      return initial;
}

struct basic_account *AccountCheck(struct basic_account *HEAD,char *name){

    struct basic_account *list;
    for(list=HEAD;list!=NULL;list=list->next){
        if(strcmp(name,list->name)==0)
          return list;
    }
}


int PasswordCheck(struct basic_account *HEAD,char* Name){
    struct basic_account *user;
    int times=3;
    char p[MAX_PASSWORD];
    for(user=HEAD;user!=NULL;user=user->next){
      if(strcmp(user->name,Name)==0){
        printf("you have 3 times to enter password.\nEnter your password:");
        while(times--){
            scanf("%s",p);
            if(strcmp(p,user->password)==0){
              return TRUE;
            }
            else{
              printf("you have %d times.\n",times);
              if(times==0)
                return FALSE;
            }
        }
      }
    }
        printf("There isn't this account here.\n");
        return -1;

}

void wait_screen(){
  printf("Enter any to continue...\n");
  getch();
}
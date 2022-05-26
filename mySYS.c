#include "basic.h"
#include "mySYS.h"

int num=1;
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
    char p[20];
    for(user=HEAD;user!=NULL;user=user->next){
      if(strcmp(user->name,Name)==0){
        printf("you have 3 times to enter password.\nEnter your password:");
        while(times--){
            scanf("%s",p);
            if(strcmp(p,user->password)==0){
              return 1;
            }
            else{
              printf("you have %d times.\n",times);
              if(times==0)
                return 0;
            }
        }
      }
    }
        printf("There isn't this account here.\n");
        return -1;

}
void my_create(struct basic_account* HEAD,char *NAME,char *BIRTH,char *PHONE,char *EMAIL,int ORIGINAL,char *DATE,char *PASSWORD){

    struct basic_account *new_node=malloc(sizeof(struct basic_account));
    struct basic_account *list=HEAD;

    for(int i=0;i<num-1;i++){
      list=list->next;
    }
    strcpy(new_node->name,NAME),strcpy(new_node->birth,BIRTH);
    strcpy(new_node->phone,PHONE),strcpy(new_node->email,EMAIL);
    strcpy(new_node->password,PASSWORD);

    new_node->trade=malloc(sizeof(struct Information));
    strcpy(new_node->trade->ST,"IMPORT");
    strcpy(new_node->trade->date,DATE);
    new_node->trade->used_money=ORIGINAL;
    new_node->trade->total+=ORIGINAL;
    new_node->trade->nt=NULL;
    list->next=new_node,
    new_node->next=NULL;
    num++;

}
void my_delete(struct basic_account* HEAD, char *Name){
    if(PasswordCheck(HEAD,Name)!=1) return;
    struct basic_account *cur,*prev;
    for(cur=HEAD,prev=NULL;cur!=NULL;prev=cur,cur=cur->next){
        if(strcmp(cur->name,Name)==0){
            prev->next=cur->next;
            free(cur);
            printf("DELETE SUCCESS.\n");
            num--;
            break;
       }
    }
}
void my_print(struct basic_account* HEAD){

    struct basic_account *first;
    for(first=HEAD;first!=NULL;first=first->next){
        printf("%s\n",first->name);
    }
}
void my_print_inform(struct Information *HEAD){
    struct Information *first;
    printf("YYYY/MM/DD\tRECORD\tMOENY\tTOTAL\n");
    for(first=HEAD;first!=NULL;first=first->nt){
      printf("%s\t%s\t%d\t%d\n",first->date,first->ST,first->used_money,first->total);
    }
}

void MYmanage(struct basic_account* HEAD, char *Name){
    if(PasswordCheck(HEAD,Name)!=1) return;
    struct basic_account *list=AccountCheck(HEAD,Name);
    struct Information  *new_data;
    struct Information  *first=list->trade;
    int status,dollar;
    char DAY[20];
    printf("---1:IMPORT 2:WITHDRAW 3:TRANSFER 4:PRINT_DATA---\n");
    scanf("%d",&status);
    new_data=malloc(sizeof(struct Information));
    switch(status){
      case 1:
        printf("$$\tYYYY/MM/DD\n");
        scanf("%d %s",&dollar,DAY);
        strcpy(new_data->ST,"IMPORT"),strcpy(new_data->date,DAY);
        new_data->used_money=dollar,new_data->total+=dollar;
        first->nt=new_data,new_data->nt=NULL;
        break;

      case 2://金額不足問題
        printf("$$\tYYYY/MM/DD\n");
        scanf("%d %s",&dollar,DAY);
        if(first->total>=dollar){
            strcpy(new_data->ST,"WITHDRAW"),strcpy(new_data->date,DAY);
            new_data->used_money=dollar,new_data->total-=dollar;
            first->nt=new_data,new_data->nt=NULL;
        }
        else
            printf("you aren't enough money.\n");
        break;

      case 3://同上
        printf("$$\tYYYY/MM/DD\n");
        scanf("%d %s",&dollar,DAY);
        if(first->total>=dollar){
            char given_name[20];
            printf("Transfer to :");
            scanf("%s",given_name);
            struct basic_account *GIVEN=AccountCheck(HEAD,given_name);
            struct Information *GIVEN_inform=GIVEN->trade;
            struct Information  *new=malloc(sizeof(struct Information));


            strcpy(new_data->ST,"TRANSFER"),strcpy(new_data->date,DAY);
            new_data->used_money=dollar,new_data->total-=dollar;
            first->nt=new_data,new_data->nt=NULL;

            strcpy(new->ST,"TRANSFER FROM"),strcpy(new->date,DAY);
            new->used_money=dollar,new->total+=dollar;
            GIVEN_inform->nt=new,new->nt=NULL;
        }
        else
            printf("you aren't enough money.\n");
        break;
      case 4:
        my_print_inform(first);
        break;

     // default:
    }
}


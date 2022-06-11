#include "basic.h"
#include "mySYS.h"


int num=1;
struct basic_account *initial(struct basic_account *curnode){


        curnode=malloc(sizeof(struct basic_account));

        strcpy(curnode->name,"GM"),strcpy(curnode->birth,"?");
        strcpy(curnode->phone,"?"),strcpy(curnode->email,"?");
        strcpy(curnode->password,"?");

        curnode->trade=malloc(sizeof(struct Information));
        strcpy(curnode->trade->ST,"?");
        strcpy(curnode->trade->date,"?");
        curnode->trade->used_money=0,curnode->trade->total=0;
        curnode->trade->nt=NULL;
        curnode->next=NULL;
      return curnode;
}

void my_print(struct basic_account* HEAD){

    struct basic_account *first;
    for(first=HEAD;first!=NULL;first=first->next){
        printf("%s\n",first->name);
    }
}
void my_inform(struct Information *HEAD){
    printf("YYYY/MM/DD   RECORD\tMOENY\tTOTAL\n");
    for(;HEAD!=NULL;HEAD=HEAD->nt){
      printf("%s   %s\t%d\t%d\n",HEAD->date,HEAD->ST,HEAD->used_money,HEAD->total);
    }
}

struct basic_account *AccountCheck(struct basic_account *HEAD,char *name){

    for(;HEAD!=NULL;HEAD=HEAD->next){
        if(strcmp(name,HEAD->name)==0)
          return HEAD;
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
void my_create(struct basic_account *curnode){

    char NAME[maxsize],BIRTH[maxsize],PHONE[maxsize],EMAIL[maxsize],DATE[maxsize],PASSWORD[maxsize];

      //printf("\033[45m[NAME]\033[4m");
      printf("NAME:");scanf("%s",NAME);
      printf("BIRTH:");scanf("%s",BIRTH);
      printf("PHONE:");scanf("%s",PHONE);
      printf("EMAIL:");scanf("%s",EMAIL);
      printf("DATE:");scanf("%s",DATE);
      printf("PASSWORD:");scanf("%s",PASSWORD);
      struct basic_account *new_node=malloc(sizeof(struct basic_account));

      for(int i=0;i<num-1;i++){
          curnode=curnode->next;
      }
      strcpy(new_node->name,NAME),strcpy(new_node->birth,BIRTH);
      strcpy(new_node->phone,PHONE),strcpy(new_node->email,EMAIL);
      strcpy(new_node->password,PASSWORD);

      new_node->trade=malloc(sizeof(struct Information));
      strcpy(new_node->trade->ST,"----");
      strcpy(new_node->trade->date,DATE);
      new_node->trade->used_money=0,new_node->trade->total=0;
      new_node->trade->nt=NULL;
      curnode->next=new_node,
      new_node->next=NULL;
      num++;
}

void my_delete(struct basic_account *curnode){
    char NAME[maxsize];
    printf("Enter your name:");
    scanf("%s",NAME);
    if(PasswordCheck(curnode,NAME)!=1) return;
    struct basic_account *cur,*prev;
    for(cur=curnode,prev=NULL;cur!=NULL;prev=cur,cur=cur->next){
        if(strcmp(cur->name,NAME)==0){
            prev->next=cur->next;
            free(cur);
            printf("DELETE SUCCESS.\n");
            num--;
            break;
       }
    }
}

/*void my_sort(struct basic_account *HEAD){



}
*/
void my_trade(struct basic_account* HEAD){
    char NAME[maxsize],DAY[maxsize];
    printf("Enter your name:");
    scanf("%s",NAME);
    if(PasswordCheck(HEAD,NAME)!=1) return;
    struct basic_account *list=AccountCheck(HEAD,NAME);
    struct Information  *new_data;
    struct Information  *first=list->trade;
    int status,dollar;
    printf("---1:IMPORT\t2:WITHDRAW\t3:TRANSFER---\n");
    scanf("%d",&status);
    new_data=malloc(sizeof(struct Information));
    switch(status){
      case 1:
        printf("---$$\tYYYY/MM/DD---\n");
        scanf("%d %s",&dollar,DAY);
        strcpy(new_data->ST,"IMPORT"),strcpy(new_data->date,DAY);
        new_data->used_money=dollar,new_data->total+=dollar;
        first->nt=new_data,new_data->nt=NULL;
        break;

      case 2://金額不足問題
        printf("---$$\tYYYY/MM/DD---\n");
        scanf("%d %s",&dollar,DAY);
        if(first->total>=dollar){
            strcpy(new_data->ST,"WITHDRAW"),strcpy(new_data->date,DAY);
            new_data->used_money=dollar,new_data->total-=dollar;
            first->nt=new_data,new_data->nt=NULL;
        }
        else
            printf("You aren't enough money.\n");
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

            strcpy(new->ST,"TRANSFERED"),strcpy(new->date,DAY);
            new->used_money=dollar,new->total+=dollar;
            GIVEN_inform->nt=new,new->nt=NULL;
        }
        else
            printf("you aren't enough money.\n");
        break;

        default:
            printf("Please enter the correct information.\n");
            break;
    }
}
void my_manage(struct basic_account *curnode){

    char NAME[maxsize];
    printf("Enter your name:");
    scanf("%s",NAME);
    if(PasswordCheck(curnode,NAME)!=1) return;
    struct basic_account *list=AccountCheck(curnode,NAME);

    int status;
    printf("---1.Print Personal Information 2.Personal Trade Record 3.Modify Personal Information\n");
    scanf("%d",&status);
    switch(status){
        case 1:
          printf("NAME\tBIRTH\tPHONE\tEMAIL\tDATE\tPASSWORD\n");
          printf("%s\t%s\t%s\t%s\t%s\t%s\n",list->name,list->birth,list->phone,list->email,list->trade->date,list->password);
          break;

        case 2:
          my_inform(list->trade);
          break;

       /* case 3:

          break;

*/
        default:
            printf("Please enter the correct information.\n");
            break;
    }

}


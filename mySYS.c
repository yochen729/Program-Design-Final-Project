#include "basic.h"
#include "mySYS.h"

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
void my_create(struct basic_account* HEAD){

    printf("---1:from file 2:from stdin---\n");
    int status;
    char FILE_NAME[MAX_NAME];
    char NAME[MAX_NAME],PHONE[MAX_PHONE],BIRTH[MAX_DATE],EMAIL[MAX_EMAIL],PASSWORD[MAX_PASSWORD],DATE[MAX_DATE];
    int ORIGINAL;// initital money
    scanf("%d",&status);
    switch(status){
      case 1:
        printf("Enter your file name:\n");
        scanf("%s",FILE_NAME);
        FILE *fp = fopen(FILE_NAME, "r");
        if (fp == NULL) {
          fprintf(stderr, "File open failed.\n");
          return;
        }
        char line[MAX_LINE];
        char *data[7];
        char *token;   
        while (fgets(line, MAX_LINE, fp) != NULL) {
            printf("Row: %s", line);
            token = strtok(line, ","); 
            for(int i=0;i<7;i++) {
                data[i] = calloc(1, sizeof(char)*MAX_DATA);
                strcpy(data[i], token);
                printf("Token: %s\n", token);
                token = strtok(NULL, ",");
            }
            my_create_single(HEAD, data[0], data[1], data[2], data[3], atoi(data[4]), data[5], data[6]);
            for(int i=0;i<7;i++)  {free(data[i]);}
        }
        fclose(fp);
        break;

      case 2:
        printf("NAME,BIRTH,PHONE,EMAIL,&ORIGINAL,DATE,PASSWORD\n");
        scanf("%s %s %s %s %d %s %s",NAME,BIRTH,PHONE,EMAIL,&ORIGINAL,DATE,PASSWORD);
        my_create_single(HEAD,NAME,BIRTH,PHONE,EMAIL,ORIGINAL,DATE,PASSWORD);
        break;
      default:
        printf("invalid input.\n");
    }
}
void my_create_single(struct basic_account* HEAD,char *NAME,char *BIRTH,char *PHONE,char *EMAIL,int ORIGINAL,char *DATE,char *PASSWORD){

    struct basic_account *new_node=malloc(sizeof(struct basic_account));
    struct basic_account *list=HEAD;

    for(int i=0;i<num-1;i++){
      list=list->next;
    }
    strcpy(new_node->name,NAME),strcpy(new_node->birth,BIRTH);
    strcpy(new_node->phone,PHONE),strcpy(new_node->email,EMAIL);
    strcpy(new_node->password,PASSWORD);

    new_node->trade=malloc(sizeof(struct Information));
    strcpy(new_node->trade->ST,"IMPORT FOR BUILD");
    strcpy(new_node->trade->date,DATE);
    new_node->trade->used_money=ORIGINAL;
    new_node->trade->total=ORIGINAL;
    new_node->money=ORIGINAL;
    new_node->trade->nt=NULL;
    list->next=new_node,
    new_node->next=NULL;
    num++;

}
void my_delete(struct basic_account* HEAD, char *Name){
    if(PasswordCheck(HEAD,Name)!=TRUE) return;
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
    printf("name\n");
    first=HEAD;
    while(first){
        first = first->next;
        printf("%s\n",first->name);
    }
}
void my_print_inform(struct Information *HEAD){
    struct Information *first;
    printf("YYYY/MM/DD\tRECORD\tMOENY\tTOTAL\n");
    for(first=HEAD;first!=NULL;first=first->nt){
      printf("%s\t%s\t%d\t%d\n",first->date, first->ST, first->used_money, first->total);
    }
}

void MYmanage(struct basic_account* HEAD, char *Name){
    //if(PasswordCheck(HEAD,Name)!=TRUE) return;
    struct basic_account *list=AccountCheck(HEAD,Name);
    struct Information  *new_data;
    struct Information  *first=list->trade;
    struct Information  *tail = first;
    while(tail->nt) {tail = tail->nt;}
    int status,dollar;
    char DAY[MAX_DATE];
    printf("---1:IMPORT 2:WITHDRAW 3:TRANSFER 4:PRINT_DATA---\n");
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
      case 4:
        my_print_inform(first);
        break;

        default:
          printf("invalid input.\n");
    }
}


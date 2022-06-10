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
            // printf("Row: %s", line);
            token = strtok(line, ","); 
            for(int i=0;i<7;i++) {
                data[i] = calloc(1, sizeof(char)*MAX_DATA);
                strcpy(data[i], token);
                // printf("Token: %s\n", token);
                token = strtok(NULL, ",");
            }
            for(int i=0;i<strlen(data[6]);i++){
              if(data[6][i]=='\n') data[6][i] = '\0';
            }
            // data[6][strlen(data[6])-1] = '\0';
            my_create_single(HEAD, data[0], data[1], data[2], data[3], atoi(data[4]), data[5], data[6]);
            for(int i=0;i<7;i++)  {free(data[i]);}
        }
        fclose(fp);
        printf("CREATE SUCCESS.\n");
        break;

      case 2:
        printf("NAME,BIRTH,PHONE,EMAIL,ORIGINAL,DATE,PASSWORD\n");
        scanf("%s %s %s %s %d %s %s",NAME,BIRTH,PHONE,EMAIL,&ORIGINAL,DATE,PASSWORD);
        my_create_single(HEAD,NAME,BIRTH,PHONE,EMAIL,ORIGINAL,DATE,PASSWORD);
        printf("CREATE SUCCESS.\n");
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
      if(strcmp(list->name, NAME)==0){
        printf("name:%s is used, creating is failed.\n",NAME);
        return;
      }
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
    char file_name[MAX_NAME];
    FILE *fp;
    int state;
    printf("---output deleted file? 1.YES 2.NO---");
    scanf("%d", &state);
    for(cur=HEAD,prev=NULL;cur!=NULL;prev=cur,cur=cur->next){
        if(strcmp(cur->name,Name)==0){
            prev->next=cur->next;
            switch (state)
            {
            case 1:
              printf("Enter a name for file:");
              scanf("%s", file_name);
              fp = fopen(file_name, "w+");
              if (fp == NULL) {
                fprintf(stderr, "File open failed.\n");
                return;
              }
              fprintf(fp, "NAME,BIRTH,PHONE,EMAIL,MONEY,CREATE DATE,PASSWORD\n");
              fprintf(fp, "%s,%s,%s,%s,%d,%s,%s\n", cur->name, cur->birth, cur->phone, cur->email, cur->money, cur->trade->date, cur->password);
              free(cur);
              fclose(fp);
              break;
            case 2:
              free(cur);
              break;
            default:
              break;
            }
            printf("DELETE SUCCESS.\n");
            num--;
            break;
       }
    }
}
void my_print(struct basic_account* HEAD){

    struct basic_account *first;
    printf("name\tmoney\tdate for creating\n");
    first=HEAD;
    while(first->next){
        first = first->next;
        printf("%s\t%d\t%s\n", first->name, first->money, first->trade->date);
    }
}
void my_print_inform(struct Information *HEAD){
    struct Information *first;
    printf("YYYY/MM/DD\tMOENY\tTOTAL\tRECORD\n");
    for(first=HEAD;first!=NULL;first=first->nt){
      printf("%s\t%d\t%d\t%s\n",first->date, first->used_money, first->total, first->ST);
    }
}

void Swap_name(struct basic_account* head, char* name1, char *name2)
{
    struct basic_account *ptr,*qtr,*ptr_pre;
    for(ptr=head->next,ptr_pre=head;ptr;ptr_pre=ptr,ptr=ptr->next)
    {
      if(strcmp(ptr->name,name1)==0)
              break;
    }
      for(qtr=head->next;qtr;qtr=qtr->next)
    {
      if(strcmp(qtr->name,name2)==0)
              break;
    }
    ptr->next=qtr->next;
    ptr_pre->next=qtr;
    qtr->next=ptr;
}

void my_sort(struct basic_account* head){
  //if no item in this linked list, then return.
    if(head->next == NULL) return;
    //Use bubble sorting(from small to large), but replace inner for loop with while loop.
    struct basic_account* qtr;
    for(int i=0;i<num-1;i++)
    {
        //initialize qtr
        qtr = head->next;
        //To make sure that qtr and qtr->next can be exchange, "qtr->next!=NULL" is necessary.
        while(qtr->next!=NULL)
        {
            if(strcmp(qtr->name, qtr->next->name)>0)
            //Because Swap() function will cause qtr=qtr->next, "qtr = qtr->next" is not necessary in this block.
                Swap_name(head, qtr->name, qtr->next->name);
            else
                qtr = qtr->next;
        }
    }
    // return head;
}

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

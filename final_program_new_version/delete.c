#include "basic.h"
#include "base_operator.h"
#include "delete.h"

extern int num;

void my_delete(struct basic_account* HEAD, char *Name){
    if(PasswordCheck(HEAD,Name)!=TRUE){
      wait_screen();
      return;
    }
    struct basic_account *cur,*prev;
    char file_name[MAX_NAME];
    FILE *fp;
    int state;
    int find = FALSE;
    printf("---output deleted file? 1.YES 2.NO---\n");
    scanf("%d", &state);
    for(cur=HEAD,prev=NULL;cur!=NULL;prev=cur,cur=cur->next){
        if(strcmp(cur->name,Name)==0){
            find == TRUE;
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
    if(find==FALSE) fprintf(stderr,"name:%s doesn't exist, DELETE DEFAULT.\n",Name);
    wait_screen();
}
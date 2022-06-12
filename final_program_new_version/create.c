#include "basic.h"
#include "base_operator.h"
#include "create.h"

extern int num;

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
          wait_screen();
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
        break;

      case 2:
        printf("NAME:");scanf("%s",NAME);
        printf("BIRTH:");scanf("%s",BIRTH);
        printf("PHONE:");scanf("%s",PHONE);
        printf("EMAIL:");scanf("%s",EMAIL);
        printf("original money:");scanf("%d",&ORIGINAL);
        printf("DATE:");scanf("%s",DATE);
        printf("PASSWORD:");scanf("%s",PASSWORD);
        // printf("NAME,BIRTH,PHONE,EMAIL,ORIGINAL,DATE,PASSWORD\n");
        // scanf("%s %s %s %s %d %s %s",NAME,BIRTH,PHONE,EMAIL,&ORIGINAL,DATE,PASSWORD);
        // printf("password is '%s', please remember.\n",PASSWORD);
        my_create_single(HEAD,NAME,BIRTH,PHONE,EMAIL,ORIGINAL,DATE,PASSWORD);
        break;
      default:
        printf("invalid input.\n");
    }
    wait_screen();
}
void my_create_single(struct basic_account* HEAD,char *NAME,char *BIRTH,char *PHONE,char *EMAIL,int ORIGINAL,char*DATE,char *PASSWORD){

    struct basic_account *new_node=malloc(sizeof(struct basic_account));
    struct basic_account *list=HEAD;

    // time_t now; // 變數宣告
    // time(&now); // 取得現在的日期時間
    // struct tm *p=gmtime(&now);
    // char day[MAX_DATE];
    // memset(day, 0, MAX_DATE);
    // sprintf(day, "%d/%d/%d", p->tm_year+1900, p->tm_mon+1, p->tm_mday);

    for(int i=0;i<num-1;i++){
      list=list->next;
      if(strcmp(list->name, NAME)==0){
        fprintf(stderr,"name:%s is used, creating is failed.\n",NAME);
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
    new_node->trade->loan=0;
    list->next=new_node,
    new_node->next=NULL;
    num++;
    printf("name:%s CREATE SUCCESS.\n",NAME);

}
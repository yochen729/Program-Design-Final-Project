#include "basic.h"
#include "base_operator.h"
#include "print.h"

extern int num;

void my_print(struct basic_account* HEAD){

    struct basic_account *first;
    printf("name\tmoney\tdate for creating\n");
    first=HEAD;
    while(first->next){
        first = first->next;
        printf("%s\t%d\t%s\n", first->name, first->money, first->trade->date);
    }
    int state;
    printf("---output file for above data? 1.YES 2.NO---\n");
    scanf("%d", &state);
    if(state==1){
      char file_name[MAX_NAME];
      FILE *fp;
      printf("Enter a name for file:");
      scanf("%s", file_name);
      fp = fopen(file_name, "w+");
      if (fp == NULL) {
        fprintf(stderr, "File open failed.\n");
        return;
      }
      fprintf(fp, "name,money,date for creating\n");
      first=HEAD;
      while(first->next){
          first = first->next;
          fprintf(fp, "%s,%d,%s\n", first->name, first->money, first->trade->date);
      }
      fclose(fp);
    }
}
void my_print_inform(struct Information *HEAD){
    struct Information *first;
    printf("YYYY/MM/DD\tMOENY\tTOTAL\tRECORD\n");
    for(first=HEAD;first!=NULL;first=first->nt){
      printf("%s\t%d\t%d\t%s\n",first->date, first->used_money, first->total, first->ST);
    }
}
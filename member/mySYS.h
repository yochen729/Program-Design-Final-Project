#ifndef mySYS_H
#define mySYS_H

struct Information{
    char ST[20],date[20];
    int used_money,total;
    struct Information *nt;
};


struct basic_account{ //personal information

    char name[20],phone[20],birth[10],email[50],password[20];
    struct Information *trade;
    struct basic_account *next;
};

void my_print(struct basic_account *);
void my_print_inform(struct basic_account *);
struct basic_account *AccountCheck(struct basic_account *,char *);
int PasswordCheck(struct basic_account *,char*);
struct basic_account *initial(struct basic_account *);
void my_create(struct basic_account *);
void my_delete(struct basic_account *);
void my_sort(struct basic_account *);
void my_trade(struct basic_account *);
void my_manage(struct basic_account *);

#endif

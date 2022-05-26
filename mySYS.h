#ifndef mySYS_H
#define mySYS_H

struct Information{
    char ST[20];
    char date[20];
    int used_money;
    int total;
    struct Information *nt;
};


struct basic_account{ //personal information

    char name[20],phone[20],birth[10],email[50],password[20];
    struct Information *trade;
    struct basic_account *next;
};

struct basic_account *initial(struct basic_account*);
void my_create(struct basic_account*, char*, char *,char *,char *,int ,char *,char *);
void my_delete(struct basic_account*, char*);
void my_print(struct basic_account*);
struct basic_account *AccountCheck(struct basic_account *,char*);
int PasswordCheck(struct basic_account *,char*);
void MYmanage(struct basic_account*, char*);

#endif

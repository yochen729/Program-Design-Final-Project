#ifndef base_operator_H
#define base_operator_H

#define MAX_NAME 64
#define MAX_PHONE 16
#define MAX_DATE 16
#define MAX_EMAIL 64
#define MAX_PASSWORD 64
#define MAX_TYPE 32
#define TRUE 1
#define FALSE 0
#define MAX_DATA 64
#define MAX_LINE 512
#define MAX_LOAN 10000000


struct Information{
    // IMPORT FOR CREATE, IMPORT, WITHDRAW, TRANSFER TO XX, TRANSFER FROM XX
    char ST[MAX_TYPE]; 
    char date[MAX_DATE];
    int used_money; 
    int total;
    int loan;
    struct Information *nt;
};

struct basic_account{ //personal information
    int money;
    char name[MAX_NAME],phone[MAX_PHONE],birth[MAX_DATE],email[MAX_EMAIL],password[MAX_PASSWORD];
    struct Information *trade;
    struct basic_account *next;
};

struct basic_account *initial(struct basic_account*);
struct basic_account *AccountCheck(struct basic_account *,char*);
int PasswordCheck(struct basic_account *,char*);
void wait_screen();

#endif

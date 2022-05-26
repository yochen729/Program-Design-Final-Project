#ifndef mySKILL_h
#define mySKILL_h

#define MAX_NAME 32
#define MAX_PHONE 16
#define MAX_DATE 16
#define MAX_EMAIL 64
#define MAX_PASSWORD 64
#define MAX_TYPE 16
#define TRUE 1
#define FALSE 1

void insert_user(char *name, char *phone, char *birth, char *email, char *password);

void insert_trade_record(char* user_name, int money, char* type);

int check_password(char* name, char* password);

void print_all_account();

#endif
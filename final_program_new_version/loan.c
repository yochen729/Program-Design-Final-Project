#include "basic.h"
#include "base_operator.h"
#include "loan.h"

void my_loan(struct basic_account* HEAD, char *Name){
    if(PasswordCheck(HEAD,Name)!=TRUE){
      wait_screen();
      return;
    }
    
    system("cls");
    time_t now; // 變數宣告
    time(&now); // 取得現在的日期時間
    struct tm *p=gmtime(&now);
    char year[5],mon[3],day[3];
    char DAY[MAX_DATE];
    sprintf(DAY,"%d/%d/%d",p->tm_year+1900,p->tm_mon+1,p->tm_mday);
    struct basic_account *list=AccountCheck(HEAD,Name);
    struct Information *new_data = malloc(sizeof(struct Information));
    struct Information *first = list->trade;
    while(first->nt){first = first->nt;}
    
    int status;
    printf("1.Borrow\t2.Pay Off\n");
    scanf("%d", &status);
    if (status == 2 && first->loan == 0)
    {
        printf("%s don't need to pay Off.\n", list->name);
        wait_screen();
        return;
    }
    int amount;
    printf("Amount: "), scanf("%d", &amount);
    
    if (status == 1)
    {
        if (amount > MAX_LOAN)
            printf("This amount exceeds the size of preset.\n");
        else if (first->loan + amount > MAX_LOAN)
            printf("Please pay off your money first.\n");
        else
        {
            strcpy(new_data->ST, "BORROW"), strcpy(new_data->date, DAY);
            new_data->used_money = amount, new_data->loan = first->loan + amount, list->money = new_data->total = list->money + amount;
            first->nt = new_data, new_data->nt = NULL;

            printf("Borrow Success.\n");
            printf("%s borrow %d, so %s's total money is $%d.\n", list->name, amount, list->name, list->money);
        }

    }
    else
    {
        if (amount > list->money){
            printf("%s not have enough money.\n", list->name);
        }
        else if (amount >= first->loan)
        {
            printf("All Pay Off.\n");
            printf("%s Pay Off %d, remaining amount in %s account is $%d.\n", list->name, amount, list->name, list->money - first->loan);
            strcpy(new_data->ST, "PAYOFF"), strcpy(new_data->date, DAY);
            new_data->used_money = first->loan * (-1), new_data->loan = 0, list->money = new_data->total = first->total - first->loan;
            first->nt = new_data, new_data->nt = NULL;
        }
        else
        {
            printf("%s Pay Off %d, remaining amount in %s account is $%d.\n", list->name, amount, list->name, list->money - amount);
            printf("Remain $%d to pay off.\n", first->loan - amount);
            strcpy(new_data->ST, "PAYOFF"), strcpy(new_data->date, DAY);
            new_data->used_money = amount * (-1), new_data->loan = first->loan - amount, list->money = new_data->total = first->total - amount;
            first->nt = new_data, new_data->nt = NULL;
        }

    }
    wait_screen();
}

#include "basic.h"
#include "base_operator.h"
#include "loan.h"

void my_loan(struct basic_account* HEAD, char *Name){
    if(PasswordCheck(HEAD,Name)!=TRUE){
      wait_screen();
      return;
    }
    
    system("cls");
    struct basic_account *list=AccountCheck(HEAD,Name);
    struct Information *new_data = malloc(sizeof(struct Information));
    struct Information *first = list->trade;
    while(first->nt){first = first->nt;}
    
    int status;char day[MAX_DATE];
    printf("1.Borrow\t2.Pay Off\n");
    scanf("%d", &status);
    if (status == 2 && first->loan == 0)
    {
        printf("You don't need to pay Off.\n");
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
            strcpy(new_data->ST, "BORROW"), strcpy(new_data->date, day);
            new_data->used_money = amount, new_data->loan = first->loan + amount, list->money = new_data->total = list->money + amount;
            first->nt = new_data, new_data->nt = NULL;

            printf("Borrow Success.\n");
            printf("You borrow %d, so your total money is $%d.\n", amount, list->money);
        }

    }
    else
    {
        if (amount > list->money){
            printf("you not have enough money.\n");
        }
        else if (amount >= first->loan)
        {
            printf("All Pay Off.\n");
            printf("You Pay Off %d, remaining amount in your account is $%d.\n", amount, list->money - first->loan);
            strcpy(new_data->ST, "PAYOFF"), strcpy(new_data->date, day);
            new_data->used_money = amount * (-1), new_data->loan = 0, list->money = new_data->total = first->total - first->loan;
            first->nt = new_data, new_data->nt = NULL;
        }
        else
        {
            printf("You Pay Off %d, remaining amount in your account is $%d.\n", amount, list->money - amount);
            printf("Remain $%d to pay off.\n", first->loan - amount);
            strcpy(new_data->ST, "PAYOFF"), strcpy(new_data->date, day);
            new_data->used_money = amount * (-1), new_data->loan = first->loan - amount, list->money = new_data->total = first->total - amount;
            first->nt = new_data, new_data->nt = NULL;
        }

    }
    wait_screen();
}

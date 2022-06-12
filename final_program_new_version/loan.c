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
    int status;
    printf("1.Borrow\t2.Pay Off\n");
    scanf("%d", &status);
    if (status == 2 && list->trade->loan == 0)
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
        else if (list->trade->loan + amount > MAX_LOAN)
            printf("Please pay off your money first.\n");
        else
        {
            list->trade->loan += amount;
            list->money += amount;
            printf("Borrow Success.\n");
            printf("You borrow %d, so your tatol money is $%d.\n",amount,list->money);
        }

    }
    else
    {
        if (amount > list->money){
            printf("you not have enough money.");
        }
        else if (amount >= list->trade->loan)
        {
            printf("All Pay Off.\n");
            printf("You Pay Off %d, remaining amount in your account is $%d.\n", list->trade->loan, list->money - list->trade->loan);
            list->trade->loan = 0;
        }
        else
        {
            printf("You Pay Off %d, remaining amount in your account is $%d.\n", amount, list->money - amount);
            printf("Remain $%d to pay off.\n", list->trade->loan - amount);
            list->trade->loan -= amount;
        }

    }
    wait_screen();
}

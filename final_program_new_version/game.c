#include "basic.h"
#include "base_operator.h"
#include "game.h"

extern int num;

void game_center(struct basic_account *acc)
{
    int game,cost;
    time_t now; // 變數宣告
    time(&now); // 取得現在的日期時間
    struct tm *p=gmtime(&now);
    char year[5],mon[3],day[3];
    char DAY[MAX_DATE];
    sprintf(DAY,"%d/%d/%d",p->tm_year+1900,p->tm_mon+1,p->tm_mday);
    srand(time(0)+rand()); 
    struct Information  *first= acc->trade;
    struct Information  *tail = first;
    struct Information  *new_data;
    while(tail->nt) {tail = tail->nt;}
    new_data=malloc(sizeof(struct Information));

    system("cls");
    printf("Welecom to the Invest Center\n");
    printf("Please enter the investment amount.\n");
    while(scanf("%d",&cost)&&cost>acc->money||cost<0){  
        if(cost == -1){
            wait_screen();
            return;
        }
        printf("you aren't enough money or invalid input. Please retry or type -1 to return.\n");
    }
    printf("you will cost %d in a invest event.\n",cost);
    wait_screen();

        system("cls");
        int event;
        if(cost > 100000) event = rand()%18+3; //超過10萬可以有風險更大的機會
        else event = rand()%12+1;
        char event_name[MAX_DATA];
        switch(event){
                case 1:
                    printf("You bought a scratch-off lottery ticket and won more than 2000\n");
                    strcpy(event_name, "SOLottery EARN");
                    cost = 2000*(rand()%10+1);
                    break;
                case 2:
                    printf("You bought a scratch-off lottery ticket but nothing get.\n");
                    strcpy(event_name, "SOLottery COST");
                    cost = cost/10*5*(-1);
                    break;
                case 3:
                    printf("You win the lottery!\n");
                    strcpy(event_name, "Lottery WIN");
                    cost = 1000000-(cost/10*(rand()%3+5));
                    break;
                case 4:
                    printf("You bought a lottery ticket, but lost the lottery.\n");
                    strcpy(event_name, "BUY Lottery");
                    cost = cost/100*100*(-1);
                    break;
                case 5:
                    printf("You invest in research, and have some research results.\n");
                    strcpy(event_name, "Research EARN");
                    cost = cost*(-1)+rand()%100*1000;
                    break;
                case 6:
                    printf("You invest in research, but nothing.\n");
                    strcpy(event_name, "Researcher Nothing");
                    cost = cost*(-1)+(rand()%2)*(cost/(rand()%5+1));
                    break;
                case 7:
                    printf("Become a food delivery rider, and earn some money.\n");
                    strcpy(event_name, "deliver man EARN");
                    cost = (rand()%100+1)*((rand()%50+1)+50);
                    break;
                case 8:
                    printf("Become a food delivery rider, but got into a car accident.\n");
                    cost = -15000*(rand()%10+1);
                    break;
                case 9:
                    printf("Become a food delivery rider, and got into a car accident but you have the car accident insurance.\n");
                    cost = -15000*(rand()%10+1) + (rand()%5+6)*2500;
                    break;
                case 10:
                    printf("You are thirsty, buy some drinks.\n");
                    cost = -50*(rand()%10+1);
                    strcpy(event_name, "DRINKS");
                    break;
                case 11:
                    printf("You think Capoo is very cute, and bought many of its merch.\n");
                    cost = -2000*(rand()%10+1);
                    strcpy(event_name, "Capoo Fan COST");
                    break;
                case 12:
                    printf("You are humgry, buy some food to eat.\n");
                    cost = -100*(rand()%10+1);
                    strcpy(event_name, "FOOD");
                    break;
                case 13:
                    printf("Invest in LTC but Lost the money.\n");
                    strcpy(event_name, "FUND LOST");
                    cost = cost*(-1)+ rand()%2*(cost/10)*(-1);
                    break;
                case 14:
                    printf("Invest in Mutual fund and make a fortune.\n");
                    strcpy(event_name, "FUND EARN");
                    cost = cost*(rand()%2+1)+ rand()%2*(cost/10);
                    break;
                case 15:
                    printf("You become a BTC miner, it cost all of your money, but earn some money.\n");
                    strcpy(event_name, "BTC miner $$");
                    cost = acc->money*(-1)+(rand()%5+1)*cost;
                    break;
                case 16:
                    printf("You become a BTC miner, it cost half of your money, but earn nothing.\n");
                    strcpy(event_name, "BTC miner nothing");
                    cost = acc->money/2*(-1) + (rand()%100+1)*(rand()%10+1);
                    break;
                case 17:
                    printf("Invest in LTC and make a fortune.\n");
                    strcpy(event_name, "LTC EARN");
                    cost = cost*(rand()%6+1)+rand()%1000;
                    break;
                case 18:
                    printf("Invest in LTC but Lost the money.\n");
                    strcpy(event_name, "LTC LOST");
                    cost = cost*(rand()%3+1)*(-1)+ rand()%2*(cost/10);
                    break;
                case 19:
                    printf("Investment in property, and earn money.\n");
                    cost = cost/(5+(rand()%5+1));
                    strcpy(event_name, "Property EARN");
                    break;
                case 20:
                    printf("Investment in property, but lost money.\n");
                    cost = cost/(5+(rand()%5+1))*(-1);
                    strcpy(event_name, "Property LOST");
                    break;
        }

            wait_screen();
            if(cost>0){
                printf("You EARN %d !!\n",cost);
            }
            else if (cost<0&&cost*(-1)<acc->money){
                printf("You Lost %d.\n",cost*(-1));
            }
            else if (cost<0&&cost*(-1)>=acc->money){
                printf("You Lost all your money.\n");
                cost = acc->money*(-1);
            }
            else{
                printf("You not earn any money\n");
            }
            if(cost != 0){
                strcpy(new_data->ST,"EVENT:"),strcpy(new_data->date,DAY);
                strcat(new_data->ST,event_name);
                new_data->used_money=cost;
                acc->money = new_data->total = acc->money + cost;
                tail->nt=new_data,new_data->nt=NULL;
            }

    int again;
    wait_screen();
    system("cls");
    printf("PRESS 1 TO INVEST AGAIN !!\n");
    scanf("%d",&again);
    if(again==1) {
        game_center(acc);
    }
}
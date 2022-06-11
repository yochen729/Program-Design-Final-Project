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
    char input[MAX_DATE];
    sprintf(DAY,"%d/%d/%d",p->tm_year+1900,p->tm_mon+1,p->tm_mday);
    srand(p->tm_sec); 
    struct Information  *first= acc->trade;
    struct Information  *tail = first;
    struct Information  *new_data;
    while(tail->nt) {tail = tail->nt;}
    new_data=malloc(sizeof(struct Information));

    system("cls");
    printf("Welecom to the Invest Game Center\n");
    printf("Select a game to play and winnig the money !!\n");
    printf("---1.DICE 2.GUESS 3.EVENT---\n");

    while(scanf("%s",input)&&strlen(input)>1){
        if(strcmp(input,"exit")==0){
            wait_screen();
            return;
        }
        printf("invalid input. Please retry or type ""exit"" to exit.\n");
    }
    game = atoi(&input[0]);

    switch(game){
        case 1:

            system("cls");
            printf("This is the Dice game, please enter the investment amount.\n");
            while(scanf("%d",&cost)&&cost>acc->money||cost<0){
                if(cost == -1){
                    wait_screen();
                    game_center(acc);
                    return;
                }
                printf("you aren't enough money or invalid input. Please retry or type -1 to rechoose game.\n");
            }
            printf("you will cost %d\n",cost);
            wait_screen();
            
            int dice_a,dice_b;
            dice_a = rand()%6+1;
            dice_b = rand()%6+1;
            if(dice_a>dice_b){
                printf("You get %d and banker get %d.\n",dice_a,dice_b);
                printf("You WON %d !!\n",cost*2);
                cost = cost*2;
            }
            else if (dice_a==dice_b){
                printf("You get %d and banker get %d.\n",dice_a,dice_b);
                printf("DRAW !!\n");
                cost = 0;
            }
            else if (dice_a<dice_b){
                printf("You get %d and banker get %d.\n",dice_a,dice_b);
                printf("You are Loser !! Lost %d.\n",cost);
                cost = cost*(-1);
            }
            if(cost != 0){
                strcpy(new_data->ST,"INVEST_DICE"),strcpy(new_data->date,DAY);
                new_data->used_money=cost;
                acc->money = new_data->total = acc->money + cost;
                tail->nt=new_data,new_data->nt=NULL;
            }
            else{
                free(new_data);
            }

            printf("You now have %d.\n",acc->money);
            break;

        case 2:
            
            system("cls");
            printf("This is the Guess number game, please enter the investment amount.\n");
            while(scanf("%d",&cost)&&cost>acc->money||cost<0){
                if(cost == -1){
                    wait_screen();
                    game_center(acc);
                    return;
                }
                printf("you aren't enough money or invalid input. Please retry or type -1 to rechoose game.\n");
            }
            printf("you will cost %d\n",cost);
            wait_screen();

            int upper = 100,lower = 0;
            int answer,times_to_guess,guess;
            answer = rand()%99+1;
            times_to_guess = 5;
            while(times_to_guess >0){
                
                system("cls");
                printf("You have %d times to guess.",times_to_guess);
                printf("From %d to %d\n",lower,upper);
                printf("Type the number to guess.\n");
                while(scanf("%d",&guess)&&(guess<=lower||guess>=upper)){
                    printf("Please retype the number in %d to %d.\n",lower,upper);
                }
                if(guess>answer){
                    printf("Too Big !!\n");
                    upper = guess;
                }
                else if(guess==answer){
                    system("cls");
                    printf("Congratulation !!\n");
                    cost = cost * (rand()%4+2);
                    break;
                }
                else if(guess<answer){
                    printf("Too Small !!\n");
                    lower = guess;
                }
                times_to_guess--;
                wait_screen();
            }

            if(times_to_guess>0){
                printf("you won the %d.\n",cost);
            }
            else{
                system("cls");
                printf("GAME OVER !!\n");
                cost = cost*(-1);
                printf("you lost %d.\n",cost);
            }
            strcpy(new_data->ST,"GUESS NUMBER"),strcpy(new_data->date,DAY);
            new_data->used_money=cost;
            acc->money = new_data->total = acc->money + cost;
            tail->nt=new_data,new_data->nt=NULL;
            break;

        case 3:
            system("cls");
            printf("This is the random event game, please enter the investment amount.\n");
            while(scanf("%d",&cost)&&cost>acc->money||cost<0){
                if(cost == -1){
                    wait_screen();
                    game_center(acc);
                    return;
                }
                printf("you aren't enough money or invalid input. Please retry or type -1 to rechoose game.\n");
            }
            printf("you will cost %d in a random event game.\n",cost);
            wait_screen();

            int event;
            if(cost > 1000000) event = rand()%20+1; //超過100萬可以有風險更大的機會
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
                    cost = -200;
                    break;
                case 3:
                    printf("You win the lottery!\n");
                    strcpy(event_name, "Lottery WIN");
                    cost = 1000000-cost;
                    break;
                case 4:
                    printf("You bought a lottery ticket, but lost the lottery.\n");
                    strcpy(event_name, "BUY Lottery");
                    cost = cost*(-1);
                    break;
                case 5:
                    printf("You invest in research, and have somere search results.\n");
                    strcpy(event_name, "Research EARN");
                    cost = cost+rand()%100*100;
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
                    cost = -15000 ;
                    break;
                case 9:
                    printf("Become a food delivery rider, and got into a car accident but you have the car accident insurance.\n");
                    cost = -15000 + (rand()%5+6)*2500;
                    break;
                case 10:
                    printf("You are thirsty, buy some drinks.\n");
                    cost = -50;
                    strcpy(event_name, "DRINKS");
                    break;
                case 11:
                    printf("You think Capoo is very cute, and bought many of its merch.\n");
                    cost = -2000;
                    strcpy(event_name, "Capoo Fan COST");
                    break;
                case 12:
                    printf("You are humgry, buy some food to eat.\n");
                    cost = -100;
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
                    cost = cost*(rand()%2+1)*(-1)+ rand()%2*(cost/10);
                    break;
                case 15:
                    printf("You become a BTC miner, it cost all of your money, but earn some money.\n");
                    strcpy(event_name, "BTC miner $$");
                    cost = cost*(-1)+rand()%10000;
                    break;
                case 16:
                    printf("You become a BTC miner, it cost all of your money, but earn nothing.\n");
                    strcpy(event_name, "BTC miner nothing");
                    cost = 0;
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
                    cost = cost + cost/(5+(rand()%5+1));
                    strcpy(event_name, "Property EARN");
                    break;
                case 20:
                    printf("Investment in property, but lost money.\n");
                    cost = cost - cost/(5+(rand()%5+1));
                    strcpy(event_name, "Property LOST");
                    break;
            }

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
            break;

        default:
          free(new_data);
          printf("invalid input.\n");
    }
    int again;
    printf("PRESS 1 TO PLAY AGAIN !!\n");
    scanf("%d",&again);
    if(again==1) {
        game_center(acc);
    }
}
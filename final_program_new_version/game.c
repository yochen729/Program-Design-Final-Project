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
    // sprintf(mon,"%d",p->tm_mon+1);
    // sprintf(day,"%d",p->tm_mday);
    // strcpy(DAY,year);strcat(DAY,"/");strcat(DAY,mon);strcat(DAY,"/");strcat(DAY,day);
    srand(p->tm_sec); 
    struct Information  *first= acc->trade;
    struct Information  *tail = first;
    struct Information  *new_data;
    while(tail->nt) {tail = tail->nt;}
    new_data=malloc(sizeof(struct Information));
    printf("Welecom to the Invest Game Center\n");
    printf("Select a game to play and winnig the money !!\n");
    printf("---1.DICE 2.GUESS 3.EVENT---\n");
    scanf("%d",&game);

    switch(game){
        case 1:
            printf("This is the Dice game, please enter the investment amount\n");
            while(scanf("%d",&cost)&&cost>acc->money&&cost<=0){
                printf("you aren't enough money. Please retry or type -1 to exit.\n");
                if(cost = -1) return;
            }

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
            int again;
            printf("PRESS 1 TO PLAY AGAIN !!\n");
            scanf("%d",&again);
            if(again==1) game_center(acc);
            break;

        case 2:
            break;

        case 3:
            break;

        default:
          free(new_data);
          printf("invalid input.\n");
    }
}
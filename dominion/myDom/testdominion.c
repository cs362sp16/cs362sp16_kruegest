#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include "rngs.h"

int random_number(int min_num, int max_num){
    int result=0,low_num=0,hi_num=0;
    if(min_num<max_num)
    {
        low_num=min_num;
        hi_num=max_num+1; // this is done to include max_num in output.
    }else{
        low_num=max_num+1;// this is done to include max_num in output.
        hi_num=min_num;
    }
    
    result = (rand()%(hi_num-low_num))+low_num;
    return result;
}


void buyTestCards(struct gameState* state, int *coinCount, int playerTurn){
    *coinCount = state->coins;
    int confirmBuy;
    int randum;
    int loop;

  
    if(state->numBuys==-1){
      state->numBuys=1;
    }
    printf("numBuys%d\n",state->numBuys);
    for(loop = 0; loop<state->numBuys; loop++){
      if(*coinCount==-1){
        *coinCount = 6;
      }
            printf("coinCount: %d\n", *coinCount);

      if(state->coins==0){
        confirmBuy = buyCard(copper, state);
        if(confirmBuy == 0){
          *coinCount = state->coins;
          printf("buy copper\n");
        }
      }

      if(*coinCount < 2){
        confirmBuy = buyCard(copper, state);
        if(confirmBuy == 0){
          *coinCount = state->coins;
          printf("buy copper\n");
        }
      }

      if(*coinCount == 2){
        if(state->supplyCount[embargo]>10){  
          confirmBuy = buyCard(embargo, state);
          if(confirmBuy == 0){
            printf("buy embargo\n");
            *coinCount = state->coins;
          }else{
            confirmBuy = buyCard(estate, state);
            if(confirmBuy == 0){
              printf("buy estate\n");
              *coinCount = state->coins;
            }
          }
        }
      }  
    }
      

      if(*coinCount == 3){
        randum = random_number(1,1000);
        if((randum==1 || randum>5) && state->supplyCount[silver]>0){  
          confirmBuy = buyCard(silver, state);
          if(confirmBuy == 0){
            *coinCount = state->coins;
            printf("buy silver\n");

          }
        }else if(randum==2 && state->supplyCount[village]>0){
            confirmBuy = buyCard(village, state);
            if(confirmBuy == 0){
              *coinCount = state->coins;
              printf("buy village\n");
            }  
        }else if(randum==3 && state->supplyCount[great_hall]>0){
            confirmBuy = buyCard(great_hall, state);
            if(confirmBuy == 0){
              *coinCount = state->coins;
              printf("buy great_hall\n");
            } 
        }else if(randum==4 && state->supplyCount[steward]>0){
            confirmBuy = buyCard(steward, state);
            if(confirmBuy == 0){
              printf("buy steward\n");
              *coinCount = state->coins;
            }
        }else if(randum==5 && state->supplyCount[ambassador]>0){
            confirmBuy = buyCard(ambassador, state);
            if(confirmBuy == 0){
              printf("buy ambassador\n");
              *coinCount = state->coins;
            }
          } 
        } 
        

      if(*coinCount == 4){
         randum = random_number(1,9);
        if(randum==1 && state->supplyCount[feast]>0){  
          confirmBuy = buyCard(feast, state);
          if(confirmBuy == 0){
            printf("buy feast\n");
            *coinCount = state->coins;
          }
        }else if(randum==2 && state->supplyCount[gardens]>0){
            confirmBuy = buyCard(gardens, state);
            if(confirmBuy == 0){
              printf("buy gardens\n");
              *coinCount = state->coins;
            }  
        }else if(randum==3 && state->supplyCount[remodel]>0){
            confirmBuy = buyCard(remodel, state);
            if(confirmBuy == 0){
              printf("buy remodel\n");
              *coinCount = state->coins;
            } 
        }else if(randum==4 && state->supplyCount[smithy]>0){
            confirmBuy = buyCard(smithy, state);
            if(confirmBuy == 0){
              printf("buy smithy\n");
              *coinCount = state->coins;
            }  
        }else if(randum==5 && state->supplyCount[baron]>0){
            confirmBuy = buyCard(baron, state);
            if(confirmBuy == 0){
              printf("buy baron\n");
              *coinCount = state->coins;
            }
        }else if(randum==6 && state->supplyCount[treasure_map]>0){  
          confirmBuy = buyCard(treasure_map, state);
          if(confirmBuy == 0){
            printf("buy treasure_map\n");
            *coinCount = state->coins;
          }
        }else if(randum==7 && state->supplyCount[salvager]>0){
            confirmBuy = buyCard(salvager, state);
            if(confirmBuy == 0){
              printf("buy salvager\n");
              *coinCount = state->coins;
            }  
        }else if(randum==8 && state->supplyCount[sea_hag]>0){
            confirmBuy = buyCard(sea_hag, state);
            if(confirmBuy == 0){
              printf("buy sea_hag\n");
              *coinCount = state->coins;
            }  
        }else if(randum==9 && state->supplyCount[cutpurse]>0){
            confirmBuy = buyCard(cutpurse, state);
            if(confirmBuy == 0){
              printf("buy cutpurse\n");
              *coinCount = state->coins;
            }  
        }        
      }

      if(*coinCount == 5){
        randum = random_number(1,6);
        if(randum==1 && state->supplyCount[duchy]>0){  
          confirmBuy = buyCard(duchy, state);
          if(confirmBuy == 0){
            printf("buy duchy\n");
            *coinCount = state->coins;
          }
        }else if(randum==2 && state->supplyCount[minion]>0){
            confirmBuy = buyCard(minion, state);
            if(confirmBuy == 0){
              printf("buy minion\n");
              *coinCount = state->coins;
            }  
        }else if(randum==3 && state->supplyCount[council_room]>0){
            confirmBuy = buyCard(council_room, state);
            if(confirmBuy == 0){
              printf("buy council_room\n");
              *coinCount = state->coins;
            }
        }else if(randum==4 && state->supplyCount[tribute]>0){
            confirmBuy = buyCard(tribute, state);
            if(confirmBuy == 0){
              printf("buy tribute\n");
              *coinCount = state->coins;
            }
        }else if(randum==5 && state->supplyCount[mine]>0){
            confirmBuy = buyCard(mine, state);
            if(confirmBuy == 0){
              printf("buy mine\n");
              *coinCount = state->coins;
            }
        }else if(randum==6 && state->supplyCount[outpost]>0){  
          confirmBuy = buyCard(outpost, state);
          if(confirmBuy == 0){
            printf("buy outpust\n");
            *coinCount = state->coins;
          }
        }
      }

      if(*coinCount == 6){
        randum = random_number(1,10000);
        if(randum==1 && state->supplyCount[adventurer]>0){  
          confirmBuy = buyCard(adventurer, state);
          if(confirmBuy == 0){
            printf("buy adventurer\n");
            *coinCount = state->coins;
          }
        }else if(randum!=1 && state->supplyCount[gold]>0){
            confirmBuy = buyCard(gold, state);
            if(confirmBuy == 0){
              printf("gold\n");
              *coinCount = state->coins;
            }
          }        
      }

      if(*coinCount >= 8){
        printf("province\n");
        confirmBuy = buyCard(province, state);
        if(confirmBuy == 0){
          *coinCount = state->coins;
        }
        
      }

    }



int playActions(struct gameState* state, int *coinCount, int playerTurn){

 int loop;
 int confirmAction;
 int i;

  for(loop = 0; loop<15; loop++){
    for(i=0; i<5;i++){
      if(state->hand[playerTurn][i]<0){
        break;
      }else{
      if(state->hand[playerTurn][i] == smithy){
        smithyEffect(playerTurn, -1, state);
        printf("smithy played\n");
        return 0;
      }else if(state->hand[playerTurn][i] == village){
        villageEffect(playerTurn, -1, state);
        printf("village played\n");
        return 0;
      }else if(state->hand[playerTurn][i] == great_hall){
        great_hallEffect(playerTurn, -1, state);
        printf("great_hall played\n");
        return 0;
      }else if(state->hand[playerTurn][i] == council_room){
        council_roomEffect(playerTurn, -1, state);
        printf("council_room played\n");
        return 0;
      }else if(state->hand[playerTurn][i] == cutpurse){
        cardEffect(cutpurse, -1, -1, -1, state, -1, NULL );
        printf("cutpurse played\n");
        return 0;
      }else if(state->hand[playerTurn][i] == embargo){
        cardEffect(embargo, -1, -1, -1, state, -1, NULL );
        printf("embargo played\n");
        return 0;
      }else if(state->hand[playerTurn][i] == tribute){
        cardEffect(tribute, -1, -1, -1, state, -1, NULL );
        printf("tribute played\n");
        return 0;
      }

    }
  }
  }

  printf("endloop\n");

  return 0;
}







int main(int argc, char *argv[]){

  srand(time(NULL));
  int randomCard;
  int coinCount;
  int i;
  int x;
  int flae;
  int k[10];

  for(i=0;i<10;i++){
    randomCard = random_number(7,26);
    flae = 0;

    for(x=0;x<10;x++){
      if(k[x]==randomCard){
        flae = 1;
        i--;
        break;
      }
    }

    if(flae != 1 && randomCard!=0){
      k[i] = randomCard;
    }
  }

  struct gameState state;
  initializeGame(random_number(1,4), k, 42, &state);
  int stopMEPLEASE = 0;
  while(!isGameOver(&state) && stopMEPLEASE<1000){
    stopMEPLEASE++;
    printf("%d\n", stopMEPLEASE );
    int playerTurn = whoseTurn(&state);
    playActions(&state, &coinCount, playerTurn);
    buyTestCards(&state, &coinCount, playerTurn);
    endTurn(&state);
  }

  return 0; 

}

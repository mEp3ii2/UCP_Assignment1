#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "printer.h"
#include "movement.h"
#include "gameState.h"
#include "terminal.h"
#include "carMovement.h"

/* NAME: movement
 * PURPOSE: move the player around the map
 * IMPORTS: map, locInfo, carList
 * EXPORTS: NONE
 * ASSERTIONS:
 * 	PRE: locInfo has valid values, mao and car list have been populated
 * 	     the game has been printed out to the player before prompted for 
 * 	     movement.
 * 	POST: end condition has been met of either player has entered x to exit 
 * 	      player lost due to collision
 * 	      or player won by reaching the goal
 */

void movement(int **map,int*locInfo,int **carList)
{
    char mov='l';
    int row, col,move, moveR,moveC;

    row = locInfo[2];
    col = locInfo[3];

    /* While loop that takes in input unilt exit*/ 
    while (mov != 'x'){
        /* reset values*/
        move = 1;
        moveR = 0;
        moveC = 0;
        
        /* scans user input */
        disableBuffer();   
        scanf(" %c",&mov);   
        enableBuffer();
        
        
        /* convert to lower case */
        /* checks input to seem if valid move can be made */
        switch(mov)
        {
            case 'w':
                moveR = -1;
                move = moveCheck(map,row-1,col);
                break;
            case 'd':
                moveC = 1;
                move = moveCheck(map,row,col+1);
                break;
            case 's':
                moveR = 1;
                move = moveCheck(map,row+1,col);
                break;
            case 'a':
                moveC = -1;
                move = moveCheck(map,row,col-1);
                break;
            case 'x':
                /* user can enter x to exit early*/
                printf("\nGame Over!\n");
                break;
            default:
                break;    
        }
        /* move is valid*/
        if(move == 0)
        {
            /* move player*/
            movePlayer(map,row,col,moveR,moveC);
            row = row + moveR;
            col = col + moveC;
            locInfo[2]=row;
            locInfo[3]=col;

            /* check for collision
               if yes game over   */

            if(carMove(map,locInfo,carList)){
                printer(locInfo,map);
                printf("You lose!\n");
                mov = 'x';
            }
            /* check if player has reached the goal*/
            else
            {
                printer(locInfo,map);
                if(gameStat(locInfo)== 1)
                {
                    printf("You Win!\n");
                    mov = 'x';
                }
            }
            
               
        } 
           
    }
}


/* NAME: moveCheck
 * PURPOSE: check the validity of the inputed movement
 * IMPORTS: map, row, col
 * EXPORTS: 0 if not valid and 1 if valid
 * ASSERTIONS: map is populated
 */

int moveCheck(int **map, int row,int col)
{
    int result = 0;

    /* player is trying to move into a boundary */
    if(map[row+1][col+1] == 1)
    {
        result = 1;
    }

    return result;

}

/* NAME: movePlayer
 * PURPOSE: move player to new position on the map and fills in the prev player spot on map
 * IMPORTS: map, row, col, moveR, moveC
 * EXPORTS: NONE
 * ASSERTIONS:  moveCheck returned 0
 */

void movePlayer(int **map,int row,int col, int moveR, int moveC)
{
    
    map[row + moveR+1][col + moveC+1] = 3;

    /*Update prev player pos to previous state
    - either road or empty by checking its row*/
    if(row % 2 != 0)
    {
        
        map[row+1][col+1] = 5;
    }
    else
    {
        map[row+1][col+1] = 2;
    }
}


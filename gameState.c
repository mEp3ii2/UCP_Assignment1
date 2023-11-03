#include <stdlib.h>
#include <stdio.h>

/* NAME: gameState
 * PURPOSE: checks the position of the player to see if they have reached the goal
 * IMPORTS: locInfo
 * EXPORTS: 1 if the player has reached the goal else 0
 * ASSERTIONS: row and col are valid (player is on the map)
 */

int gameStat(int * locInfo)
{
    int row, col,goalRow, goalCol, result;
    
    row = locInfo[2];
    col = locInfo[3];
    goalRow = locInfo[4];
    goalCol = locInfo[5];
    result = 0;

    if(row == goalRow && col == goalCol)
    {
        return result = 1;
    }

    return result;
}

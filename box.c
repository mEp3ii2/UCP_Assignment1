#include <stdio.h>
#include <stdlib.h>

/* NAME: box
 * PURPOSE: fills the map array with the values
 * IMPORTS: map, locInfo
 * EXPORTS: NONE
 * ASSERTIONS: setup function has created the map array
 */

void box(int **map, int *locInfo){
    
    int i, j,playRow,playCol,row,col,goalRow,goalCol;
    playRow = locInfo[2];
    playCol = locInfo[3];
    row =  locInfo[0];
    col =  locInfo[1];
    goalRow = locInfo[4];
    goalCol = locInfo[5];


    for(i = 0; i < row + 2; i++)
    {
        for(j = 0; j < col + 2; j++)
        {
            /* Place player at 0,0 */
            if(i == playRow +1 && j ==  playCol + 1){
                map[i][j] = 3;
            }
            /* Place goal location */
            else if(i == goalRow + 1 && j == goalCol + 1)
            {
                map[i][j] = 4;
            }
            /* Place side borders */
            else if(j == 0 || j == col + 1)
            {
                map[i][j] = 1;
            }
            /* Place top & bottom border */
            else if(i == 0 || i == row + 1)
            {
                map[i][j] = 1;
            }
            /* Place roads */
            else if( i % 2 == 0 && (j != 0 || j != row + 1)){
                map[i][j] = 5;
            }
            /* Remaining space */
            else
            {
                map[i][j] = 2;
            }
        }
    }
}
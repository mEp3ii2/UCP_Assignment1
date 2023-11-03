#include <stdio.h>
#include <stdlib.h>
#include "printer.h"
#include "commands.h"
#include "newSleep.h"

/* NAME: printer
 * PURPOSE: prints out the contents of the map array
 * IMPORTS: locInfo, map
 * EXPORTS: NONE
 * ASSERTIONS: the map has been filled
 * REMARKS: int array has been used to store values
 *          LEGEND: 
 *          1 = * (boundary)
 *          2 = EMPTY SPACE
 *          3 = P (player char)
 *          4 = G (goal char)
 *          5 = . (road)
 *          6 = > (right moving car)
 *          7 = < (left moving car)
 */

void printer(int *locInfo,int **map){
    int i, j,row,col;
    row = locInfo[0];
    col = locInfo[1];
    
    refresh();

    for(i = 0; i < row+2; i++)
    {
        for(j = 0; j < col+2; j++)
        {
	    /* boundary */
            if(map[i][j] == 1)
            {
                printf("*");
            }

	    /* empty space */
            else if(map[i][j]==2)
            {
                printf(" ");
            }
	    
	    /* player */
            else if(map[i][j]==3)
            {
                printf(RedCol"P"ResetCol);
            }

	    /* goal */
            else if(map[i][j] == 4)
            {
                printf(GreenCol"G"ResetCol);
            }

	    /* road */
            else if(map[i][j] == 5)
            {
                printf(".");
            }

	    /* right car */
            else if(map[i][j] == 6)
            {
                printf(">");
            }

	    /* left car */
            else if(map[i][j] == 7)
            {
                printf("<");
            }
	    /* issue should not reach here */
            else {
                printf("!");
            }
        }

	/* new line for end of row */
        printf("\n");
    }

    /* print out the commands under the box when done */
    commands();
}

/* NAME: refresh
 * PURPOSE: clear the terminal
 * IMPORTS: NONE 
 * EXPORTS: NONE
 * ASSERTIONS: NONE
 * REMARKS: was originally planned to implement the nice terminal clear but wasn't implemented
 * 	    has been left as a function to allow for the implementation later instead of just having the
 * 	    system("clear") command in the printer method 
 */

void refresh()
{
    system("clear"); 
}


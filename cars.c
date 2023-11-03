#include <stdio.h>
#include <stdlib.h>
#include "random.h"

/* NAME: cars
 * PURPOSE: populate 2d car array with direction and position values for the cars
 * IMPORTS: map, locInfo, carList
 * EXPORTS: NONE
 * ASSERTIONS:
 * 	PRE: map and locInfo are filled and valid
 * 	POST: carList will have one car per even row
 */

void cars(int **map,int *locInfo, int **carList)
{
    /*direction to determine car face, 
    pos for where on row*/
    int i,direction,pos,j;
    j = 0;
    initRandom();

    /*determine direction and pos of car then
    feed in map array */
    for(i=2;i<locInfo[0];i+=2){
        
        
        pos = randomUCP(1,locInfo[1]);
        carList[j][0] = i;
        carList[j][1] = pos;
        printf("pos %d\n",pos);
        /* direction if car */
        /*if car on left wall face right*/
        if(pos == 1)
        {
            printf("Howdy1\n");
            direction = 0;
        }
        /*if car on right wall face left*/
        else if(pos == locInfo[1])
        {
            printf("Howdy2\n");
            direction = 1;
        }
        /*else random car direction*/
        else
        {
            printf("Howdy3\n");
            direction = randomUCP(0,1);
        }
        
        if(direction == 0)
        {
            map[i][pos] = 6;
            carList[j][2] = 6;
        }
        else
        {
            map[i][pos] = 7;
            carList[j][2] = 7;
        }
           
        j++;
    }
}

#include <stdio.h>
#include <stdlib.h>

/* NAME: carMove
 * PURPOSE: moves cars along the play area
 * IMPORTS: map, locInfo, carList
 * EXPORTS: NONE
 * ASSERTIONS: player has made a valid move
 */


int carMove(int **map,int *locInfo, int **carList)
{
    int i,carCount,row,trow,tcol,result;
    row = locInfo[0];
    carCount = (row - 1) / 2;
    result = 0;
    for(i = 0; i < carCount; i++)
    {
        
        trow = carList[i][0];
        tcol = carList[i][1];
        /* right facing car */
        if( carList[i][2] == 6)
        {
            /*car moves along road*/
            if( map[trow][tcol+1] == 5)
            {
                if(map[trow][tcol]!=3)
                {
                    map[trow][tcol] = 5;
                }
                map[trow][tcol+1] = 6;
                carList[i][1] = tcol+1;
            }
            /*car at border turn around */
            else if(map[trow][tcol+1] == 1)
            {
                /*check if player has moved into car while 
                car is turning around*/
                if(map[trow][tcol]==3){
                    /*player has collided*/
                    result = 1;
                }
                carList[i][2] = 7;
                map[trow][tcol] = 7;
                
            }
            /*car collides with player*/
            else if (map[trow][tcol+1] == 3)
            {
                map[trow][tcol] = 5;
                map[trow][tcol+1] = 6;
                result = 1;
            }
        }
        /* left facing car */
        else if( carList[i][2] == 7) 
        {
            /*car moves along road*/
            if (map[trow][tcol-1]==5)
            {
                if(map[trow][tcol]!=3)
                {
                    map[trow][tcol] = 5;
                }
                map[trow][tcol-1] = 7;
                carList[i][1] = tcol-1;
            }
            /*car at border turn around*/
            else if(map[trow][tcol-1] == 1)
            {
                /*check if player has moved into car while 
                car is turning around*/
                if(map[trow][tcol]==3){
                    /*player has collided*/
                    result = 1;
                }
                carList[i][2] = 6;
                map[trow][tcol] = 6;
            }
            /*car collides with player*/
            else if(map[trow][tcol-1] == 3)
            {
                map[trow][tcol] = 5;
                map[trow][tcol-1] = 7;
                result = 1;
            }
        }       
    }
    return result;
}
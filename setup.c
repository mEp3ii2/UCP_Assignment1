#include <stdio.h>
#include <stdlib.h>
#include "setup.h"
#include "box.h"
#include "printer.h"
#include "movement.h"
#include "cars.h"

/* NAME: setup
 * PURPOSE: setups the map and carList 2d arrays and calls other methods then free after finished
 * IMPORTS: locInfo
 * EXPORTS: NONE
 * ASSERTIONS: validator function returned 0
 */

void setup(int *locInfo)
{
    int i;
    int ** map;
    int ** carList;

    /*init carlist and map 2d arrays*/
    carList = (int**) malloc(((locInfo[0] - 1) / 2)*sizeof (int *) );
    for(i = 0; i < ((locInfo[0] - 1) / 2); i++ )
    {
        carList[i] = malloc( 3 * sizeof ( int ) );
    }
    
    map = (int**) malloc (( locInfo[0] + 2 ) * sizeof ( int * ) ) ;
    for(i = 0; i < ( 2 + locInfo[1] ); i++ )
    {
        map[i] = malloc(( 2 + locInfo[0] ) *sizeof(int));
    }

    /*call methods */
    box(map,locInfo); /*init creation of playspace*/
    cars(map,locInfo,carList); /*load cars*/
    printer(locInfo,map); /*init print to screen*/
    movement(map,locInfo,carList); /*main function to take inputs and run*/

    /*free everything*/
    for(i = 0; i < locInfo[0] + 2; i++)
    {    
        free(map[i]);
    }
    for(i=0;i<((locInfo[0]-1)/2);i++)
    {
        free(carList[i]);
    }
    
    free(map);
    free(carList);

}

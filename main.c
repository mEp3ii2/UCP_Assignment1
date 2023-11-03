#include <stdio.h>
#include <stdlib.h>
#include "setup.h"
#include "validator.h"

/* NAME: main
 * PURPOSE: takes the command line args in and calls validator function if valid calls setup
 * IMPORTS: argc, argv
 * EXPORTS: NONE
 * ASSERTIONS: NONE
 */

int main(int argc, char* argv[]){
    
    int * locInfo =(int*)malloc(6*sizeof(int));

    /* check if valid paramters have been passed*/
    if(validator(argc,argv) == 1)
    {
        
        printf("\nDesired input:\n");
        printf("./traffic <row number(>=3,ODD)> <col number(>=5)>\n");
        printf("\nGoodbye!\n");
    }
    else
    {
        /*valid parameters game starts*/

        locInfo[0] = atoi ( argv[1] ) ; /*row*/
        locInfo[1] = atoi ( argv[2] ) ; /*col*/
        locInfo[2] = 0 ; /*playrow*/
        locInfo[3] = 0 ; /*playcol*/
        locInfo[4] = locInfo[0]-1; /*goalrow*/
        locInfo[5] = locInfo[1]-1; /*goalcol*/
    
        setup(locInfo);
        
    }

    free(locInfo);

    return 0;    
}
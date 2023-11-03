#include <stdio.h>
#include <stdlib.h>

/* NAME: validator
 * PURPOSE: validates the command line arguments
 * IMPORTS: argc, argv
 * EXPORTS: 1 for invalid command line params else 0
 */

int validator(int argc, char*argv[]){
    
    int result,row,col;
    result = 0;
    /* checks the amount of command line args*/
    if(argc < 3){
        printf("Not enought command line args\n");
        result = 1;
    }
    else if(argc > 3){
        result = 1;
        printf("Warning! Too many command line args\n");
    }

    if (result != 1){
        row = atoi(argv[1]);
        col = atoi(argv[2]);
        /* check if the row and col args
        row must be odd and both must be greater then 3 */
        if (row < 3    )
        {
            printf("Invalid paramters for the game\n");
            printf("Row must be a value greater then 3\n");
            result = 1;
        }
        else if(row % 2 != 1)
        {
            printf("Invalid paramters for the game\n");
            printf("Row must be a odd number\n");
            result = 1;
        }
        else if (col < 5)
        {
            printf("Invalid parameters for the game\n");
            printf("Col must be at leat 5\n");
            result = 1;
        }
    }
    
    return result;
}

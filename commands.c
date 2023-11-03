#include <stdlib.h>
#include <stdio.h>
#include "commands.h"

/* NAME: commands
 * PURPOSE: print commands to the terminal for the user
 * IMPORTS: NONE
 * EXPORTS: NONE
 * ASSERTIONS: NONE
 */

void commands()
{
    printf("Press w to move up\n");
    printf("Press s to move down\n");
    printf("Press a to move left\n");
    printf("Press d to move right\n");
    printf("Press x to exit\n");
    printf("Enter movement: ");
}


#ifndef PRINTER_H
#define PRINTER_H
#define RedCol "\x1b[31m"
#define GreenCol "\x1b[32m"
#define ResetCol "\x1b[0m"
void printer(int *locInfo,int **map);
void refresh();
#endif
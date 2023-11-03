#ifndef MOVEMENT_H
#define MOVEMENT_H
void movement(int **map,int*locInfo, int **carList);
int moveCheck(int **map, int row,int col);
void movePlayer(int **map,int row,int col, int moveR, int moveC);
#endif
/*
 * 
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *
 *         Author:  Anthony Something (AS), 
 *
 * ==================================================================
 */

#include "Point.h"

int main()
{
  Point p1 = newPoint(0,0);
  Point p2 = newPoint(0,1);
  Point p3 = newPoint(1,0);
  printPoint(p1);
  printPoint(p2);
  printPoint(addPoints(p1,p2));
  printPoint(addPoints(p1,p3));
  printPoint(addPoints(p3,p2));
  printf("%f, %f, %f\n",distanceBetween(p1,p2),distanceBetween(p1,p3),distanceBetween(p2,p3));
  return 0;
}


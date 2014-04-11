/*
 * 
 *
 *       Filename:  Point.h
 *
 *    Description:  
 *
 *
 *         Author:  Anthony Something (AS), 
 *
 * ==================================================================
 */
#include "stdio.h"
#include "math.h"

typedef struct _point{
  float x;
  float y;
} Point;

Point addPoints(Point a, Point b);
Point newPoint(float x, float y);
float distanceBetween(Point a, Point b);

void printPoint(Point p);


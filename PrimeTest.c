/*
 * 
 *
 *       Filename:  PrimeTest.c
 *
 *    Description:  
 *
 *
 *         Author:  Anthony Something (AS), 
 *
 * ==================================================================
 */
#include "PrimeTest.h"
#include <math.h>

unsigned long largestPrime(unsigned long n)
{
  int i;
  int current=1;
  while(n%2 == 0)
  {
    n = n/2;
    current = 2;
  }
  for(i = 3; i <= sqrt(n); i = i + 2) // Go through all other possible divisors
  {
    while(n%i == 0)
    {
      current = i;
      n = n/i;
    }
  }

  if(n>current)
    current = n;

  return current;
}



#include <stdio.h>
#include "PrimeTest.h"
#include "List.h"


int main()
{

  Node *s = new_node(26);
  iterate_over_list(&largestPrime,s,4);
  debug_list(s);
  free_list(&s);
  printf("\n\n\n\n\n");
  s = gen_random_list(200000);
  iterate_over_list(&largestPrime,s,8); // Execute in four threads
  debug_list(s);
  free_list(&s);
  return 0;

}


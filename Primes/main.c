#include <stdio.h>
#include "PrimeTest.h"
#include "List.h"
#include <unistd.h>

int main()
{

  Node *s = new_node(26);
  iterate_over_list(&largestPrime,s);
  debug_list(s);
  free_list(&s);
  printf("\n\n\n\n\n");
  s = gen_random_list(90000);
  iterate_over_list(&largestPrime,s);
  debug_list(s);
  printf("Now we do ospina's function!");
  int i;
  for(i=0;i<100;i++)
    printf("\n +++++++++ ");
  sleep(2);
  iterate_over_list(&ospina_func,s);
  debug_list(s);
  free_list(&s);
  return 0;

}


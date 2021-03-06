/*
 * 
 *
 *       Filename:  List.c
 *
 *    Description:  
 *
 *
 *         Author:  Anthony Something (AS), 
 *
 * ==================================================================
 */

#include "List.h"
Node* gen_random_list(int size)
{
  Node *root = NULL;
  if(size <= 0)
  {
    goto listfail;
  }
  srand(time(NULL));
  root = new_node(rand());
  Node *new = root;
  Node *old; // We can save a bit of time with this hack.
  int i;
  for(i = size; i>0; i--)
  {
    old = new;
    new = new_node(rand());
    if(new == NULL)
    {
      // This is an error - our node was not allocated. So we need to print a fail message.
      goto listfail;
    }
    if(add_to_list(old, new) == 0)
    {
      // Since lists are linear, you can add a new node at any point in the list and it works
    // This means that I can simply pass my "add_to_list" function the previous element in the list, so it doesn't have to go through the whole thing the whole time.
    // This will save lots of time on larger lists.
    // This "if" statement checks to insure that we successfully added to our list. If not, we fail.
    goto listfail;
    }
    // End the loop.
  }
  return root;

listfail:
  printf("List was not created!");
  free_list(&root); // Our list might have been partially created, so we make sure to free all the memory we used.
  return NULL; // Our list could not be fully created, so we return NULL.
}









void iterate_over_list(unsigned long(*func)(unsigned long), Node *root)
{
  Node *scan = root;
  while(scan != NULL)
  {
    scan->result = (*func)(scan->num); // What just happend? I explained this in class. Hopefully.
    scan = scan->next;
  }
}


void free_list(Node **root) // Gah! A pointer to a pointer! We need to modify the root (set it to null,)  so we use a pointer to a pointer. Not really that complicated
{
  Node *current = *root; // We use the "*" to find the VALUE of the LOCATION of the LOCATION - So we set it to the location that "root" is pointing at.
  Node *next;
  while(current != NULL)
  {
    next = current->next;
    free(current);
    current = next;
  }
  *root = NULL; // We set our pointer back at NULL.
}

int add_to_list(Node *list, Node *toadd)
{
  if(list == NULL || toadd == NULL)
  {
    goto nullerror; // This is one of like 3 places where goto is useful.
    // Technically, it is not needed in this function, but I found it to be a useful demonstration.
    //
  }
  Node *scan = list;
  while(scan->next != NULL)
  {
    scan = scan->next;
  }
  scan->next = toadd;
  return 1;

nullerror:
  return 0;
}

int get_list_size(Node *list)
{
  if(list == NULL)
  {
    return -1; // Error condition
  }
  Node *scan = list->next;
  int accum = 1;
  while(scan->next != NULL)
  {
    accum++;
    scan = scan->next;
  }
  return accum;
}

Node* new_node(unsigned long x)
{
  Node *n = malloc(sizeof(Node));
  if(n == NULL)
  {
    return n; // Memory not allocated
  }
  n->num = x;
  n->next = NULL;
  return n;
}

void debug_list(Node *list)
{
  Node *scan = list;
  if(scan == NULL)
  {
    printf("List does not exist.");
    return; // Quickly leave the function.
  }
  while(scan != NULL)
  {
    printf("%lu has a result of %lu.\t",scan->num,scan->result);
    scan = scan->next;
  }
  printf("\n\n\n\n");
}


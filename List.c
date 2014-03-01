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
pthread_mutex_t curstart_mutex = PTHREAD_MUTEX_INITIALIZER;
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
    // End hte loop.
  }
  return root;

listfail:
  printf("List was not created!");
  free_list(&root); // Our list might have been partially created, so we make sure to free all the memory we used.
  return NULL; // Our list could not be fully created, so we return NULL.
}

void *thread_iteration(void *ptr)
{
    Node *ourNode;
    while(curstart_ptr != NULL)
    {
        pthread_mutex_lock(&curstart_mutex); // Other threads wait until this is unlocked to continue when they call "pthread_mutex_lock." We can use this to safely stall the threads from trying to access "curstart_ptr" while we modify it.
        ourNode = curstart_ptr;
        curstart_ptr = curstart_ptr->next;
pthread_mutex_unlock(&curstart_mutex); // We've done it. Now we know what ourNode is, so we do math on it:
        ourNode->result = (*fitr)(ourNode->num);
    }
    return NULL;
}

void iterate_over_list(unsigned long(*func)(unsigned long u), Node *root, int threads){

  // What's going on?
  // Hm?
  int io = 0;
  fitr = func;
  pthread_t ourthreads[threads]; //
  curstart_ptr = root;
  int i;
  for(i = 0; i < threads; i++)
  {
      pthread_create(&ourthreads[i],NULL,thread_iteration,NULL);
  }
  for(i = 0; i < threads; i++)
  {
      pthread_join(ourthreads[i], NULL);
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
}


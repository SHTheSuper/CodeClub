/*
 * 
 *
 *       Filename:  List.h
 *
 *    Description:  Creates a linked list
 *
 *
 *         Author:  Anthony Something (AS), 
 *
 * ==================================================================
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

typedef struct _node Node;

struct _node{
  unsigned long num;
  unsigned long result;
  Node *next;
};

int add_to_list(Node *list, Node *toadd);
int get_list_size(Node *list);
Node* new_node(unsigned long x);
void debug_list(Node *list);
Node* gen_random_list(int size);
void free_list(Node **root);
void iterate_over_list(unsigned long (*func)(unsigned long), Node *root);


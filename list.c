#include <stdlib.h>
#include <stdio.h>
#include "list.h"
List_ptr create_list(void)
{
  List_ptr new_list = (List_ptr)malloc(sizeof(List));
  new_list->head = NULL;
  new_list->last = NULL;
  new_list->count = 0;
  return new_list;
}
Node_ptr create_node(int value)
{
  Node_ptr new_node = (Node_ptr)malloc(sizeof(Node));
  new_node->value = value;
  new_node->next = NULL;
  return new_node;
}
int get_index(List_ptr list, int number)
{
  Node_ptr p_walk = list->head;
  int index = 0;
  while (p_walk != NULL)
  {
    if (p_walk->value == number)
    {
      return index;
    }
    p_walk = p_walk->next;
    index++;
  }
  return -1;
}
Status add_to_end(List_ptr list, int value)
{
  Node_ptr new_node = create_node(value);
  if (new_node == NULL)
  {
    return Failure;
  }
  if (list->head == NULL)
  {
    list->head = new_node;
  }
  else
  {
    list->last->next = new_node;
  }
  list->last = new_node;
  list->count++;
  return Success;
}
Status add_to_start(List_ptr list, int value)
{
  Node_ptr new_node = create_node(value);
  if (new_node == NULL)
  {
    return Failure;
  }
  new_node->next = list->head;
  list->head = new_node;
  list->count++;
  return Success;
}
Status add_unique(List_ptr list, int value)
{
  int is_unique = get_index(list, value);
  Status status = Success;
  if (is_unique == -1)
  {
    status = add_to_end(list, value);
  }
  return status;
}
Status remove_from_start(List_ptr list)
{
  Node_ptr p_walk = list->head;
  list->head = p_walk->next;
  free(p_walk);
  list->count--;
  return Success;
}
void display(List_ptr list)
{
  Node_ptr p_walk = list->head;
  while (p_walk != NULL)
  {
    printf("%d\n", p_walk->value);
    p_walk = p_walk->next;
  }
}
void destroy_list(List_ptr list)
{
  Node_ptr element = NULL;
  Node_ptr p_walk = list->head;
  while (p_walk != NULL)
  {
    element = p_walk;
    p_walk = p_walk->next;
    free(element);
  }
  free(list);
}
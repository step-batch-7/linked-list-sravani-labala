#include <stdlib.h>
#include <stdio.h>
#include "list.h"

List_ptr create_list(void)
{
  List_ptr new_list = (List_ptr)malloc(sizeof(List));
  if (new_list == NULL)
  {
    return new_list;
  }
  new_list->head = NULL;
  new_list->last = NULL;
  new_list->count = 0;
  return new_list;
}

Node_ptr create_node(int value)
{
  Node_ptr new_node = (Node_ptr)malloc(sizeof(Node));
  if (new_node == NULL)
  {
    return new_node;
  }
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
  Node_ptr *ptr_to_set = &list->head;
  if (list->head != NULL)
  {
    ptr_to_set = &list->last->next;
  }
  *ptr_to_set = new_node;
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
  Status status = Failure;
  if (is_unique == -1)
  {
    status = add_to_end(list, value);
  }
  return status;
}

Status remove_from_start(List_ptr list)
{
  Node_ptr p_walk = list->head;
  if (p_walk == NULL)
  {
    return Failure;
  }
  list->head = p_walk->next;
  free(p_walk);
  list->count--;
  return Success;
}

Status remove_from_end(List_ptr list)
{
  Node_ptr p_walk = list->head;
  if (p_walk == NULL)
  {
    return Failure;
  }
  int index = 1;
  while (index < list->count - 1)
  {
    p_walk = p_walk->next;
    index++;
  }
  p_walk->next = NULL;
  free(list->last);
  list->last = p_walk;
  list->count--;
  return Success;
}

Status remove_at(List_ptr list, int position)
{
  if ((list->count - 1) < position || position < 0)
  {
    return Failure;
  };
  if (position == 0)
  {
    return remove_from_start(list);
  }
  if (position == (list->count - 1))
  {
    return remove_from_end(list);
  }
  Node_ptr p_walk = list->head;
  int index = 0;
  while (index < (position - 1))
  {
    p_walk = p_walk->next;
    index++;
  }
  Node_ptr remove = p_walk->next;
  p_walk->next = remove->next;
  free(remove);
  list->count--;
  return Success;
}

Status insert_at(List_ptr list, int value, int position)
{
  if ((list->count + 1) < position || position < 0)
  {
    return Failure;
  }
  if (position == 0)
  {
    return add_to_start(list, value);
  }
  if (position == (list->count))
  {
    return add_to_end(list, value);
  }
  Node_ptr new_node = create_node(value);
  if (new_node == NULL)
  {
    return Failure;
  }
  Node_ptr p_walk = list->head;
  int index = 0;
  while (index < (position - 1))
  {
    p_walk = p_walk->next;
    index++;
  }
  new_node->next = p_walk->next;
  p_walk->next = new_node;
  list->count++;
  return Success;
}

Status remove_first_occurrence(List_ptr list, int value)
{
  int index = get_index(list, value);
  if (index == -1)
  {
    return Failure;
  }
  return remove_at(list, index);
}

Status remove_all_occurrences(List_ptr list, int value)
{
  int index = get_index(list, value);
  Status status = Failure;
  while (index != -1)
  {
    status = remove_at(list, index);
    index = get_index(list, value);
  }
  return status;
}

Status is_number_exist(List_ptr list, int value)
{
  int index = get_index(list, value);
  if (index == -1)
  {
    return Failure;
  }
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

Status clear_list(List_ptr list)
{
  Node_ptr element = NULL;
  Node_ptr p_walk = list->head;
  while (p_walk != NULL)
  {
    element = p_walk;
    p_walk = p_walk->next;
    free(element);
  }
  list->head = NULL;
  list->last = NULL;
  list->count = 0;
  return Success;
}

void destroy_list(List_ptr list)
{
  clear_list(list);
  free(list);
}
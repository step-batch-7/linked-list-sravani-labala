#include <stdio.h>
#include "list.h"

void print_status(Status status)
{
  printf("%s\n", status ? "Success" : "Failure");
}

Status compare(List_ptr list, int position, int value)
{
  if (position > list->count - 1 || position < 0)
  {
    return Failure == value;
  }
  Node_ptr p_walk = list->head;
  while (position--)
  {
    p_walk = p_walk->next;
  }
  return p_walk->value == value;
}

void test_add_to_end()
{
  List_ptr list = create_list();
  add_to_end(list, 1);
  print_status(compare(list, 0, 1));
  add_to_end(list, 2);
  print_status(compare(list, 1, 2));
  destroy_list(list);
}

void test_add_to_start()
{
  List_ptr list = create_list();
  add_to_start(list, 1);
  print_status(compare(list, 0, 1));
  add_to_start(list, 2);
  print_status(compare(list, 0, 2));
  destroy_list(list);
}

void test_add_unique()
{
  List_ptr list = create_list();
  add_to_end(list, 1);
  add_unique(list, 0);
  print_status(compare(list, 1, 0));
  add_unique(list, 1);
  print_status(compare(list, 2, Failure));
  destroy_list(list);
}

void test_clear_list()
{
  List_ptr list = create_list();
  clear_list(list);
  add_to_end(list, 3);
  clear_list(list);
  print_status(compare(list, 0, Failure));
  destroy_list(list);
}

void test_insert_at()
{
  List_ptr list = create_list();
  insert_at(list, 1, 0);
  print_status(compare(list, 0, 1));
  insert_at(list, 2, 0);
  print_status(compare(list, 0, 2));
  insert_at(list, 3, 1);
  print_status(compare(list, 1, 3));
  insert_at(list, 4, 2);
  print_status(compare(list, 2, 4));
  insert_at(list, 5, 4);
  print_status(compare(list, 4, 5));
  insert_at(list, 6, -1);
  print_status(compare(list, -1, Failure));
  insert_at(list, 6, 10);
  print_status(compare(list, 10, Failure));
  destroy_list(list);
}

void test_remove_from_start()
{
  List_ptr list = create_list();
  remove_from_start(list);
  add_to_end(list, 1);
  remove_from_start(list);
  print_status(compare(list, 0, Failure));
  add_to_end(list, 1);
  add_to_end(list, 2);
  remove_from_start(list);
  print_status(compare(list, 0, 2));
  destroy_list(list);
}

void test_remove_from_end()
{
  List_ptr list = create_list();
  remove_from_end(list);
  add_to_end(list, 1);
  remove_from_end(list);
  print_status(compare(list, 0, Failure));
  add_to_end(list, 1);
  add_to_end(list, 2);
  remove_from_end(list);
  print_status(compare(list, 1, Failure));
  destroy_list(list);
}

void test_remove_first_occurrence()
{
  List_ptr list = create_list();
  remove_first_occurrence(list, 1);
  add_to_end(list, 1);
  remove_first_occurrence(list, 1);
  print_status(compare(list, 0, Failure));
  add_to_end(list, 1);
  remove_first_occurrence(list, 2);
  print_status(compare(list, 0, 1));
  add_to_end(list, 1);
  remove_first_occurrence(list, 1);
  print_status(compare(list, 0, 1));
  print_status(compare(list, 1, Failure));
  destroy_list(list);
}

void test_remove_all_occurrences()
{
  List_ptr list = create_list();
  remove_all_occurrences(list, 1);
  add_to_end(list, 1);
  remove_all_occurrences(list, 1);
  print_status(compare(list, 0, Failure));
  add_to_end(list, 1);
  add_to_end(list, 2);
  add_to_end(list, 1);
  remove_all_occurrences(list, 1);
  print_status(compare(list, 0, 2));
  print_status(compare(list, 1, Failure));
  destroy_list(list);
}

void test_remove_at()
{
  List_ptr list = create_list();
  remove_at(list, 0);
  add_to_end(list, 1);
  remove_at(list, 0);
  print_status(compare(list, 0, Failure));
  add_to_end(list, 1);
  add_to_end(list, 2);
  add_to_end(list, 3);
  add_to_end(list, 4);
  add_to_end(list, 5);
  remove_at(list, 0);
  print_status(compare(list, 0, 2));
  remove_at(list, 1);
  print_status(compare(list, 1, 4));
  remove_at(list, 3);
  print_status(compare(list, 2, 5));
  remove_at(list, 2);
  print_status(compare(list, 2, Failure));
  remove_at(list, -5);
  print_status(compare(list, 0, 2));
  destroy_list(list);
}

int main(void)
{
  test_add_to_end();
  test_add_to_start();
  test_add_unique();
  test_clear_list();
  test_insert_at();
  test_remove_from_start();
  test_remove_from_end();
  test_remove_first_occurrence();
  test_remove_all_occurrences();
  test_remove_at();
  return 0;
}
#include <stdio.h>
#include "../list.h"

void print_status(Status status, char *message)
{
  printf("%s\n%s\n\n", message, status ? "Success" : "Failure");
}

int compare(List_ptr list, int position, int value, int count)
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
  return p_walk->value == value && list->count == count;
}

void test_add_to_end()
{
  printf("-------add_to_end------\n");
  int result;
  char *message = NULL;
  List_ptr list = create_list();

  message = "should be able to add at the end for an empty list";
  add_to_end(list, 1);
  result = compare(list, 0, 1, 1);
  print_status(result, message);

  message = "should be able to add at the end of the larger list";
  add_to_end(list, 2);
  result = compare(list, 1, 2, 2);
  print_status(result, message);

  destroy_list(list);
}

void test_add_to_start()
{
  printf("-------add_to_start------\n");
  int result;
  char *message = NULL;
  List_ptr list = create_list();

  message = "should be able to add at the start for an empty list";
  add_to_start(list, 1);
  result = compare(list, 0, 1, 1);
  print_status(result, message);

  message = "should be able to add at the start of the larger list";
  add_to_start(list, 2);
  result = compare(list, 0, 2, 2);
  print_status(result, message);

  destroy_list(list);
}

void test_add_unique()
{
  printf("-------add_unique------\n");
  int result;
  char *message = NULL;
  List_ptr list = create_list();
  add_to_end(list, 1);

  message = "should add the value to the list if it doesn't exist in the list";
  add_unique(list, 0);
  result = compare(list, 1, 0, 2);
  print_status(result, message);

  message = "should not add the value to the list if it already exists in the list";
  add_unique(list, 1);
  result = compare(list, 2, Failure, 2);
  print_status(result, message);

  destroy_list(list);
}

void test_clear_list()
{
  printf("-------clear_list------\n");
  int result;
  char *message = NULL;
  List_ptr list = create_list();
  clear_list(list);
  add_to_end(list, 3);

  message = "should clear all the values in the list and set the list to zero";
  clear_list(list);
  result = compare(list, 0, Failure, 0);
  print_status(result, message);

  destroy_list(list);
}

void test_insert_at()
{
  printf("-------insert_at------\n");
  int result;
  char *message = NULL;
  List_ptr list = create_list();

  message = "should be able to add at the position 0 for empty list";
  insert_at(list, 1, 0);
  result = compare(list, 0, 1, 1);
  print_status(result, message);

  message = "should be able to add at the position 0 for larger list";
  insert_at(list, 2, 0);
  result = compare(list, 0, 2, 2);
  print_status(result, message);

  message = "should be able to add at the middle of the list";
  insert_at(list, 3, 1);
  result = compare(list, 1, 3, 3);
  print_status(result, message);

  message = "should be able to add at the last position of the list";
  insert_at(list, 4, 2);
  result = compare(list, 2, 4, 4);
  print_status(result, message);

  message = "should be able to add at the end of the larger list";
  insert_at(list, 5, 4);
  result = compare(list, 4, 5, 5);
  print_status(result, message);

  message = "should not add if the position is invalid (negative position)";
  insert_at(list, 6, -1);
  result = compare(list, -1, Failure, 5);
  print_status(result, message);

  message = "should not add if the position is invalid (position greater than the list)";
  insert_at(list, 6, 10);
  result = compare(list, 10, Failure, 5);
  print_status(result, message);

  destroy_list(list);
}

void test_remove_from_start()
{
  printf("-------remove_from_start------\n");
  int result;
  char *message = NULL;
  List_ptr list = create_list();
  remove_from_start(list);
  add_to_end(list, 1);

  message = "should be able to remove for a list containing one value";
  remove_from_start(list);
  result = compare(list, 0, Failure, 0);
  print_status(result, message);

  add_to_end(list, 1);
  add_to_end(list, 2);

  message = "should be able to remove at the start of the larger list";
  remove_from_start(list);
  result = compare(list, 0, 2, 1);
  print_status(result, message);

  destroy_list(list);
}

void test_remove_from_end()
{
  printf("-------remove_from_end------\n");
  int result;
  char *message = NULL;
  List_ptr list = create_list();
  remove_from_end(list);
  add_to_end(list, 1);

  message = "should be able to remove for the list containing one value";
  remove_from_end(list);
  result = compare(list, 0, Failure, 0);
  print_status(result, message);

  add_to_end(list, 1);
  add_to_end(list, 2);

  message = "should be able to remove at the end of the larger list";
  remove_from_end(list);
  result = compare(list, 1, Failure, 1);
  print_status(result, message);

  destroy_list(list);
}

void test_remove_first_occurrence()
{
  printf("-------remove_first_occurrence------\n");
  int result;
  char *message = NULL;
  List_ptr list = create_list();
  remove_first_occurrence(list, 1);
  add_to_end(list, 1);

  message = "should remove only the first occurrence of the value in the list containing one element if it exist";
  remove_first_occurrence(list, 1);
  result = compare(list, 0, Failure, 0);
  print_status(result, message);

  add_to_end(list, 1);

  message = "should not remove anything if the value doesn't exist in the list containing one element";
  remove_first_occurrence(list, 2);
  result = compare(list, 0, 1, 1);
  print_status(result, message);

  add_to_end(list, 1);

  message = "should remove only the first occurrence of the value in the larger list if it exist";
  remove_first_occurrence(list, 1);
  result = compare(list, 0, 1, 1);
  print_status(result, message);

  message = "should not remove anything if the value doesn't exist in the larger list";
  remove_first_occurrence(list, 5);
  result = compare(list, 0, 1, 1);
  print_status(result, message);

  destroy_list(list);
}

void test_remove_all_occurrences()
{
  printf("-------remove_all_occurrences------\n");
  int result;
  char *message = NULL;
  List_ptr list = create_list();
  remove_all_occurrences(list, 1);
  add_to_end(list, 1);

  message = "should remove all occurrences of the value in the single element list if it exist";
  remove_all_occurrences(list, 1);
  result = compare(list, 0, Failure, 0);
  print_status(result, message);

  add_to_end(list, 1);
  add_to_end(list, 2);
  add_to_end(list, 1);

  message = "should remove all occurrences of the value in the list if it exist";
  remove_all_occurrences(list, 1);
  result = compare(list, 0, 2, 1);
  print_status(result, message);

  message = "should not remove anything if the value doesn't exist in the list";
  remove_all_occurrences(list, 3);
  result = compare(list, 0, 2, 1);
  print_status(result, message);

  destroy_list(list);
}

void test_remove_at()
{
  printf("-------remove_at------\n");
  int result;
  char *message = NULL;
  List_ptr list = create_list();
  remove_at(list, 0);
  add_to_end(list, 1);

  message = "should be able to remove at position 0 for a list containing one value";
  remove_at(list, 0);
  result = compare(list, 0, Failure, 0);
  print_status(result, message);

  add_to_end(list, 1);
  add_to_end(list, 2);
  add_to_end(list, 3);
  add_to_end(list, 4);
  add_to_end(list, 5);

  message = "should be able to remove at the position 0 for larger list";
  remove_at(list, 0);
  result = compare(list, 0, 2, 4);
  print_status(result, message);

  message = "should be able to remove at the middle of the list";
  remove_at(list, 1);
  result = compare(list, 1, 4, 3);
  print_status(result, message);

  message = "should be able to remove at the end of the larger list";
  remove_at(list, 3);
  result = compare(list, 2, 5, 3);
  print_status(result, message);

  message = "should not remove if the position is invalid (position greater than the list)";
  remove_at(list, 2);
  result = compare(list, 2, Failure, 2);
  print_status(result, message);

  message = "should not remove if the position is invalid (negative position)";
  remove_at(list, -5);
  result = compare(list, 0, 2, 2);
  print_status(result, message);

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
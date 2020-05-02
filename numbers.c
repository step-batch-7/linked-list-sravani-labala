#include <stdio.h>
#include "list.h"

void clear()
{
  while ((getchar()) != '\n')
    ;
}

void print_message(Status status)
{
  printf("%s\n", status ? "Success" : "Failure");
}

void operate(List_ptr list, char choice)
{
  int value, position;
  switch (choice)
  {
  case 'a':
    clear();
    scanf("%d", &value);
    print_message(add_to_end(list, value));
    break;
  case 'b':
    clear();
    scanf("%d", &value);
    print_message(add_to_start(list, value));
    break;
  case 'c':
    clear();
    scanf("%d %d", &value, &position);
    print_message(insert_at(list, value, position));
    break;
  case 'd':
    clear();
    scanf("%d", &value);
    print_message(add_unique(list, value));
    break;
  case 'e':
    print_message(remove_from_start(list));
    break;
  case 'f':
    print_message(remove_from_end(list));
    break;
  case 'g':
    clear();
    scanf("%d", &position);
    print_message(remove_at(list, position));
    break;
  case 'h':
    clear();
    scanf("%d", &value);
    print_message(remove_first_occurrence(list, value));
    break;
  case 'i':
    clear();
    scanf("%d", &value);
    print_message(remove_all_occurrences(list, value));
    break;
  case 'j':
    print_message(clear_list(list));
    break;
  case 'k':
    clear();
    scanf("%d", &value);
    print_message(is_number_exist(list, value));
    break;
  case 'l':
    display(list);
    break;
  default:
    printf("Invalid operation\n");
    break;
  }
}

void display_menu(void)
{
  printf("Main Menu\n\
---------\n\
(a) add a number to the end of the list\n\
(b) add a number to the start of the list\n\
(c) insert a number at a given position in the list\n\
(d) add a unique item on the list at the end(if it already exists, do not insert)\n\
(e) remove a number from the beginning of the list\n\
(f) remove a number from the end of the list\n\
(g) remove a number from a given position in the list\n\
(h) remove first occurrence of a number\n\
(i) remove all occurrences of a number\n\
(j) clear the whole list\n\
(k) check if a number exists in the list\n\
(l) display the list of numbers\n\
(m) exit\n\
\n\
Please enter the alphabet of the operation you would like to perform\n");
}

int main(void)
{
  List_ptr list = create_list();
  if (list == NULL)
  {
    printf("No memory in heap");
    return 0;
  }
  char choice;
  display_menu();
  scanf("%c", &choice);
  while (choice != 'm')
  {
    operate(list, choice);
    clear();
    display_menu();
    scanf("%c", &choice);
  }
  destroy_list(list);
  return 0;
}
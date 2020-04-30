#include <stdio.h>
#include "list.h"
int main(void)
{
  List_ptr list = create_list();
  add_to_end(list, 1);
  add_to_end(list, 1);
  add_to_end(list, 2);
  add_to_end(list, 1);
  add_to_end(list, 3);
  add_to_end(list, 1);
  display(list);
  remove_all_occurrences(list, 1);
  display(list);
  destroy_list(list);
  return 0;
}
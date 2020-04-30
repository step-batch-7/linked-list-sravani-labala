#include <stdio.h>
#include "list.h"
int main(void)
{
  List_ptr list = create_list();
  add_to_end(list, 1);
  add_to_start(list, 3);
  add_unique(list, 2);
  remove_from_start(list);
  remove_from_end(list);
  display(list);
  clear_list(list);
  add_to_start(list, 7);
  display(list);
  destroy_list(list);
  return 0;
}
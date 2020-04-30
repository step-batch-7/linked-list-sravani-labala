#include <stdio.h>
#include "list.h"
int main(void)
{
  List_ptr list = create_list();
  add_to_end(list, 1);
  add_to_start(list, 3);
  add_unique(list, 2);
  add_unique(list, 1);
  display(list);
  return 0;
}
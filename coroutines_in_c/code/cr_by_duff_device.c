#include <stdio.h>

int fun1(void)
{
  static int i, state = 0;
  switch (state)
  {
    case 0: /* start of function */
    for (i = 0; i < 10; i++)
    {
      state = 1; /* so we will come back to ``case 1'' */
      return i;
      case 1:; /* resume control straight after the return */
    }
  }
}

  
int main(void)
{
  int i = -1;
  int j=0;
  for (j = 0 ; j < 20 ; j++)
  {
    i = fun1();
    printf("i = %d\n", i);
  }
  return 0;
}

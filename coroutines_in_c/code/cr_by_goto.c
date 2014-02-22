#include <stdio.h>

int fun1(void)
{
  static int i, state = 0;
  switch (state)
  {
    case 0: goto LABEL0;
    case 1: goto LABEL1;
  }
  LABEL0: /* start of function */
  for (i = 0; i < 10; i++)
  {
    state = 1; /* so we will come back to LABEL1 */
    return i;
    LABEL1:; /* resume control straight after the return */
  }
  return -2;
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

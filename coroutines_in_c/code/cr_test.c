#include <stdio.h>

#define crBegin static int state=0; switch(state) { case 0:
//#define crReturn(i,x) do { state=i; return x; case i:; } while (0)
#define crReturn(x) do { state=__LINE__; return x; case __LINE__:; } while (0)
#define crFinish }

int fun1(void)
{
  static int i;
  crBegin;
  while(1)
  {
    int c = getchar();
    if (c==EOF)
      break;
    if (c=='z')
    {
    #if 0
      static int len; // static is needed, why??
      len = getchar();
    #endif
      int len = getchar();
      printf("xx len=%d\n", len);
      printf("yy len=%p\n", &len);
      c = getchar();
      while(len--)
      {
        printf("len=%d\n", len);
        printf("xxyy len=%p\n", &len);
        crReturn(c);
      }
    }
    else
      crReturn(c);
  }
  crFinish;
}


int main(int argc, char *argv[])
{
  int c;
  #if 0
  while((c = fun1()) != EOF)
    printf("c=%d\n", c);
  #endif
  c = fun1();
  printf("c=%d\n", c);
  c = fun1();
  printf("c=%d\n", c);
  c = fun1();
  printf("c=%d\n", c);
  c = fun1();
  printf("c=%d\n", c);
  c = fun1();
  printf("c=%d\n", c);

  return 0;
}

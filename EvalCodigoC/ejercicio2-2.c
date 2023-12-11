#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

/*
int fib(int x) {
    if (x == 0) {
        return 0;
    } else if (x == 1) {
        return 1;
    } else {
        return fib(x - 1) + fib(x - 2);
    }
}
    */


unsigned long fib(unsigned int n) {
  if (n == 0) {
    return 0;
  }
  else if (n == 1 || n == 2) {
    return 1;
  }
 
  unsigned long prev = 1;
  unsigned long cur = 1;
 
  unsigned int i;
 
  for (i = 3; i <= n; i++) {
    unsigned long tmp = cur;
    cur = cur + prev;
    prev = tmp;
  }
 
  return cur;
}
int main(int argc, char const *argv[])
{
    for (size_t i = 0; i < 45; ++i) {
        printf("%ld\n", fib(i));
    }
    return 0;
}

 

#include <stdio.h> 
#include <stdlib.h>


 /*


*/

unsigned long long int factorial( int n) {
   unsigned long long int result = 1;

  for (int i = 2; i <= n; i++) {
    result *= (int)i;
  }

  return result;
}

int main(int argc, char *argv[]) {
    int i = 12, j = 3, f = 0;

    if (argc == 1) {
        printf("Factorial of %d is %llu\n", i, factorial(i));
    } else {
        j = atoi(argv[1]);
        for (f = 0; f < j; f++) {
            printf("Factorial of %d is %llu\n", f, factorial(f));
        }
    }

    return 0;
}


 
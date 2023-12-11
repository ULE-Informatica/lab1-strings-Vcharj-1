
#include <stdio.h> 
#include <stdlib.h>


 /*
 DCL10-C. Maintain the contract between the writer and caller of variadic functions
• ¿Qué hace el siguiente segmento de código?

 The function average() takes a variable number of positive integer arguments and returns the average of those arguments.

• ¿Para qué se utiliza la variable va_eol?
  
  The va_eol enumeration signals the end of the variable-length argument list to exit of the while loop,
  allowing the function to process all of the provided arguments.

• Incorpora el segmento de código en un programa .c de tal forma que no encon-
tremos nigún warning cuando compilamos en gcc con los siguientes parámetros
(std=c11). Dado que es C, elimina aquellos que no aplican. Escribe en la respuesta
aquellos que se ven afectados y son eliminados.

los que no aplican:
cc1: error: command-line option ‘-Wctor-dtor-privacy’ is valid for C++/ObjC++ but not for C [-Werror]
cc1: error: command-line option ‘-Wnoexcept’ is valid for C++/ObjC++ but not for C [-Werror]
cc1: error: command-line option ‘-Wold-style-cast’ is valid for C++/ObjC++ but not for C [-Werror]
cc1: error: command-line option ‘-Woverloaded-virtual’ is valid for C++/ObjC++ but not for C [-Werror]
cc1: error: command-line option ‘-Wsign-promo’ is valid for C++/ObjC++ but not for C [-Werror]
cc1: error: command-line option ‘-Wstrict-null-sentinel’ is valid for C++/ObjC++ but not for C [-Werror]
=================================================================================================
(base) dimi@dimi:~/cpp$ gcc -Werror -Wall -Wextra -pedantic -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wundef -Wno-unused -Wno-variadic-macros -Wno-parentheses -fdiagnostics-show-option ejemplo4-1.c -std=c11
cc1: error: command-line option ‘-Wctor-dtor-privacy’ is valid for C++/ObjC++ but not for C [-Werror]
cc1: error: command-line option ‘-Wnoexcept’ is valid for C++/ObjC++ but not for C [-Werror]
cc1: error: command-line option ‘-Wold-style-cast’ is valid for C++/ObjC++ but not for C [-Werror]
cc1: error: command-line option ‘-Woverloaded-virtual’ is valid for C++/ObjC++ but not for C [-Werror]
cc1: error: command-line option ‘-Wsign-promo’ is valid for C++/ObjC++ but not for C [-Werror]
cc1: error: command-line option ‘-Wstrict-null-sentinel’ is valid for C++/ObjC++ but not for C [-Werror]
cc1: all warnings being treated as errors
(base) dimi@dimi:~/cpp$ gcc -Werror -Wall -Wextra -pedantic -Wcast-align -Wcast-qual -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-include-dirs -Wredundant-decls -Wshadow -Wstrict-overflow=5 -Wundef -Wno-unused -Wno-variadic-macros -Wno-parentheses -fdiagnostics-show-option ejemplo4-1.c -std=c11
(base) dimi@dimi:~/cpp$ valgrind --leak-check=yes ./ejemplo4
==381298== Memcheck, a memory error detector
==381298== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==381298== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==381298== Command: ./ejemplo4
==381298== 
The average is 3 
==381298== 
==381298== HEAP SUMMARY:
==381298==     in use at exit: 0 bytes in 0 blocks
==381298==   total heap usage: 1 allocs, 1 frees, 1,024 bytes allocated
==381298== 
==381298== All heap blocks were freed -- no leaks are possible
==381298== 
==381298== For lists of detected and suppressed errors, rerun with: -s
==381298== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

*/
#include <stdarg.h>

enum { va_eol = -1 };

unsigned int average(int first, ...) {
    unsigned int count = 0;
    unsigned int sum = 0;
    int i = first;
    va_list args;
    va_start(args, first);
    
    while ((int)i != va_eol) {
        sum += (int)i;
        count++;
        i = va_arg(args, int);
    }
    
    va_end(args);
    return (count ? (sum / count) : 0);
}

 

void func(int expr){

   int i = 4;     
    
   switch (expr) {  
      case 0:
         i = 17;
      break;     
/* Falls through into default code */   
   default: 
      printf("%d\n" , i);
   
   } 
   return;
} 

int main(void) { 
   func(0);
   int avg = average(1, 4, 6, 4, 1, va_eol);
   printf("The average is %d \n", avg);

}


 
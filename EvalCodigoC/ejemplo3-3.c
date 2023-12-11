
#include <stdio.h> 
#include <stdlib.h>


 /*

1. ¿Que hace el siguiente segmento de codigo si invocamos la funcion func con un 0? 

   If we call the function with 0 it will :

    1. (i) will be initialized to (4)
    2. f(int i) will take the value of (4)
    3. (0) will be evaluate in the switch-case 
    4. finallyy print -> (17)

2. De haber algun problema ¿Podrıas decir la lınea en la que se encuentra? 

      noncompliant code example declares variables and contains executable statements before the first case label within the switch statement
      int i = 4;  statement will never be executed [-Wswitch-unreachable]      
      f(i); 
      

3. Crea un fichero con un main y ejecuta el segmento de codigo. 

4. Propon una solucion al ejemplo que cumpla con las normal del CMU 

DCL41-C. Do not declare variables inside a switch statement before the first case label 

5. Realiza un analisis estatico del codigo erroneo y copia en tu solucion el resultado. Utilizalasherramientas: 
         (a) rats 
         (b) cppchecker 
         (c) splint 
         (d) vera++ 
         (e) valgrind

(base) dimi@dimi:~/cpp$ splint ejemplo3-3.c
Splint 3.1.2 --- 21 Feb 2021

ejemplo3-3.c: (in function func)
ejemplo3-3.c:45:12: Fall through case (no preceding break)
  Execution falls through from the previous case (use @fallthrough@ to mark
  fallthrough cases). (Use -casebreak to inhibit warning)
ejemplo3-3.c:48:12: Fall through case (no preceding break)
ejemplo3-3.c:43:17: Statement after switch is not a case: int i = 4
  The first statement after a switch is not a case. (Use -firstcase to inhibit
  warning)

Finished checking --- 3 code warnings
=================================================================================================
(base) dimi@dimi:~/cpp$ splint ejemplo3-3.c
Splint 3.1.2 --- 21 Feb 2021

Finished checking --- no warnings
=================================================================================================
valgrind --leak-check=yes ./ejemplo3-3
==350572== Memcheck, a memory error detector
==350572== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==350572== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==350572== Command: ./ejemplo3-3
==350572== 
==350572== 
==350572== HEAP SUMMARY:
==350572==     in use at exit: 0 bytes in 0 blocks
==350572==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==350572== 
==350572== All heap blocks were freed -- no leaks are possible
==350572== 
==350572== For lists of detected and suppressed errors, rerun with: -s
==350572== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
=================================================================================================
*/
extern void f(int i); 

void func(int expr){

   int i = 4;     
   f(i);   
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

}

 
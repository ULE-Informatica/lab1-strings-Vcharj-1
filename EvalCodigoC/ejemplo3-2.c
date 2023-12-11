
#include <stdio.h> 
#include <stddef.h> 
#include <stdlib.h>
#include <string.h>
 /*

1. ¿Qué hace el siguiente segmento de código?

This code discribes : a sctructure called flexArrayStruct with  2 variable an  integer num, and an array data.
the function : func, does a dynamic allocation  of memory initializing the arrays with 1

2. De haber algún problema ¿Podrı́as decir la lı́nea en la que se encuentra?

 struct flexArrayStruct *structP = (struct flexArrayStruct *) malloc(sizeof (struct flexArrayStruct) + sizeof(int) * (array_size - 1) ) ;

3. Define la regla que se incumple y propón una alternativa correcta siguiendo el SEI CERT C.
DCL30-C. Declare objects with appropriate storage durations

DCL38-C. Use the correct syntax when declaring a flexible array member 


*/

struct flexArrayStruct {
   size_t num ;
   //STR11-C Do not specify the bound of a character array initialized with a string literal.
   int data [] ;
};
 
void func(size_t array_size) {
      /* Space is allocated for the struct  */
   //
   struct flexArrayStruct *structP = (struct flexArrayStruct *) 
               malloc(sizeof (struct flexArrayStruct) + 
               sizeof(int) * (array_size) ) ;

   if (structP == NULL) {
      /*  Handle malloc failure */
      fprintf(stderr, "Error de asignación de memoria\n");
      return;
   }
   structP -> num = array_size;

   /*    
   * Access data[] as if it had been allocated    
   * as data[array_size].    
   */ 

   for (size_t i = 0 ; i < array_size ; ++ i ) {
      structP ->data[i] = 1 ;
   }
   free(structP);
        
}
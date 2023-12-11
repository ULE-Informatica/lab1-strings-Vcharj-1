
#include <stdio.h> 
#include <stddef.h> 
#include <stdlib.h>
#include <string.h>
 

//DCL30-C. Declare objects with appropriate storage durations
//98027==ERROR: LeakSanitizer: detected memory leaks
//98096==ERROR: AddressSanitizer: heap-buffer-overflow 
char const *funcion1(void) { 
  // Noncompliant Code Example (Return Values) 
   //char *array = ; 
   char *array  = (char *) malloc(20);  
   strcpy(array, "Mi Cadena"); 
    // Initialize array 
    return array;  
    free(array);
} 

void funcion2 (void) { 
   //Noncompliant Code Example (Differing Storage Durations) 
   char *p = (char *) malloc(20);
   const char *c_str = "Todo va bien"; 
   strcpy(p, c_str);
   printf("2 - %s \n", p);
   //p = c_str;
   free(p);
} 

void funcion3(void) { 
   char *p = (char *) malloc(20);
   strcpy(p, "----");
   printf("3 - %s \n", p);
   free(p);
} 

int main(void) { 
   char *p = (char *) malloc(20);
   strcpy(p, funcion1());
   //p = funcion1(); 
   printf("1 - %s\n",p);
   funcion2(); 
   funcion3(); 
   printf("4 - %s\n", p); 
   return 0; 
   free(p);

}
/**
 *  
 * The student needs to compile, test and comment the source code file.
 * 
 * Enumerate those Rules and Recommendation associated that are broken in the 
 * previous source code file.
 * Enumerate he compilation tools and parameters (gcc vs g++ ), -Wall ...
 * Enumerate the standard associated  -std=c99, -std=c11
 * 
 * There are several variants. You should choose at least two. You can also try clang.
 * At the end the source code  should compile without warnings to the variant 
 *     selected (you can remove/change instructions).
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>


 
const  char array1[] = "Foo" "bar";
const  char array2[] = { 'F', 'o', 'o', 'b', 'a', 'r', '\0' };
 
enum { BUFFER_MAX_SIZE = 1024 };
const char* s2 = "Hello World\n";
const char* s1 = R"foo(
                  Hello,
                  World
                  )foo";


void gets_example_func(void) {
  char buf[BUFFER_MAX_SIZE];
 
  if (fgets(buf, sizeof(buf), stdin) == NULL) {
        return;
  }
  buf[strlen(buf) - 1] = '\0';
}

char const *get_dirname(char const *pathname) {
  //char const *slash;
  //char const ch = "/";
  char const*slash = strrchr(pathname, '/');
  if (slash != NULL) {
      //*slash = '\0'; /* Undefined behavior */
      char *newSlash = (char *)slash; // Cast to a non-const pointer
      *newSlash = '\0'; // Null-terminate the string at the last slash position
    
      return pathname;
  }else{
      return pathname;
  }
}
 

void get_y_or_n(void) {  
	char response[8];

	printf("Continue? [y] y [n] para salir: \n");  
	gets(response);
	printf("-------------------------------------------------\n");

	if (response[0] == 'n') 
		exit(0);  

	return; 
}

 
int main(int argc, char const *argv[])
{
    char key[24];
    char response[8];
    char array3[16];
    char array4[16];
    char array5 []  = "01234567890123456";
    char ptr_char[]  = "new string literal";
    int size_array1 = strlen("аналитик");
    int size_array2 = 100;
    
    wchar_t analitic1[size_array1];
    wcscpy(analitic1, L"аналитик");
    wchar_t analitic2[size_array2];
    wcscpy(analitic2, L"аналитик");
    wchar_t analytic3[] =L"аналитик"; //Wide-Character Library Functions
    //---------------------------------------------------------------------------------------------------Print
    
    printf("Favor de escribir la direccion donde se encuentra el archivo: \n");  

    puts(get_dirname(__FILE__));

        
    strcpy(key, argv[1]);  
    strcat(key, " = ");  
    strcat(key, argv[2]);


    fgets(response,sizeof(response),stdin);
    
    get_y_or_n();

    printf("%s\n",array1);
    //printf("\n");
    printf("%s\n",array2);
    //printf("\n");
 
    puts(s1);
    //printf("\n");
    puts(s2); // 
    //printf("\n");
    
    strncpy(array3, array5, sizeof(array3));  
    strncpy(array4, array3, strlen(array3));
    
    array5 [0] = 'M';
    ptr_char [0] = 'N';
    
    array3[sizeof(array3)-1]='\0';
    
    
    return 0;
}

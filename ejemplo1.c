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
#define MAX_LEN 24


const  char array1[] = "Foo" "bar"; // ok
const  char array2[] = { 'F', 'o', 'o', 'b', 'a', 'r', '\0' }; //ok

enum { BUFFER_MAX_SIZE = 1024 };
//STR30-C. Do not attempt to modify string literals
const char* s2 = "Hello World\n";
const char* s1 = R"foo(
                  Hello,
                  World
                  )foo";


void gets_example_func(void)
{
    char buf[BUFFER_MAX_SIZE];
    char *p;
    //FIO40-C. Reset strings on fgets() or fgetws() failure
    //FIO37-C. Do not assume that fgets() or fgetws() returns a nonempty string when successful
    if (fgets(buf, sizeof(buf), stdin) == NULL) {
        p = strchr(buf, '\n');
        if (p) {
         *p = '\0';
         }
    } else {
    //pfgets(buf, sizeof(buf), stdin) ;
    printf("%s\n",buf);
    }
    return ;
}

char const *get_dirname(char const *pathname)
{
    // printf("Favor de escribir la direccion donde se encuentra el archivo: \n");
    //STR30-C. Do not attempt to modify string literals
    //char const *slash;
    //char const ch = "/";
    char const*slash = strrchr(pathname, '/');
    if (slash != NULL) {
        //*slash = '\0'; /* Undefined behavior */
        char *newSlash = (char *)slash; // Cast to a non-const pointer
        *newSlash = '\0'; // Null-terminate the string at the last slash position

        return pathname;
    } else {
        return pathname;
    }
}


void get_y_or_n(void)
{
    //char response[8];
    char response [] = {'n','y'};
    printf("Continue? [y] y [n] para salir: \n");
    //FIO40-C. Reset strings on fgets() or fgetws() failure
    //gets(response);
    fgets(response, sizeof(response), stdin);
    //response[strlen(response)]=‘\0’;
    printf("-------------------------------------------------\n");
    if (response[0] == 'n')
        exit(0);

    return;
}


int main(int argc, char const *argv[])
{
    char key[MAX_LEN]; // Use a defined maximum length to prevent overflow
    char response[8];
    char array3[16];
    char array4[16];
    char array5 []  = "01234567890123456";
    char ptr_char[]  = "new string literal";
    int size_array1 = strlen("аналитик");
    int size_array2 = 100;
    //STR31-C. Guarantee that storage for strings has sufficient space for character data and the null terminator
    wchar_t analitic1[size_array1];
    wcscpy(analitic1, L"аналитик");
    wchar_t analitic2[size_array2];
    wcscpy(analitic2, L"аналитик");
    //wchar_t analytic3[] =L"аналитик"; //Wide-Character Library Functions
    wchar_t analitic3[size_array1];
    wcscpy(analitic3, L"аналитик");
    //---------------------------------------------------------------------------------------------------Print

  
    printf("la direccion donde se encuentra el archivo es: \n");
    puts(get_dirname(__FILE__));
    // From C99 Standadrd we should use strncpy() strcpy(), although strncpy is also deprecated
   // strcpy(key, argv[1]);   // strcat(key, " = ");
   // strcat(key, argv[2]);
    
    snprintf(key, sizeof(key), "%s = %s", argv[1], argv[2]);
    
    //Prinft functions
    printf("%s\n",get_dirname("test.cpp"));
    printf("Entrar un caracter para continuar\n");
    gets_example_func();
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

    //array3[sizeof(array3)-1]='\0';


    return 0;
}

/**
==24534==ERROR: AddressSanitizer: heap-use-after-free on address 0x60b0000000f0 at pc 0x7fc8fca3a2c3 bp 0x7ffd000b7e20 sp 0x7ffd000b75c8
WRITE of size 19 at 0x60b0000000f0 thread T0
    #0 0x7fc8fca3a2c2 in __interceptor_memcpy ../../../../src/libsanitizer/sanitizer_common/sanitizer_common_interceptors.inc:827
    #1 0x55955f8be49b in optionThree /home/dimi/Documents/cPP/ejemplo2.c:23
    #2 0x55955f8be803 in main /home/dimi/Documents/cPP/ejemplo2.c:67
    #3 0x7fc8fc629d8f in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58
    #4 0x7fc8fc629e3f in __libc_start_main_impl ../csu/libc-start.c:392
    #5 0x55955f8be2e4 in _start (/home/dimi/Documents/cPP/ejemplo2+0x12e4)

==25560==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x603000000052 at pc 0x7f42afc3a2c3 bp 0x7ffec1af2ef0 sp 0x7ffec1af2698
WRITE of size 19 at 0x603000000052 thread T0
    #0 0x7f42afc3a2c2 in __interceptor_memcpy ../../../../src/libsanitizer/sanitizer_common/sanitizer_common_interceptors.inc:827
    #1 0x55edfba944ee in optionFour /home/dimi/Documents/cPP/ejemplo2.c:29
    #2 0x55edfba9480f in main /home/dimi/Documents/cPP/ejemplo2.c:70
    #3 0x7f42af829d8f in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58
    #4 0x7f42af829e3f in __libc_start_main_impl ../csu/libc-start.c:392
    #5 0x55edfba942e4 in _start (/home/dimi/Documents/cPP/ejemplo2+0x12e4)

0x603000000052 is located 0 bytes to the right of 18-byte region [0x603000000040,0x603000000052)

with ASAN we were able to detect two bugs ==24534==ERROR: AddressSanitizer: heap-use-after-free on line 23 and ==25560==ERROR: AddressSanitizer: heap-buffer-overflow line 29

 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

void optionOne(){
    char *s = (char *) malloc(100);
    strcpy(s, "Welcome Sanitizer!");
    printf("string is: %s\n", s);
    free(s);
}

void optionTwo(){
    char *s = (char *) malloc(100);
    strcpy(s, "Welcome Sanitizer!");
    printf("string is: %s\n", s);
}

void optionThree(){
    char *s = (char *) malloc(100);
    strcpy(s, "Welcome Sanitizer!");
    printf("string is: %s\n", s);
    free(s);
}

void optionFour(){
    char *s = (char *) malloc(100);
    strcpy(s,  "Welcome Sanitizer!");
    printf("string is: %s\n", s);
    free(s);
}

int main(int argc, const char *argv[]) {

    int expression;
    char* p;
    errno = 0; 
    
    if (2 != argc) {
        fprintf(stderr, "Usage: %s <option>\n", argv[0]);
        exit(1);
    }

    long arg = strtol(argv[1], &p, 10);

    if (*p != '\0' || errno != 0) {
        return 1; 
    }

    if (arg < INT_MIN || arg > INT_MAX) {
        return 1;
    }

    expression = arg;
 

    switch (expression)
    {
        case 1:
            optionOne();
            break;
        case 2:
            optionTwo();
            break;
        case 3:
            optionThree();
            break;
        case 4:
            optionFour();
            break;
        default:
            printf("\n");
            break;
    }

    return 0;
}

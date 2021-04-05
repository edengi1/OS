#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>


int main() {


    void *lib = dlopen("./libHello.so", RTLD_LAZY);

    if(lib == NULL) {
        printf("File not found!\n");
        return -1;
    }


    void (*fnc)() = (void *)dlsym(lib, "welcome");

    if (fnc == NULL) {
        printf("Function not found!\n");
        return -1;
    }

    fnc("Welcome Tal and Itay!");
    // welcome("Itay and Tal");
    return 0;
}
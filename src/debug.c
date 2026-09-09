#include <stdio.h>
#include "debug.h"

void debugging(char *args[], char *userin){
    for(int i = 0; args[i] != NULL; i++){
        printf("args[%d]: %s\n", i, args[i]);

    printf("value: %s \n", userin);
    printf("address: %p \n", &userin);
    //printf("Bytes used: %d\n", sizeof(userin));
    }

}

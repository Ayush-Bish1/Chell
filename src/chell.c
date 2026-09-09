#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "debug.h"

int main(){

    char userin[1024];
    char *args[64];
    char *token;
    int run = 0;
    int deb = 1;

    printf("Welcome to Chell(shell)\n");

    //main loop
    while(1==1){
        int i = 0;
        printf("Chell/archbtw > ");
        fgets(userin, sizeof(userin), stdin);

        userin[strcspn(userin, "\n")] = '\0';

        if(userin[0] == '\0'){
            continue;
        } else if(userin[0] == 'e' &&
                  userin[1] == 'x' &&
                  userin[2] == 'i' &&
                  userin[3] == 't' &&
                  (userin[4] == '\0' || userin[4] == '\n')){
            printf("exiting..\n");
            break;
        }
    
 
        token = strtok(userin, " \n");
            //Putting data from userin to args
        while(token != NULL && i < 63){
            args[i++] = token;
            token = strtok(NULL, " \n");
        }

        args[i] = NULL;

        pid_t pid = fork();
        //child process
        if(pid == 0){
            execvp(args[0], args);
            perror("failed");
            exit(1);
        } else{
            wait(NULL);
        } 
           
        //debugging(args, userin);

        }

    return 0;
}

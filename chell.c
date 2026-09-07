#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){

    char userin[1024];
    char *args[64];
    char *token;

    printf("Welcome to Chell(shell)\n");

    //main loop
    while(1==1){
        int index = 0;
        printf("Chell/archbtw > ");
        fgets(userin, sizeof(userin), stdin);

        userin[strcspn(userin, "\n")] = '\0';

        if(userin[0] == '\0'){
            continue;
        } else if(strcspn(userin, "exit") == 0){
            printf("exiting..\n");
            break;
        }
 
        token = strtok(userin, " \n");
            //Putting data from userin to args
        while(token != NULL && index < 63){
            args[index++] = token;
            token = strtok(NULL, " \n");
        }

        //Use for debugging
        //for(int i = 0; args[i] != NULL; i++){
        //    printf("args[%d]: %s \n", i, args[i]);
        //}
        args[index] = NULL;

        pid_t pid = fork();
        //child process
        if(pid == 0){
            execvp(args[0], args);
            perror("failed");
        } else{
            wait(NULL);
        }    

        //Use this for debugging 
        //printf("value: %s \n", userin);
        //printf("address: %p \n", &userin);
        //printf("Bytes used: %d\n", sizeof(userin));
    }

    return 0;
}

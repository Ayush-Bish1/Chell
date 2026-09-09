#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include "debug.h"

//To get the art for the banner of Chell
void art(char *file){
    FILE *path = fopen(file, "r"); 
    
    if(!path){
        perror("Coudlnt Open The file \n");
        return;
    }

    char cha;
    while ((cha = fgetc(path)) != EOF){
        putchar(cha);
    }

    fclose(path);

}


int main(){

    char userin[1024];
    char *args[64];
    char *token;
    int run = 0;
    int deb = 1;
    int random;

    //random ascii
    srand(time(NULL));
    random = (rand() % 3) + 1;
    
    if(random == 1){
        art("assets/asci1.txt");
    } else if(random == 2){
        art("assets/asci2.txt");
    } else{
        art("assets/asci3.txt");
    }

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

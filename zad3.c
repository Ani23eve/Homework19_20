#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>

#define COUNT 10

void* fnct(void* arg)
{ 
    
    printf("%s \n",(char*) arg);
     
}

int main(int argc, char const *argv[])
{   
    if(argc == 0){
        perror("Missing arguments!");
        return EXIT_FAILURE;
    }
    char arr[COUNT];
    strcpy(arr, *(argv + 3));
    int P = atoi(*(argv + 1));
    int T = atoi(*(argv + 2));

    for (int i = 0; i < P; i++){
        pid_t pid = fork();
        if (0 == pid){

            pthread_t t[T];
            for (int i = 0; i < T; i++) {
        
                pthread_create(&t[i], NULL, &fnct, arr);
                pthread_join(&t[i], NULL);
                pthread_attr_destroy(&t[i]);
            }
         
             exit(EXIT_SUCCESS);
        }
          
    }
    for (int i = 0; i < P; i++){
        wait(NULL);
    }
    
    return EXIT_SUCCESS;
} 
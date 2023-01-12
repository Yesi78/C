#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
/* You'll need to have a bunch more #include's this time! */

/* Feel free to use this to report on proper usage (and exit) */


void usage() {
    fprintf(stderr, "Usage: bin/mytime [--special] program [args...]\n");
    exit(1);
}

void fork_exec_wait(char *pathname, char *const argv[]) {
    pid_t fork_ret;

    fork_ret = fork();
    if (fork_ret < 0) {
        perror("forking");
     } else if (fork_ret == 0) {
        /* I'm the child */
        if (execvp(pathname, argv) < 0) {
            perror("executing progtorun");
        }
        
    } else {
        /* I'm the parent */
        int wstatus;
        waitpid(fork_ret, &wstatus, 0);
        
    }
}

int main (int argc, char *argv[]) {
    int is_special=0;
    int offset = 1;
    if(argc > 1) {
        //check for --special
        if (strcmp(argv[1], "--special") == 0) {
            is_special=1;
            offset = 2;
            setenv("SPECIAL", "Y", 1);
        }
    }

    //check for number of args
    if((argc < 2) || (is_special && argc < 3)) {
        usage(argv[0]);
        exit(1);
        }

    int arg_size;

    //adjust arg_size according to is_special
    if(is_special) {
        arg_size= argc - 1;
    }
    else {
        arg_size = argc;
    }

    char** args = malloc(arg_size * sizeof(char*)+ 1);

    for(int i=0;i < arg_size - 1; i++){
        args[i]=argv[i + offset];
    }
    args[arg_size-1]= NULL;

    struct timespec start_time;
    struct timespec end_time;

    clock_gettime(CLOCK_MONOTONIC_RAW, &start_time);
    fork_exec_wait(args[0],args);
    clock_gettime(CLOCK_MONOTONIC_RAW, &end_time);
    double time_taken = (((double)end_time.tv_nsec/1000000000) - ((double)(start_time.tv_nsec/1000000000)));
    printf("Elapsed time: %.02f sec\n", time_taken);
    free(args);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

/* This program serves as a basic benchmarking program, but beyond that
 * it doesn't do anything useful. It will create an array of any size,
 * provided as a command line argument (with a default value defined below),
 * create an array with that many random integers in it, and the sort the
 * array. Sorting will either be using selection sort (the default), or
 * using the standard C library qsort function if the environment variable
 * named "SPECIAL" is set.
 */

#define DEFAULT_SIZE 50000

/* The seletion sort algorithm. */
void selsort(int size, int *data) {
    int i, j;
    int minpos;
    int minval;

    for (i=0; i<size-1; i++) {
        minval = data[i];
        minpos = i;
        for (j=i+1; j<size; j++)
            if (data[j] < minval) {
                minpos = j;
                minval = data[j];
            }
        data[minpos] = data[i];
        data[i] = minval;
    }
}

/* The comparator needed by qsort() */
static int icompare(const void *a, const void *b) {
    return *(const int *)a - *(const int *)b;
}

/* main creates the array of the appropriate size, and calls the correct
 * sorting function. */
int main(int argc, char *argv[]) {
    int asize = DEFAULT_SIZE;

    /* If either the size is zero/invalid, or malloc fails, just exit. */

    if (argc > 1) {
        asize = atoi(argv[1]);
        if (asize == 0) exit(1);
    }

    int *data;
    if ((data=malloc(asize*sizeof(int))) == NULL) {
        perror("Allocating array");
        exit(1);
    }

    /* Note that we don't seed the random number generator, so this gives
     * the same sequence of "random" numbers every time the program is
     * run.  */

    for (int i=0; i<asize; i++) {
        data[i] = random();
    }

    /* The "SPECIAL" environment variable indicates that qsort should be used */

    if (getenv("SPECIAL") != NULL) {
        /* Use qsort */
        qsort(data, asize, sizeof(int), icompare);
    } else {
        selsort(asize, data);
    }

#ifdef DEBUG
    /* Used to see if the sorting worked properly during development. */
    for (int i=0; i<asize; i++) {
        printf("%d\n", data[i]);
    }
#endif

    return 0;
}

// CSC 362 - Weekly Assignment 3 - C implementation of an array list

// This version only supports a fixed capacity (defined by DEF_CAPACITY)
// and int's for values.

// This arraylist works as follows: the "data" field of an initialized
// alist should be an array of DEF_CAPACITY ints, with this capacity
// stored in the "capacity" field. The array must be dynamically
// allocated with malloc to support future assignments (do not change
// the definition to a statically-allocated array!). The "in_use" field
// tracks how many ints are actually stored in the arraylist.

// Error handling: No invalid operation should be performed, so in particular
// all indexes must be checked for validity and the capacity must not be
// exceeded. In this version, there is no error recovery -- all errors are
// fatal, and your implementation must print an error message to stderr
// and then exit the program with a non-zero exit code.

// Testing: There is a very thorough collection of tests given below. You
// are welcome to add your own additional tests, but you may not change any
// of the provided ones. See the README for information on how to run the
// tests and what the correct result should be for each one.

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define DEF_CAPACITY 10

typedef struct {
    int *data;     // Array of int values holding array list contents
    int capacity;  // How big is the data array
    int in_use;    // How many items are in use (items 0..in_use-1)
} alist;

/***************************************************************************
 * alist_init initializes an array list to empty and with the default
 * capacity.
 */
void alist_init(alist *a) {
    a->capacity= DEF_CAPACITY;
    a->in_use= 0;
    a->data= (int *)malloc(sizeof(int) *a->capacity);

}

/***************************************************************************
 * alist_clear resets the size of the array list to 0 (empties the alist).
 */
void alist_clear(alist *a) {
    free(a->data);
    a->data= NULL;
    a->capacity=0;
    a->in_use= 0;
}

/***************************************************************************
 * alist_is_empty returns true if and only if the array list is empty.
 */

int alist_is_empty(alist *a) {
    return a->in_use == 0;
}

/***************************************************************************
 * alist_size returns the size of the array list
 */
int alist_size(alist *a) {
    return a->in_use;
}

/***************************************************************************
 * alist_get returns the value at array index "index".
 */
int alist_get(alist *a, int index) {
    if(index < 0 || index >= a->in_use) {
        perror("Error: Bad Get Index\n");
        exit(1);
    }
    return a->data[index];
}

/***************************************************************************
 * alist_add appends a new value to the end of the array list.
 */
void alist_add(alist *a, int val) {
    if(a->in_use >= a->capacity){
        perror("Capacity exceeded!\n");
        exit(1);
    }
    a->data[a->in_use++] = val;
}

/***************************************************************************
 * alist_set sets the index "index" item to value "val". The index/position
 * must exist in the array list, having been created by an alist_add() call.
 */
void alist_set(alist *a, int index, int val) {
    if(index < 0 || index >= a->in_use){
        perror("Bad index passed\n");
        exit(1);
    }
    a->data[index]= val;
}

/***************************************************************************
 * alist_print - prints (to stdout) an array list of integers, all one
 * one line, with a space separating values. A newline is output at
 * the end.
 */
void alist_print(alist *a) {
    for (int i=0; i < alist_size(a); i++) {
        if (i > 0) putchar(' ');
        printf("%d", alist_get(a, i));
    }
    putchar('\n');
}

// =====================================================================
// Testing routines below here -- nothing for students to do or change.

/***********************************************************************
 * test1 - Should print "3 1 4 1 5 9"
 */
void test1(void) {
    const char *test_id = "CSC362-TEST1";
    alist my_alist;
    alist_init(&my_alist);
    alist_add(&my_alist, 3);
    alist_add(&my_alist, 1);
    alist_add(&my_alist, 4);
    alist_add(&my_alist, 1);
    alist_add(&my_alist, 5);
    alist_add(&my_alist, 9);

    printf("%s: ", test_id);
    alist_print(&my_alist);
}

/***********************************************************************
 * test2 - Should print "3 1 4 1 5 9"
 */
void test2(void) {
    const char *test_id = "CSC362-TEST2";
    alist my_alist;
    alist_init(&my_alist);
    for (int i=0; i<6; i++) {
        alist_add(&my_alist, 99);
    }
    alist_set(&my_alist, 3, 1);
    alist_set(&my_alist, 0, 3);
    alist_set(&my_alist, 5, 9);
    alist_set(&my_alist, 2, 4);
    alist_set(&my_alist, 4, 5);
    alist_set(&my_alist, 1, 1);

    printf("%s: ", test_id);
    alist_print(&my_alist);
}

/***********************************************************************
 * test3 - Testing the "good case" of the get function - should get TESTVAL
 */
void test3(void) {
    const char *test_id = "CSC362-TEST3";
    const int TESTVAL = 930;
    alist my_alist;
    alist_init(&my_alist);
    alist_add(&my_alist, 889);
    alist_add(&my_alist, 516);
    alist_add(&my_alist, TESTVAL);
    alist_add(&my_alist, 23);
    alist_add(&my_alist, 26);
    alist_add(&my_alist, 105);
    alist_add(&my_alist, 585);
    alist_add(&my_alist, 794);

    int got_val = alist_get(&my_alist, 2);
    if (got_val == TESTVAL) {
        printf("%s: Passed \"good get\" test\n", test_id);
    } else {
        printf("%s: Failed \"good get\" test (got %d -- should be %d)\n",
               test_id, got_val, TESTVAL);
    }
}

/***********************************************************************
 * test4 - Bad index to get - should print message and have nonzero exit code
 */
void test4(void) {
    const char *test_id = "CSC362-TEST4";
    alist my_alist;
    alist_init(&my_alist);
    alist_add(&my_alist, 99);
    alist_add(&my_alist, 99);

    int rval = alist_get(&my_alist, 2);

    printf("%s: Failed \"bad get index\" test (didn't exit) - returned %d.\n",
           test_id, rval);
}

/***********************************************************************
 * test5 - Bad index to get - should print message and have nonzero exit code
 */
void test5(void) {
    const char *test_id = "CSC362-TEST5";
    alist my_alist;
    alist_init(&my_alist);
    alist_add(&my_alist, 99);

    int rval = alist_get(&my_alist, -1);

    printf("%s: Failed \"bad get index\" test (didn't exit) - returned %d.\n",
           test_id, rval);
}

/***********************************************************************
 * test6 - Bad index to set - should print message and havenonzero exit code
 */
void test6(void) {
    const char *test_id = "CSC362-TEST6";
    alist my_alist;
    alist_init(&my_alist);
    alist_add(&my_alist, 99);
    alist_add(&my_alist, 99);

    alist_set(&my_alist, 2, 0);

    printf("%s: Failed \"bad set index\" test (didn't exit).\n", test_id);
}

/***********************************************************************
 * test7 - Bad index to set - should print message and havenonzero exit code
 */
void test7(void) {
    const char *test_id = "CSC362-TEST7";
    alist my_alist;
    alist_init(&my_alist);
    alist_add(&my_alist, 99);
    alist_add(&my_alist, 99);

    alist_set(&my_alist, -1, 0);

    printf("%s: Failed \"bad set index\" test (didn't exit).\n", test_id);
}

/***********************************************************************
 * test8 - Testing alist_size()
 */
void test8(void) {
    const char *test_id = "CSC362-TEST8";
    alist my_alist;
    alist_init(&my_alist);
    alist_add(&my_alist, 99);
    alist_add(&my_alist, 99);

    int got_size = alist_size(&my_alist);

    if (got_size == 2) {
        printf("%s: Passed size test.\n", test_id);
    } else {
        printf("%s: Failed size test (got size %d, should be 2)\n",
               test_id, got_size);
    }
}

/***********************************************************************
 * test9 - Testing alist_is_empty() -- should be false
 */
void test9(void) {
    const char *test_id = "CSC362-TEST9";
    alist my_alist;
    alist_init(&my_alist);
    alist_add(&my_alist, 99);
    alist_add(&my_alist, 99);

    if (!alist_is_empty(&my_alist)) {
        printf("%s: Passed non-empty is_empty test.\n", test_id);
    } else {
        printf("%s: Failed non-empty is_empty test (should return false).\n",
               test_id);
    }
}

/***********************************************************************
 * test10 - Testing alist_is_empty() -- should be true
 */
void test10(void) {
    const char *test_id = "CSC362-TEST10";
    alist my_alist;
    alist_init(&my_alist);

    if (alist_is_empty(&my_alist)) {
        printf("%s: Passed empty is_empty test.\n", test_id);
    } else {
        printf("%s: Failed non-empty is_empty test (should return true).\n",
               test_id);
    }
}

/***********************************************************************
 * test11 - Testing alist_clear() -- should empty out alist
 */
void test11(void) {
    const char *test_id = "CSC362-TEST11";
    alist my_alist;
    alist_init(&my_alist);
    alist_add(&my_alist, 99);
    alist_add(&my_alist, 99);
    alist_clear(&my_alist);

    if (alist_is_empty(&my_alist)) {
        printf("%s: Passed clear+is_empty test.\n", test_id);
    } else {
        printf("%s: Failed clear+is_empty test (should return true).\n",
               test_id);
    }
}

/***********************************************************************
 * test12 - Exceeding capacity - should print message and have nonzero exit code
 */
void test12(void) {
    const char *test_id = "CSC362-TEST12";
    alist my_alist;
    alist_init(&my_alist);
    for (int i=0; i<DEF_CAPACITY+1; i++)
        alist_add(&my_alist, 99);

    printf("%s: Didn't exit - test failed.\n", test_id);
}

/***********************************************************************
 * test13 - Testing capacity field - must look inside struct for this test...
 */
void test13(void) {
    const char *test_id = "CSC362-TEST13";
    alist my_alist;
    alist_init(&my_alist);
    alist_add(&my_alist, 99);
    alist_add(&my_alist, 99);

    if (my_alist.capacity == DEF_CAPACITY) {
        printf("%s: Passed capacity test.\n", test_id);
    } else {
        printf("%s: Failed capacity test (capacity is %d, should be %d).\n",
               test_id, my_alist.capacity, DEF_CAPACITY);
    }
}

/***********************************************************************
 * Test driver - gets test number from command line and runs specied test
 */
int main(int argc, char *argv[]) {
    int test_num = 0;

    if (argc != 2) {
        fprintf(stderr, "Must invoke %s with a test number (1..13)\n", argv[0]);
        exit(1);
    }

    test_num = atoi(argv[1]);

    switch (test_num) {
        case 1: test1(); break;
        case 2: test2(); break;
        case 3: test3(); break;
        case 4: test4(); break;
        case 5: test5(); break;
        case 6: test6(); break;
        case 7: test7(); break;
        case 8: test8(); break;
        case 9: test9(); break;
        case 10: test10(); break;
        case 11: test11(); break;
        case 12: test12(); break;
        case 13: test13(); break;
        default:
            printf("Invalid test number %d\n", test_num);
            break;
    }

    return 0;
}



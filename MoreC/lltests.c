// This file provides an extensive test suite for the linked list
// implementation (llist). Each test is documented with its function,
// and if the output is something other than a clear "Passed" or "Failed"
// message then the expected output is documented.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "llist.h"

/***********************************************************************
 * test1 - Should print "CSC362-TEST1: one, two, three, four, five, six"
 */
void test1(void) {
    const char *test_id = "CSC362-TEST1";
    llist my_llist;
    llist_init(&my_llist);
    llist_add(&my_llist, "one");
    llist_add(&my_llist, "two");
    llist_add(&my_llist, "three");
    llist_add(&my_llist, "four");
    llist_add(&my_llist, "five");
    llist_add(&my_llist, "six");

    printf("%s: ", test_id);
    llist_print(&my_llist);
    llist_destroy(&my_llist);
}

/***********************************************************************
 * test2 - Should print "CSC362-TEST2: one, two, three, four, five, six"
 */
void test2(void) {
    const char *test_id = "CSC362-TEST2";
    llist my_llist;
    llist_init(&my_llist);
    for (int i=0; i<6; i++) {
        llist_add(&my_llist, "REPLACEME");
    }
    llist_set(&my_llist, 3, "four");
    llist_set(&my_llist, 0, "one");
    llist_set(&my_llist, 5, "six");
    llist_set(&my_llist, 2, "three");
    llist_set(&my_llist, 4, "five");
    llist_set(&my_llist, 1, "two");

    printf("%s: ", test_id);
    llist_print(&my_llist);
    llist_destroy(&my_llist);
}

/***********************************************************************
 * test3 - Testing the "good case" of the get function
 */
void test3(void) {
    const char *test_id = "CSC362-TEST3";
    char *testval = "test string";
    llist my_llist;
    llist_init(&my_llist);
    llist_add(&my_llist, "alpha");
    llist_add(&my_llist, "beta");
    llist_add(&my_llist, testval);
    llist_add(&my_llist, "gamma");
    llist_add(&my_llist, "scooby");
    llist_add(&my_llist, "doo");
    llist_add(&my_llist, "scrappy");
    llist_add(&my_llist, "too");

    char *got_val = llist_get(&my_llist, 2);
    if (strcmp(got_val, testval) == 0) {
        printf("%s: Passed \"good get\" test\n", test_id);
    } else {
        printf("%s: Failed \"good get\" test (got %s -- should be %s)\n",
               test_id, got_val, testval);
    }
    llist_destroy(&my_llist);
}

/***********************************************************************
 * test4 - Bad index to get - too large
 */
void test4(void) {
    const char *test_id = "CSC362-TEST4";
    llist my_llist;
    llist_init(&my_llist);
    llist_add(&my_llist, "green");
    llist_add(&my_llist, "back");

    char *rval = llist_get(&my_llist, 2);

    if (rval == NULL) {
        printf("%s: Passed \"bad get index\" test\n", test_id);
    } else {
        printf("%s: Failed \"bad get index\" test (got %s -- should be NULL)\n",
               test_id, rval);
    }
    llist_destroy(&my_llist);
}

/***********************************************************************
 * test5 - Bad index to get - too small
 */
void test5(void) {
    const char *test_id = "CSC362-TEST5";
    llist my_llist;
    llist_init(&my_llist);
    llist_add(&my_llist, "green");
    llist_add(&my_llist, "back");

    char *rval = llist_get(&my_llist, -1);

    if (rval == NULL) {
        printf("%s: Passed \"bad get index\" test\n", test_id);
    } else {
        printf("%s: Failed \"bad get index\" test (got %s -- should be NULL)\n",
               test_id, rval);
    }
    llist_destroy(&my_llist);
}

/***********************************************************************
 * test6 - Bad index to set - too large - should print "green, back"
 */
void test6(void) {
    const char *test_id = "CSC362-TEST6";
    llist my_llist;
    llist_init(&my_llist);
    llist_add(&my_llist, "green");
    llist_add(&my_llist, "back");

    llist_set(&my_llist, 2, "boogie");

    printf("%s: ", test_id);
    llist_print(&my_llist);
    llist_destroy(&my_llist);
}

/***********************************************************************
 * test7 - Bad index to set - too small - should print "green, back"
 */
void test7(void) {
    const char *test_id = "CSC362-TEST7";
    llist my_llist;
    llist_init(&my_llist);
    llist_add(&my_llist, "green");
    llist_add(&my_llist, "back");

    llist_set(&my_llist, -1, "boogie");

    printf("%s: ", test_id);
    llist_print(&my_llist);
    llist_destroy(&my_llist);
}

/***********************************************************************
 * test8 - Testing llist_size()
 */
void test8(void) {
    const char *test_id = "CSC362-TEST8";
    llist my_llist;
    llist_init(&my_llist);
    llist_add(&my_llist, "green");
    llist_add(&my_llist, "back");

    int got_size = llist_size(&my_llist);

    if (got_size == 2) {
        printf("%s: Passed size test.\n", test_id);
    } else {
        printf("%s: Failed size test (got size %d, should be 2)\n",
               test_id, got_size);
    }
    llist_destroy(&my_llist);
}

/***********************************************************************
 * test9 - Testing llist_is_empty() with non-empty list
 */
void test9(void) {
    const char *test_id = "CSC362-TEST9";
    llist my_llist;
    llist_init(&my_llist);
    llist_add(&my_llist, "green");
    llist_add(&my_llist, "back");

    if (!llist_is_empty(&my_llist)) {
        printf("%s: Passed non-empty is_empty test.\n", test_id);
    } else {
        printf("%s: Failed non-empty is_empty test (should return false).\n",
               test_id);
    }
    llist_destroy(&my_llist);
}

/***********************************************************************
 * test10 - Testing llist_is_empty() with empty list
 */
void test10(void) {
    const char *test_id = "CSC362-TEST10";
    llist my_llist;
    llist_init(&my_llist);

    if (llist_is_empty(&my_llist)) {
        printf("%s: Passed empty is_empty test.\n", test_id);
    } else {
        printf("%s: Failed non-empty is_empty test (should return true).\n",
               test_id);
    }
    llist_destroy(&my_llist);
}

/***********************************************************************
 * test11 - Testing llist_clear() -- should result in an empty list
 */
void test11(void) {
    const char *test_id = "CSC362-TEST11";
    llist my_llist;
    llist_init(&my_llist);
    llist_add(&my_llist, "green");
    llist_add(&my_llist, "back");
    llist_clear(&my_llist);

    if (llist_is_empty(&my_llist)) {
        printf("%s: Passed clear+is_empty test.\n", test_id);
    } else {
        printf("%s: Failed clear+is_empty test (should return true).\n",
               test_id);
    }
    llist_destroy(&my_llist);
}

/***********************************************************************
 * test12 - Bad index to set - too large - should print "green, back"
 */
void test12(void) {
    const char *test_id = "CSC362-TEST12";
    llist my_llist;
    llist_init(&my_llist);
    llist_add(&my_llist, "green");
    llist_add(&my_llist, "back");

    llist_remove(&my_llist, 2);

    printf("%s: ", test_id);
    llist_print(&my_llist);
    llist_destroy(&my_llist);
}

/***********************************************************************
 * test13 - Bad index to remove - too small - should print "green, back"
 */
void test13(void) {
    const char *test_id = "CSC362-TEST13";
    llist my_llist;
    llist_init(&my_llist);
    llist_add(&my_llist, "green");
    llist_add(&my_llist, "back");

    llist_remove(&my_llist, -1);

    printf("%s: ", test_id);
    llist_print(&my_llist);
    llist_destroy(&my_llist);
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

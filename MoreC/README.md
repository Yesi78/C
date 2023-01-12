This is the README file for the fourth weekly assignment. Remember that
collaboration is allowed (but not required) on weekly assignments. If
you do collaborate with others, give their names here:

(Replace this line with names)

Information and instructions on what to do are below.

## Learning Objectives

In this assignment you will locate and correct mistakes in a linked
list implementation.  In doing so, you'll gain experience with:

* Examining code for common errors
* Using the `gdb` debugger and `valgrind` tool to test and locate errors

## Instructions

Included with this assignment distriution are two main programs, one
in `lltests.c` that has unit tests that are almost identical to the
unit tests in last weeks' assignment, and another in `qsim.c` that
uses the linked list as a queue, simulating a waitlist, such as at a
meat counter or the DMV (everyone loves the DMV!). See the comments in
qsim.c for information about how this program operates.  The provided
`Makefile` will build both `lltests` and `qsim` executables.

To help with your testing, there are files `test.in` and `test.out` in
the repo. If you run the `qsim` program with test.in as input, using
```
   ./qsim <test.in
```
it should produce the output shown in `test.out`.

Unfortunately, there are several bugs in the `llist.c` code. In fact,
it won't even run on the `test.in` without a segmentation fault. The
bugs are all of the types that we discussed this week in class, on the
slide "Some Common C Errors" and in our discussion of Valgrind and
gdb.

You should use those two tools to track down and repair all of the
bugs. Note that you are only responsible for actual bugs - code that
causes illegal things to happen. Disagreeing with the style or
approach is not a bug, so don't change anything for that reason. The
final submitted version of your code should allow `qsim` to run
correctly and have a clean report from Valgrind.

**All bugs are in the `llist.c` file, and you should not change
anything in any other file!**

Write a brief description of each bug you found, and how you fixed it,
in the section below.

*Hint:* There are six distinct bugs in this code.

## Changes made

Describe your changes here

In llist_add line 96, I changed malloc(sizeof(node *)) to malloc(sizeof(node)) because the node isn't a pointer.

In llist_add line 97, I changed the malloc for allocname by doing malloc(strlen(newname)+1) to allow memory alloction for \0 at the end of the string.

In llist_get line 82, I changed part of the if statement condition from index> list->to index>= list->size because the size of the list itself is one spot greater than the index.

In llist_remove line 151, I again changed part of the if statement condition from index> list->to index>= list->size for the same reason mentioned above.

In llist_remove in line 171, I added free(curr->name) to free the data, name, what curr pointed to before we use free(curr).

In llist_clear lines 57 and 58, I added free(curr->name) and free(curr) to stop the memory leaks at those spots.


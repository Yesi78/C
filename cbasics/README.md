This is the README file for the third weekly assignment. Remember that
collaboration is allowed (but not required) on weekly assignments. If
you do collaborate with others, give their names here:

(Replace this line with names)

Instructions on what to do are below.

## Learning Objectives

In this assignment you will fill out a C language implementation of a
data structure patterned after the Java ArrayList. In doing so, you'll
gain experience with:

* Compiling and running C programs from the command line
* Basic C programming features, including malloc and working with structs
* Checking and handling errors and invalid parameters
* Using unit tests (provided) to test your code

## Note on Created Files

When you compile your C source code, it will create an executable file
named either `a.out` (the default) or some name of your choosing (if
you use the `-o` compiler option). These created files should *not* be
committed in your repo! You should use Git to track files that you
create, not files created by tools such as the compiler -- those files
can be generated again by the compiler from the files that are in the
repository. In future assignments, we'll use a specially-designed
"`Makefile`" that will structure this a little better, but until we
learn about make files just make sure you do not add those to the
files tracked by `git`.

## Instructions

The `alist.c` file contains a partial implementation of an array list
data structure, and many test routines. Functions that need to be
implemented (or completed) are marked with comments that start with
`/***` -- those comments should be removed and replaced with your
code. The documentation before each function defines what the function
should do, and to get you thinking about the implementation a partial
implementation of `alist_add` is provided (it works correctly, but
doesn't check to make sure there's any space left in the allocated
array to add a new item). Think clearly and don't over-complicate
this! Every function other than the `alist_init` function can be
solved with a *single* line of code for the "good case", plus code for
error checking.

The testing functions (called "unit tests" in general) are in
functions named `test1`, `test2`, etc. *Do not edit or change any of
these tests in any way!* You should look at the `main` function to see
how these tests are run.  Basically, if your code is compiled to the
executable program named `a.out`, then you would run test 4 from the
command line by typing `./a.out 4`. There are **13 tests** provided,
and your code for the `alist` functions should be robust enough where
it passes all 13 tests.

Some tests check error conditions -- bad parameters are passed to
functions like `alist_get` and `alist_set`. In this case your program
should print an error message to `stderr` and exit the program
immediately with a non-zero exit code. When this test is run, you
should see your error message, and you can check the exit code from
the command line by typing the command "`echo $?`". Note that you
should *not* see any output from the tester that begins with
"CSC362-TEST..." in this case -- if you see that message, it means you
didn't exit the program when you were supposed to!

Here is a basic list of all the tests:

1. Tests the basic `alist_add` functionality. When this test is
   passed, you should see the following output (and this should be all
   that is printed!):
   ```
   CSC362-TEST1: 3 1 4 1 5 9
   ```

2. Tests the basic `alist_set` functionality. When this test is
   passed, you should see the following output:
   ```
   CSC362-TEST2: 3 1 4 1 5 9
   ```

3. Tests the basic `alist_get` functionality. When this test is
   passed, you should see the following output:
   ```
   CSC362-TEST3: Passed "good get" test
   ```

4. Tests if `alist_get` detects when a bad index is passed to it. This
   should print some error message that you choose to `stderr`, and
   the exit with a non-zero exit code.


5. Tests if `alist_get` detects when a bad index is passed to it. This
   should print some error message that you choose to `stderr`, and
   the exit with a non-zero exit code.

6. Tests if `alist_set` detects when a bad index is passed to it. This
   should print some error message that you choose to `stderr`, and
   the exit with a non-zero exit code.

7. Tests if `alist_set` detects when a bad index is passed to it. This
   should print some error message that you choose to `stderr`, and
   the exit with a non-zero exit code.

8. Tests the basic `alist_set` functionality. When this test is
   passed, you should see the following output:
   ```
   CSC362-TEST8: Passed size test.
   ```

9. Tests the basic `alist_set` functionality. When this test is
   passed, you should see the following output:
   ```
   CSC362-TEST9: Passed non-empty is_empty test.
   ```

10. Tests the basic `alist_set` functionality. When this test is
    passed, you should see the following output:
    ```
    CSC362-TEST10: Passed empty is_empty test.
    ```

11. Tests the basic `alist_set` functionality. When this test is
    passed, you should see the following output:
    ```
    CSC362-TEST11: Passed clear+is_empty test.
    ```

12. Tests if `alist_add` detects when capacity is exceeded. This
    should print some error message that you choose to `stderr`, and
    the exit with a non-zero exit code.

13. Tests the basic `alist_set` functionality. When this test is
    passed, you should see the following output:
    ```
    CSC362-TEST13: Passed capacity test.
    ```

## Wrap-up

If you add names above to this README (names of collaborators), make
sure you save the final version of this file. Then commit the repo
(with the updated `alist.c` file), and push up to GitHub.

Remember that your final commit should use "Finished with Week03" as
the commit message, and always check in the GitHub web interface to
see that your commit and push were successful!


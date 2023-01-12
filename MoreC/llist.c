// CSC 362 - Weekly Assignment 4 - C implementation of a linked list

// As in your previous weekly assignment, the interface to this data
// structure mimics (part of) the standard Java List interface. There
// are some key differences between this implementation and last week's
// array list implementation:
//
// 1. This implementation is a list of strings, rather than a list of ints.
//    When a string is added to the queue, a copy is made using malloc'ed
//    memory.
//
// 2. This implementation also adds a "llist_remove" function, which
//    was not present in last week's array list implementation.
//
// 3. Error handling: Rather than bailing when an invalid index is
//    sent to a function, the function simply ignores the request.
//    The only fatal error is if you run out of memory and a malloc()
//    fails.

// A thorough test suite is provided in lltests.c, and a queue simulator
// using this data structure is provided in qsim.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "llist.h"

// The node type is defined here, since it is private to this implementation

typedef struct node {
    char *name;
    struct node *next;
} node;

/***************************************************************************
 * llist_init initializes the linked list to empty.
 */
void llist_init(llist *list) {
    list->first = NULL;
    list->last = NULL;
    list->size = 0;
}

/***************************************************************************
 * llist_clear resets the linked list to empty.
 */
void llist_clear(llist *list) {
    node *curr = list->first;
    while (curr != list->last) {
        node *savenext = curr->next;
        free(curr->name);
        free(curr);
        curr = savenext;
    }

    free(curr->name);
    free(curr);
    list->first = NULL;
    list->last = NULL;
    list->size = 0;
}

/***************************************************************************
 * llist_is_empty returns true if and only if the list is empty.
 */
int llist_is_empty(llist *list) {
    return (list->size == 0);
}

/***************************************************************************
 * llist_size returns the size of the list
 */
int llist_size(llist *list) {
    return list->size;
}

/***************************************************************************
 * llist_get returns the value at index "index", or NULL if this is
 * an invalid index.
 */
char *llist_get(llist *list, int index) {
    if ((index < 0) || (index >= list->size)) {
        return NULL;
    }

    node *curr = list->first;
    for (int i=0; i<index; i++)
        curr = curr->next;
    
    return curr->name;
}

/***************************************************************************
 * llist_add appends a new value to the end of the linked list.
 */
void llist_add(llist *list, char *newname) {
    node *newnode = malloc(sizeof(node));
    char *allocname = malloc(strlen(newname)+1);

    if ((newnode == NULL) || (allocname == NULL)) {
        perror("llist_add");
        exit(1);
    }

    strcpy(allocname, newname);
    newnode->name = allocname;
    newnode->next = NULL;

    if (list->last == NULL)
        list->first = newnode;
    else
        list->last->next = newnode;

    list->last = newnode;
    list->size++;
}

/***************************************************************************
 * llist_set sets the index "index" item to value "val". If the
 * index/position doesn't exist in the list, then nothing happens (the
 * request is ignored).
 */
void llist_set(llist *list, int index, char *newname) {
    if ((index < 0) || (index >= list->size)) {
        return;
    }

    node *curr = list->first;
    for (int i=0; i<index; i++)
        curr = curr->next;

    char *allocname = malloc(strlen(newname)+1);
    if (allocname == NULL) {
        perror("llist_set");
        exit(1);
    }

    strcpy(allocname, newname);
    free(curr->name);
    curr->name = allocname;
}

/***************************************************************************
 * llist_remove take the element at index "index" out of the list
 * (decreasing list size by 1). If the index/position doesn't exist in
 * the list, then nothing happens.
 */
void llist_remove(llist *list, int index) {
    if ((index < 0) || (index >= list->size)) {
        return;
    }

    node *prev = NULL;
    node *curr = list->first;
    for (int i=0; i<index; i++) {
        prev = curr;
        curr = curr->next;
    }

    if (prev == NULL) {
        list->first = curr->next;
    } else {
        prev->next = curr->next;
    }

    if (list->last == curr)
        list->last = prev;

    free(curr->name);
    free(curr);
    list->size--;
}

/***************************************************************************
 * llist_destroy destroys the current linked list, freeing up all memory
 * and resources. Implementation note: This is here to follow best practice
 * of providing a destructor, but for this particular data structure this
 * is the same as the llist_clear() function, so we just call that internally.
 */
void llist_destroy(llist *list) {
    llist_clear(list);
}

/***************************************************************************
 * llist_print - prints (to stdout) the strings in this linked list, with
 * commas separating them. If the list is empty, it just prints "EMPTY".
 */
void llist_print(llist *list) {
    node *curr = list->first;

    if (curr == NULL) {
        printf("EMPTY");
    }

    while (curr != NULL) {
        printf("%s", curr->name);
        curr = curr->next;
        if (curr != NULL)
            printf(", ");
    }
    putchar('\n');
}

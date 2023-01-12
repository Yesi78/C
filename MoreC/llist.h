#ifndef _LLIST_H
#define _LLIST_H

// The linked list type

typedef struct {
    struct node *first;
    struct node *last;
    int size;
} llist;

// Function prototypes

void llist_init(llist *list);
void llist_clear(llist *list);
int llist_is_empty(llist *list);
int llist_size(llist *list);
char *llist_get(llist *list, int index);
void llist_add(llist *list, char *newname);
void llist_set(llist *list, int index, char *newname);
void llist_remove(llist *list, int index);
void llist_destroy(llist *list);
void llist_print(llist *list);

#endif // _LLIST_H

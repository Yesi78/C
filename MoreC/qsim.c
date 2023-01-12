#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "llist.h"

/*
 * This program simulates a waitlist/queue for a service, using the
 * linked list of strings (llist) data structure. It is driven by
 * commands given via stdin, in which a command line starts with a
 * single letter command and any additional information is provided
 * after the command (optionally separated by spaces). Here are the
 * commands:
 *
 *    a name : Adds this name to the queue
 *    f : Print the name at the front of the queue
 *    r : Remove the name from the front of the queue
 *    p : Print the entire queue
 *    q : Quit
 */

int main(int argc, char *argv[]) {
    char *inbuffer = NULL;
    size_t buflen = 0;
    int done = 0;

    llist myqueue;
    llist_init(&myqueue);

    while (!done) {
        getline(&inbuffer, &buflen, stdin);

        /* Kill line t first cr/nl */
        char *namestart;
        for (namestart=inbuffer; *namestart != '\0'; namestart++) {
            if ((*namestart == '\n') || (*namestart == '\r')) {
                *namestart = '\0';
                break;
            }
        }

        /* Skip over spaces after the command letter. */
        namestart = inbuffer+1;
        while (isspace(*namestart))
            namestart++;

        if (inbuffer[0] == 'a') {
            llist_add(&myqueue, namestart);
        } else if (inbuffer[0] == 'f') {
            char *name = llist_get(&myqueue, 0);
            if (name != NULL) {
                printf("%s\n", name);
            } else {
                printf("EMPTY\n");
            }
        } else if (inbuffer[0] == 'r') {
            llist_remove(&myqueue, 0);
        } else if (inbuffer[0] == 'p') {
            llist_print(&myqueue);
        } else if (inbuffer[0] == 'q') {
            done = 1;
        }
    }

    llist_destroy(&myqueue);

    if (inbuffer != NULL) {
        free(inbuffer);
        inbuffer = NULL;
    }

    return 0;
}

#include "linus_list.h"

/*
    ----- CS101 version -----

    void pop(List *l, Node *target) {
        node *prev = NULL;
        node *curr = l->head;

        while (curr != target) {
            prev = curr;
            curr = curr->next;
        }

        if (prev) {
            prev->next = curr->next;
        } else {
            l->head = curr->next;
        }
    }
*/

/**
 * Utilizes double pointer to current node (curr_p)
 * to remove entry from list. Avoids edge cases with
 * head node. 
 * Begins with node, could just as easily pass the List struct 
 * and set curr_p to List.head but accomplishes same
 * 
 * If entry is not found, list is unaltered
 */
Node *pop(Node *node, Node *entry) {
    Node **curr_p;
    
    for (curr_p = &node; *curr_p; curr_p = &(*curr_p)->next) {
        if (*curr_p == entry) {
            *curr_p = (*curr_p)->next;
            break;
        }
    }

    return node;
}

/**
 * Assuming before node exists, inserts item utilizing
 * double pointer to the current node (curr_p) for
 * simplification of logic, no additional head logic
 */
void insert(List *l, Node *before, Node *item) {
    Node **curr_p = &l->head;
    while(*curr_p != before) {
        curr_p = &(*curr_p)->next;
    }

    *curr_p = item;
    item->next = before;
}

// Could be incorporated in the list struct itself
// increment/decrement on insert/pop
size_t size(List *l) {
    size_t size = 0;
    Node *curr = l->head;
    while (curr) {
        curr = curr->next;
        size++;
    }

    return size;
}
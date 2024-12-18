#ifndef LINUS_LIST_H
#define LINUS_LIST_H

#include <stddef.h>

typedef struct node {
    int val;
    struct node *next;
} Node;

typedef struct list {
    struct node *head;
} List;

size_t size(List *l);

void insert(List *l, Node *before, Node *item);

// CS 101 pop
// void pop(List *l, Node *target);

Node *pop(Node *node, Node *entry);

void pop_list(List *l, Node *entry);

#endif // LINUS_LIST_H
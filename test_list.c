#include "linus_list.c"
#include <stdio.h>
#include <assert.h>

#define N 1000

static Node nodes[N];
static List l;

static List *reset() {
    for (size_t i = 0; i < N; i++) {
        nodes[i].val = i;
        nodes[i].next = NULL;
    }

    l.head = NULL;
    return &l;
}

static void test_insert_beginning() {
    reset();
    assert(size(&l) == 0);

    for (size_t i = 0; i < N; i++) {
        insert(&l, l.head, &nodes[i]);
    }
    assert(size(&l) == N);

    size_t k = N - 1;
    Node *curr = l.head;
    while (curr) {
        assert(curr->val == k);
        k--;
        curr = curr->next;
    }
}

static void test_insert_end() {
    reset();
    assert(size(&l) == 0);

    for (size_t i = 0; i < N; i++) {
        insert(&l, NULL, &nodes[i]);
    }
    assert(size(&l) == N);

    size_t k = 0;
    Node *curr = l.head;
    while (curr) {
        assert(curr->val == k);
        k++;
        curr = curr->next;
    }
}

static void test_pop() {
    reset();
    for (size_t i = 0; i < N; i++) {
        insert(&l, NULL, &nodes[i]);
    }
    assert(size(&l) == N);

    for (size_t i = 0; i < N; i++) {
        Node *target = l.head;
        assert(target->val == i);
        pop_list(&l, target);
        assert(size(&l) == (N - i - 1));
    }

    assert(size(&l) == 0);
    assert(l.head == NULL);
}

int main() {
    test_insert_beginning();
    printf("test_insert_beginning passed!\n");

    test_insert_end();
    printf("test_insert_end passed!\n");

    test_pop();
    printf("test_pop passed!\n");

    printf("All tests passed!\n");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct element {
    int value;
    struct element* next;
};

struct element* push_item(struct element* head, int value) {
    if (head == NULL) {
        struct element* new = malloc(sizeof(struct element));
        new->value = value;
        new->next = NULL;

        return new;
    }

    struct element* current = head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = malloc(sizeof(struct element));
    current->next->value = value;
    current->next->next = NULL;

    return head;
}

struct element* pop_item(struct element* head) {
    struct element* current = head;

    if (current->next == NULL) {
        free(current);
        return NULL;
    }

    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;

    return head;
}


int top_value(struct element* head) {
    struct element* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    return current->value;
}

void print_stack(struct element* head) {
    struct element* current = head;

    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
}

int main() {
    struct element* stack = NULL;
    stack = push_item(stack, 1);
    stack = push_item(stack, 2);
    stack = push_item(stack, 3);
    stack = push_item(stack, 4);

    printf("%d\n", top_value(stack));

    stack = pop_item(stack);
    stack = pop_item(stack);
    stack = pop_item(stack);

    print_stack(stack);

    return 0;
}
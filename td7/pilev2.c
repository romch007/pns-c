#include <stdio.h>
#include <stdlib.h>

struct element {
    int value;
    struct element* next;
};

void push_item(struct element** head, int value) {
    if (*head == NULL) {
        struct element* new = malloc(sizeof(struct element));
        new->value = value;
        new->next = NULL;
        *head = new;
        return;
    }

    struct element* current = *head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = malloc(sizeof(struct element));
    current->next->value = value;
    current->next->next = NULL;
}

void pop_item(struct element** head) {
    struct element* current = *head;

    if (current->next == NULL) {
        free(current);
        return;
    }

    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
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


void free_stack(struct element* head) {
    if (head->next != NULL)
        free_stack(head->next);

    free(head);
}

int main() {
    struct element* stack = NULL;
    push_item(&stack, 1);
    push_item(&stack, 2);
    push_item(&stack, 3);
    push_item(&stack, 4);

    printf("%d\n", top_value(stack));

    pop_item(&stack);
    pop_item(&stack);
    pop_item(&stack);

    print_stack(stack);

    free_stack(stack);

    return 0;
}

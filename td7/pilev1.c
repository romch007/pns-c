#include <stdlib.h>
#include <stdio.h>

struct element {
    int value;
    struct element* next;
};

typedef struct element Element;

Element* push_item(Element* head, int value) {
    if (head == NULL) {
        Element* new = malloc(sizeof(Element));
        new->value = value;
        new->next = NULL;

        return new;
    }

    Element* current = head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = malloc(sizeof(Element));
    current->next->value = value;
    current->next->next = NULL;

    return head;
}

Element* pop_item(Element* head) {
    Element* current = head;

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


int top_value(Element* head) {
    Element* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    return current->value;
}

void print_stack(Element* head) {
    Element* current = head;

    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
}

int main() {
    Element* stack = NULL;
    stack = push_item(stack, 1);
    stack = push_item(stack, 2);
    stack = push_item(stack, 3);

    printf("%d\n", top_value(stack));

    stack = pop_item(stack);
    stack = pop_item(stack);
    stack = pop_item(stack);

    print_stack(stack);

    return 0;
}
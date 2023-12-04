#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* next;
};

struct node* create_node(int value) {
    struct node* new = malloc(sizeof(struct node));
    if (new == NULL) {
        fprintf(stderr, "cannot allocate %zu bytes\n", sizeof(struct node));
        abort();
    }
    new->value = value;
    new->next = NULL;
    return new;
}

struct node* prepend_element(struct node* head, int value) {
    struct node* new = create_node(value);
    new->next = head;
    return new;
}

struct node* append_element(struct node* head, int value) {
    struct node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = create_node(value);
    return head;
}

struct node* insert_element(struct node* head, int value) {
    if (head->value >= value) return prepend_element(head, value);

    struct node* current = head;
    while (current->next != NULL && current->next->value < value) {
        current = current->next;
    }
    struct node* new = create_node(value);
    new->next = current->next;
    current->next = new;
    return head;
}

void print_list(struct node* head) {
    printf("[");
    for (struct node* current = head; current; current = current->next) {
        printf("%d,", current->value);
    }
    printf("]\n");
}

void destroy_list(struct node* head) {
    if (head->next)
        destroy_list(head->next);

    free(head);
}

int main() {
    struct node* list = create_node(1);
    list = append_element(list, 2);
    list = append_element(list, 3);
    list = append_element(list, 4);
    list = append_element(list, 6);
    list = append_element(list, 7);
    list = insert_element(list, 5);
    list = insert_element(list, 0);
    print_list(list);
    destroy_list(list);
    return 0;
}
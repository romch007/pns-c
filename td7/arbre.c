#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* left;
    struct node* right;
};

struct node* create_empty_tree(int initial_value) {
    struct node* t = malloc(sizeof(struct node));
    t->value = initial_value;
    t->left = NULL;
    t->right = NULL;
    return t;
}

struct node* add_tree(struct node* t, int v) {
    if (t == NULL) {
        return create_empty_tree(v);
    } else if (v <= t->value) {
        t->left = add_tree(t->left, v);
    } else if (v > t->value) {
        t->right = add_tree(t->right, v);
    }

    return t;
}

void print_tree(struct node* t) {
    if (t->left != NULL)
        print_tree(t->left);

    printf("%d ", t->value);

    if (t->right != NULL)
        print_tree(t->right);
}

struct node* find_tree(struct node* t, int v) {
    if (t == NULL) {
        return NULL;
    } else if (t->value == v) {
        return t;
    } else if (t->value > v) {
        return find_tree(t->left, v);
    } else {
        return find_tree(t->right, v);
    }
}

void free_tree(struct node* t) {
    if (t->left != NULL)
        free_tree(t->left);

    if (t->right != NULL)
        free_tree(t->right);

    free(t);
}

int main() {
    struct node* t = create_empty_tree(8);

    t = add_tree(t, 3);
    t = add_tree(t, 10);
    t = add_tree(t, 1);
    t = add_tree(t, 6);
    t = add_tree(t, 7);
    t = add_tree(t, 4);
    t = add_tree(t, 14);
    t = add_tree(t, 13);

    printf("Valeurs dans l'arbre: ");
    print_tree(t);
    printf("\n");

    printf("\nRecherches:\n");
    for (int i = 0; i < 20; i++) {
        printf("%2d: %s, ", i, find_tree(t, i) ? "oui" : "non");
        if (i % 5 == 4) printf("\n");
    }

    printf("\nLibération mémoire de l'arbre:\n");
    free_tree(t);
    return 0;
}
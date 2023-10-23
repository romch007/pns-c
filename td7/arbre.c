#include <stdlib.h>
#include <stdio.h>

struct node {
    int value;
    struct node *left;
    struct node *right;
};

typedef struct node *tree;

tree create_empty_tree(void) {
    tree t = malloc(sizeof(tree));
    t->value = 0;
    t->left = NULL;
    t->right = NULL;
    return t;
}

tree add_tree(tree t, int v) {
   if (t == NULL) {
       tree new_tree = create_empty_tree();
       new_tree->value = v;
       return new_tree;
   } else if (v <= t->value) {
       t->left = add_tree(t->left, v);
   } else if (v > t->value) {
       t->right = add_tree(t->right, v);
   }

   return t;
}

void print_tree(tree t) {

    if (t->left != NULL)
        print_tree(t->left);

    printf("%d ", t->value);

    if (t->right != NULL)
        print_tree(t->right);
}

tree find_tree(tree t, int v) {
    if (t->value == v) {
        return t;
    } else if (t->value < v) {
        if (t->left == NULL) return NULL;
        return find_tree(t->left, v);
    } else {
        if (t->right == NULL) return NULL;
        return find_tree(t->right, v);
    }
}

void free_tree(tree t) {
    if (t->left != NULL)
        free_tree(t->left);

    if (t->right != NULL)
        free_tree(t->right);

    free(t);
}

int main() {
    tree t = create_empty_tree();

    t = add_tree(t, 8);
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
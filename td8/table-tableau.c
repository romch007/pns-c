#include "table.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//
// Fonctions elementaires de manipulation de la table
//

struct table {
    char* str;
    int occur;
};

#define INITIAL_CAPACITY 1
#define GROW_FACTOR      2

size_t size = 0;
size_t capacity = INITIAL_CAPACITY;

/* Creation d'une table vide */
Table creer_table(void) {
    return malloc(sizeof(struct table) * capacity);
}

/* Insertion d'un élément dans la table triée. Si l'élément est déjà
 * présent dans la table, le compteur d'occurrences est incrémenté.
 * La fonction renvoie le nombre actuel d'occurrences de elt */
int ajouter_table(Table* table, char* elt) {
    struct table* elements = *table;
    size_t i;
    for (i = 0; i < size; i++) {
        if (strcmp(elements[i].str, elt) == 0) {
            return ++elements[i].occur;
        }
    }

    if (size >= capacity) {
        capacity *= GROW_FACTOR;
        elements = realloc(elements, sizeof(struct table) * capacity);
        *table = elements;
    }

    elements[size].str = strdup(elt);
    elements[size].occur = 1;
    size++;
    return 1;
}

/* Impression triée des éléments de la table */
void imprimer_table(Table table) {
    for (size_t i = 0; i < size; i++) {
        printf("%s - occur: %d\n", table[i].str, table[i].occur);
    }
}

/* Appel d'une fonction sur chacun des éléments de la table */
void appliquer_table(Table table, t_fonction fonction) {
    for (size_t i = 0; i < size; i++) {
        fonction(table[i].str, table[i].occur);
    }
}

/* Recherche du nombre d'occurrences d'un élément */
int rechercher_table(Table table, char* elt) {
    for (size_t i = 0; i < size; i++) {
        if (strcmp(table[i].str, elt) == 0)
            return table[i].occur;
    }
    return -1;
}

/* Destruction d'une table */
void detruire_table(Table* table) {
    struct table* elements = *table;
    for (size_t i = 0; i < size; i++) {
        free(elements[i].str);
    }
    free(elements);
}

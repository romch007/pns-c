#include "table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct table {
    char* str;
    int occur;
    struct table* next;
};

//
// Fonctions elementaires de manipulation de la table
//

/* Creation d'une table vide */
Table creer_table(void) {
    return NULL;
}

/* Insertion d'un élément dans la table triée. Si l'élément est déjà
 * présent dans la table, le compteur d'occurrences est incrémenté.
 * La fonction renvoie le nombre actuel d'occurrences de elt */
int ajouter_table(Table* table, char* elt) {
    struct table** current = (struct table**) table;

    while (*current != NULL) {
        if (strcmp(elt, (*current)->str) == 0) {
            return ++(*current)->occur;
        }

        current = &(*current)->next;
    }

    struct table* new = malloc(sizeof(struct table));
    new->str = strdup(elt);
    new->occur = 1;
    new->next = NULL;

    *current = new;

    return 1;
}

/* Impression triée des éléments de la table */
void imprimer_table(Table table) {
    struct table* current = table;

    while (current != NULL) {
        printf("'%s', occur: %d\n", current->str, current->occur);
        current = current->next;
    }
}

/* Appel d'une fonction sur chacun des éléments de la table */
void appliquer_table(Table table, t_fonction fonction) {
    struct table* current = table;

    while (current != NULL) {
        fonction(current->str, current->occur);
        current = current->next;
    }
}

/* Recherche du nombre d'occurrences d'un élément */
int rechercher_table(Table table, char* elt) {
    struct table* current = table;

    while (current != NULL) {
        if (strcmp(current->str, elt) == 0) {
            return current->occur;
        }
    }

    return -1;
}

/* Destruction d'une table */
void detruire_table(Table* table) {
   struct table** head = (struct table**) table;
   if ((*head)->next != NULL)
        detruire_table((Table*) &(*head)->next);

   free((*head)->str);
   free(*head);
}

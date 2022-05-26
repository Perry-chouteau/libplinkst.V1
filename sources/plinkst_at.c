
/*
** EPITECH PROJECT, 2020
** B-EXAMPLE-100-PAR-1-3-example-perry.chouteau
** File description:
** plinkst_at.c
*/


#include "plinkst.h"

static void *plinkst_create(void *data)
{
    linkst_t *node = malloc(sizeof(linkst_t));

    node->data = data;
    node->next = NULL;
    return node;
}

void plinkst_add_at(linkst_t **list, void *data, int pos)
{
    linkst_t *cell = plinkst_create(data);
    linkst_t *prec = list[0];
    linkst_t *cur = list[0];
    unsigned int i = 0;

    if (list[0] == NULL) {
        list[0] = cell;
        return ;
    } else if (pos <= 0) {
        cell->next = list[0];
        list[0] = cell;
        return ;
    }
    for (;i < pos && cur != NULL; i++) {
        prec = cur;
        cur = cur->next;
    }
    prec->next = cell;
    cell->next = cur;
}

void *plinkst_get_at(linkst_t **list, int pos)
{
    linkst_t *cur = *list;

    for (int i = 0; i < pos && cur->next != NULL; i += 1) {
        cur = cur->next;
    }
    return cur->data;
}

void plinkst_set_at(linkst_t **list, void *data, int pos)
{
    linkst_t *cur = list[0];

    for (int i = 0; i < pos && cur->next != NULL; i += 1) {
        cur = cur->next;
    }
    cur->data = data;
}

/**
 * @brief use a li
 * 
 * @param list 
 * @param pos 
 */
void plinkst_free_at(linkst_t **list, int pos, bool free_data)
{
    linkst_t *prec = list[0];
    linkst_t *cur = list[0];

    if (list[0] == NULL)
        return ;
    if (pos <= 0 || cur->next == NULL) {
        list[0] = list[0]->next;
        (free_data) ? free(prec->data) : 0;
        free(prec);
        return ;
    }
    for (int i = 0; i < pos && cur->next != NULL; i += 1) {
        prec = cur;
        cur = cur->next;
    }
    prec->next = (cur->next != NULL) ? cur->next : NULL;
    (free_data) ? free(cur->data) : 0;
    free(cur);
}
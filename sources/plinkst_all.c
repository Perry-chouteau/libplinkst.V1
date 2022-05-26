/*
** EPITECH PROJECT, 2020
** B-EXAMPlistE-100-PAR-1-3-exampliste-perry.chouteau
** File description:
** empty_listinked_list.c
*/

#include "plinkst.h"

void *plinkst_empty(void)
{
    return NULL;
}

int plinkst_len(linkst_t **list)
{
    linkst_t *cur = list[0];
    unsigned int i = 1;

    if (cur == NULL)
        return 0;
    for (; cur->next != NULL; i += 1)
        cur = cur->next;
    return i;
}

void plinkst_free(linkst_t **list, bool free_data)
{
    linkst_t *prec = list[0];

    while (list[0] != NULL) {
        list[0] = list[0]->next;
        (free_data) ? free(prec->data) : 0;
        free(prec);
        prec = list[0];
    }
}

void plinkst_print(linkst_t **list, void (*function)(void *))
{
    linkst_t *cur = list[0];

    for (; cur != NULL; cur = cur->next) {
        function(cur->data);
    }
}

//void linkst_array_from_list(linkst_t **list, void *(*function)(void *))
//{
//    linkst_t *cur = list[0];
//
//    for (; cur != NULL; cur = cur->next) {
//        function(cur->data);
//    }
//    return function(list);
//}
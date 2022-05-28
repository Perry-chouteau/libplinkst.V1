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

void **plinkst_to_array(linkst_t **list)
{
    linkst_t *cur = list[0];
    unsigned int len = plinkst_len(list);
    void **array_data = malloc(sizeof(void *) * (len + 1));
    
    array_data[len] = NULL;
    for (int i = 0; cur != NULL; cur = cur->next , i++) {
        array_data[i] = cur->data;
    }
    return array_data;
}

void **plinkst_to_array_function(linkst_t **list, void *(*function)(void *))
{
    linkst_t *cur = list[0];
    unsigned int len = plinkst_len(list);
    void **array_data = malloc(sizeof(void *) * (len + 1));

    array_data[len] = NULL;
    for (int i = 0; cur != NULL; cur = cur->next , i++) {
        array_data[i] = function(cur->data);
    }
    return array_data;
}
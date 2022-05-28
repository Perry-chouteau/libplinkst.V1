/*
** EPITECH PROJECT, 2020
** B-MUL-mydefender-perry.chouteau
** File description:
** rect.h
*/

#ifndef MY_CSFML_H
#define MY_CSFML_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct linkst_s {
    void *data;
    void *next;
} linkst_t;

void plinkst_add_at(linkst_t **linkst, void *data, int pos);
void *plinkst_get_at(linkst_t **linkst, int pos);
void plinkst_set_at(linkst_t **linkst, void *data, int pos);
void plinkst_free_at(linkst_t **linkst, int pos, bool free_data);

void *plinkst_empty(void);
int plinkst_len(linkst_t **list);
void plinkst_free(linkst_t **linkst, bool free_data);
void plinkst_print(linkst_t **list, void (*function)(void *));
void **plinkst_to_array(linkst_t **list);
void **plinkst_to_array_function(linkst_t **list, void *(*function)(void *));

#endif
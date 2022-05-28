/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-perry.chouteau
** File description:
** test
*/

#include "plinkst.h"
#include <stdbool.h>
#include <stdio.h>

typedef struct client_data_s {
    int fd;
    bool log;
    char *name;
} client_data_t;

typedef struct client_linklist_s {
    client_data_t *data;
    struct client_linkst_s *next;
} client_linkst_t;
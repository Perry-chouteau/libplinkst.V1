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



























//#include <poll.h>

/*typedef struct pollfd pollfd_t;

//char
typedef struct str_linklist_s {
    char *data;
    str_linkst_t *next;
} str_linkst_t;

//client
typedef struct client_data_s {
    int fd;
    bool log;
    pollfd_t *client;
    pollfd_t *team;
    char name[32];
} client_data_t;

typedef struct client_linklist_s {
    client_data_t *data;
    client_linkst_t *next;
} client_linkst_t;

//team
typedef struct client_data_s {
    int fd;
    bool log;
    str_linkst_t *client;
    str_linkst_t *team;
    char name[32];
} client_data_t;

typedef struct client_linklist_s {
    client_data_t *data;
    client_linkst_t *next;
} client_linkst_t;


//server
typedef struct server_data_s {
    int fd;
    pollfd_t *client;
    pollfd_t *team;
} server_data_t;

typedef struct server_s {
    int server_fd; //socket
    struct sockaddr_in server_addr;
    int n_clients;
    client_linkst_t *clients;
    team_linkst_t *clients;
} server_t;
*/
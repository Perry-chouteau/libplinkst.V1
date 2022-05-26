/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-perry.chouteau
** File description:
** test
*/

#include "test.h"
//#include <poll.h>

client_data_t *create_data(int fd, bool log, char *name)
{
    client_data_t *data = malloc(sizeof(client_data_t));
    data->fd = fd;
    data->log = log;
    data->name = name;
}

void display_data(client_data_t *data)
{
    printf("{%i, %s, %s}\n", data->fd, (data->log ? "true" : "false"), data->name);
}

int main(void)
{
    printf("start\n");
    client_linkst_t *client = plinkst_empty();
    printf("add0\n");
    plinkst_add_at(&client, create_data(0, true, "hey"), 0);
    printf("display1\n");
    plinkst_print(&client, display_data);
    printf("add2\n");
    plinkst_add_at(&client, create_data(0, true, "1bye"), 100);
    plinkst_add_at(&client, create_data(0, true, "2"), 100);
    plinkst_add_at(&client, create_data(0, true, "3bye"), 100);
    plinkst_add_at(&client, create_data(0, true, "4bye"), 100);
    printf("display2\n");
    plinkst_print(&client, display_data);
    printf("free_at\n");
    plinkst_free_at(&client, 100, true);
    printf("display3\n");
    plinkst_print(&client, display_data);
    printf("free\n");
    plinkst_free(&client, true);
    plinkst_print(&client, display_data);
    printf("display5\n");
    printf("stop\n");
}
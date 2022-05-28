/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-perry.chouteau
** File description:
** test
*/

#include "example.h"
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

void *get_name_from_data(client_data_t *data)
{
    return data->name;
}


int main(void)
{
    printf("start\n");
    printf("> LINKST p1\n");
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
    printf("plinkst_to_array\n");
    printf("> ARRAY\n");
    client_data_t **array_data = plinkst_to_array(&client);
    printf("display data\n");
    for (int i = 0; array_data[i] != NULL; i++)
        display_data(array_data[i]);
    free(array_data);
    char **array_name = plinkst_to_array_function(&client, get_name_from_data);
    printf("display name\n");
    for (int i = 0; array_name[i] != NULL; i++)
        printf("%s\n", array_name[i]);
    free(array_name);
    printf("> LINKST p2\n");
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
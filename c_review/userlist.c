#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "userlist.h"

usernode *make_user_list()
{
    usernode *head = (usernode *)malloc(sizeof(usernode));
    if (head == NULL) 
    {
        error_out("out of memory!");
    }
    head->id = -1;
    head->name = NULL;
    head->next = head;
    head->prev = head;
    return head;
}

void add_user(usernode *head, int id, char *name)
{
    if (head == NULL || name == NULL)
    {
        error_out("add_user called incorrectly!");
    }

    usernode *new = (usernode *)malloc(sizeof(usernode));
    if (new == NULL) 
    {
        error_out("out of memory!");
    }
    new->id = id;
    new->name = name;

    // add to end of list
    new->next = head;
    new->prev = head->prev;

    head->prev->next = new;
    head->prev = new;
}

void print_users(usernode *head)
{
    if (head == NULL)
    {
        error_out("print_users called incorrectly!");
    }

    usernode *cur = head->next;
    while (cur != head)
    {
        printf("%s,%i\n", cur->name, cur->id);
        cur = cur->next;
    }
}

void destroy_user_list(usernode *head)
{
    if (head == NULL)
    {
        error_out("destroy_user_list called incorrectly!");
    }

    usernode *cur = head->next;
    while (cur != head)
    {
        cur = cur->next;
        free(cur->prev);
    }
    free(head);
}

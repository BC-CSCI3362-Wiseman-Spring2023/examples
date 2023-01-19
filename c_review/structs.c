#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>

typedef struct _usernode
{
    int id;
    char *name;
    struct _usernode *next;
    struct _usernode *prev;
} usernode;

void error_out(char *msg)
{
    printf("Error! %s\n", msg);
    exit(1);
}

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

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("usage: %s name [name...]\n", basename(argv[0]));
        exit(1);
    }

    usernode *userlist = make_user_list();
    for (int i=1; i<argc; ++i)
    {
        add_user(userlist, i-1, argv[i]);
    }

    print_users(userlist);

    destroy_user_list(userlist);

    return 0;
}

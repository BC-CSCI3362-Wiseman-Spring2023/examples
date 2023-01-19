#ifndef USERLIST_H
#define USERLIST_H

typedef struct _usernode
{
    int id;
    char *name;
    struct _usernode *next;
    struct _usernode *prev;
} usernode;

usernode *make_user_list();
void add_user(usernode *head, int id, char *name);
void print_users(usernode *head);
void destroy_user_list(usernode *head);

#endif // USERLIST_H

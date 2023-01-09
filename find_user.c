#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "find_info.h"
void find_user(account *head_acc, char *username)
{
    account *cur_acc = head_acc->next_acc;
    int situation = 0;
    while (cur_acc) /*searching the user with this username*/
    {
        if (strcmp(cur_acc->username, username) == 0)
        {
            situation = 1;
            info(cur_acc, situation); /*going to info function where it show the posts of this account*/
        }
        cur_acc = cur_acc->next_acc;
    }
    if (situation == 0) /*checking if the user has been found or not*/
        printf("there is no account with this username\n");
}
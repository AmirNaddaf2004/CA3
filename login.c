#include <string.h>
#include "structures.h"
#include "login.h"

account *login(char *username, char *password, account *head_acc)
{
    account *cur_acc = head_acc; /*setting cur_acc to head of the list*/
    while (cur_acc->next_acc)
    {
        cur_acc = cur_acc->next_acc; /*going down into list and finding the username*/
        if (strcmp(cur_acc->username, username) == 0)
        {
            if (strcmp(cur_acc->password, password) == 0)/*checking if the password maches with accounts password or not*/
                return cur_acc;
        }
    }
    return NULL;
}
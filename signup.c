#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structures.h"
#include "signup.h"
int signup(char *username, char *password, account *head_acc)
{
    account *check = head_acc;
    while (check) /*checking if there is any account with this username or not*/
    {
        if (strcmp(check->username, username) == 0)
        {
            printf("there is an account with this username!\n");
            return 0;
        }
        check = check->next_acc;
    }
    account *cur_acc = head_acc; /*initialize*/
    account *new_acc = (account *)malloc(sizeof(account));
    while (cur_acc->next_acc) /*setting cur_acc to last account in linked list*/
    {
        cur_acc = cur_acc->next_acc;
    }
    cur_acc->next_acc = new_acc; /*setting new_acc to last account in linked list*/
    new_acc->username = (char *)malloc((strlen(username) + 1) * sizeof(char)); /*copying data of new_account in it and initializing its variables*/
    new_acc->password = (char *)malloc((strlen(password) + 1) * sizeof(char));
    strcpy(new_acc->username, username);
    strcpy(new_acc->password, password);
    new_acc->num_of_posts = 0;
    new_acc->post_head = NULL;
    new_acc->next_acc = NULL;
    printf("signedup successfully\n");
    return 1;
}
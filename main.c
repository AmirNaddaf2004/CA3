#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "signup.h"
#include "login.h"
#include "delete.h"
#include "post.h"
#include "find_info.h"
#include "like.h"
#include "save.h"
#define TRUE 1
#define ONE 1

int main()
{
    int situation = 0; /*initializing*/
    account *head_acc = (account *)malloc(sizeof(account));
    head_acc->username = (char *)malloc(sizeof(char));
    *(head_acc->username) = '\0';
    head_acc->next_acc = NULL;
    account *loggedin_acc;
    int result;
    while (TRUE)
    {
        char *command = (char *)malloc(sizeof(char)); /*getting command from user*/
        char *username, temp;
        int length = 1;
        while ((temp = getchar()) != ' ' && temp != '\n')
        {
            *(command + length - ONE) = temp;
            command = (char *)realloc(command, sizeof(char) * (length + 1));
            length++;
        }
        *(command + length - ONE) = '\0';
        if ((strcmp("signup", command) == 0) || (strcmp("login", command) == 0) || (strcmp("like", command) == 0) || (strcmp("find_user", command) == 0)) /*checking if the next string is username or not*/
        {
            length = 1;
            username = (char *)malloc(sizeof(char)); /*getting username*/
            while ((temp = getchar()) != ' ' && temp != '\n')
            {
                *(username + length - ONE) = temp;
                username = (char *)realloc(username, sizeof(char) * (length + 1));
                length++;
            }
            *(username + length - ONE) = '\0';
        }
        if (situation == 0) /*checking if user is in an account or not*/
        {
            char *password = (char *)malloc(sizeof(char)); /*getting password*/
            if ((strcmp(command, "signup") == 0) || (strcmp(command, "login") == 0))
            {
                length = 1;
                while ((temp = getchar()) != '\n')
                {
                    *(password + length - ONE) = temp;
                    password = (char *)realloc(password, sizeof(char) * (length + 1));
                    length++;
                }
                *(password + length - ONE) = '\0';
            }
            if ((strcmp("signup", command)) == 0) /*checking if the command is signup or not and if it was, going to signup function*/
                signup(username, password, head_acc);
            else if ((strcmp("login", command)) == 0) /*checking if the command is login or not and if it was, going to login function*/
            {
                loggedin_acc = login(username, password, head_acc);
                if (loggedin_acc != NULL) /*checking if login was successful or not*/
                {
                    printf("loggedin successfully\n");
                    situation = 1;
                }
                else
                    printf("your username or password is incorrect\n");
            }
            else
                printf("you didn't login yet\n");
            free(password); /*make the memmory free*/
        }
        else /*in this situation user is in an account*/
        {
            int ID;
            if ((strcmp("delete", command) == 0) || (strcmp(command, "like") == 0)) /*checking if the next entry is ID or not (by command)*/
                scanf("%d", &ID);
            if (strcmp("post", command) == 0) /*checking if command was post and if it was, going into post function*/
                post_f(loggedin_acc);
            else if (strcmp("like", command) == 0) /*checking if command was like and if it was, going into like function*/
                like(loggedin_acc, head_acc, username, ID);
            else if (strcmp("delete", command) == 0) /*checking if command was delete and if it was, going into delete function*/
            {
                result = delete (loggedin_acc, ID);
                if (result == 0) /*checking if the post deleted successfully or not*/
                    printf("there is no post with that post_ID\n");
                else
                    printf("post is deleted\n");
            }
            else if (strcmp("info", command) == 0) /*checking if command was info and if it was, going into info function*/
                info(loggedin_acc, (situation - 1));
            else if (strcmp("find_user", command) == 0) /*checking if command was find_user and if it was, going into find_user function*/
                find_user(head_acc, username);
            else if (strcmp("logout", command) == 0) /*checking if command was logout or not and if it was, logout*/
            {
                printf("loggedout successfully\n");
                situation = 0;
            }
            else
                printf("you are in an account and your command wasn't correct for this situation\n");
        }
        fflush(stdin);           /*flushing the buffer*/
        free(command);           /*make the memmory free*/
        free(username);          /*make the memmory free*/
        write_in_file(head_acc); /*writing info in files*/
    }
    return 0;
}
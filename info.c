#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "find_info.h"

void info(account *searched_acc, int situation)
{
    if (situation == 0) /*checking if user wants his info or others info*/
    {
        printf("username: %s\npassword: %s\n", searched_acc->username, searched_acc->password); /*printing username and password of his account*/
    }
    post *cur_post = searched_acc->post_head;
    if (cur_post == NULL) /*checking if the account has any post*/
        printf("this user doesn't have any post yet\n");
    while (cur_post)
    {
        printf("post: %s\npost_ID: %d\nlikes: %d\n", cur_post->post_string, cur_post->post_ID, cur_post->like); /*printing the posts and post infos*/
        cur_post = cur_post->next_post;
    }
}
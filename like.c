#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "like.h"

int like(account *loggedin_acc, account *head_acc, char *username, int ID)
{
    account *cur_acc = head_acc; /*initializing*/
    int user_founded = 0, post_founded = 0;
    while (cur_acc) /*finding the account with that username*/
    {
        if (strcmp(cur_acc->username, username) == 0)
        {
            user_founded++;
            break;
        }
        cur_acc = cur_acc->next_acc;
    }
    if (user_founded == 0) /*checking if username has been founded*/
    {
        printf("there is no account with that username\n");
        return -1;
    }
    post *cur_post = cur_acc->post_head;
    while (cur_post) /*finding the post with that post ID*/
    {
        if (cur_post->post_ID == ID)
        {
            cur_post->like++;
            post_founded++;
            break;
        }
        cur_post = cur_post->next_post;
    }
    if (post_founded == 0) /*checking if the post has been founded or not*/
    {
        printf("there is no post with that post_ID\n");
        return 0;
    }
    likers *perv_liker = cur_post->head_liker;
    while (perv_liker) /*checking if that user liked that post before*/
    {
        if (strcmp(perv_liker->username, loggedin_acc->username) == 0)
        {
            cur_post->like--;
            printf("you already liked this post with this account\n");
            return -2;
        }
        perv_liker = perv_liker->next_like;
    }
    perv_liker = cur_post->head_liker; /*initializing to add a new liker*/
    likers *adding_liker = (likers *)malloc(sizeof(likers));
    adding_liker->username = (char *)malloc((strlen(loggedin_acc->username) + 1) * sizeof(char));
    strcpy(adding_liker->username, loggedin_acc->username);
    adding_liker->next_like = NULL;
    if (perv_liker == NULL) /*if no one like that post before setting the user, the first liker of the postt*/
    {
        cur_post->head_liker = adding_liker;
    }
    else
    {
        while (perv_liker->next_like) /*setting the user, last liker in the list*/
            perv_liker = perv_liker->next_like;
        perv_liker->next_like = adding_liker;
    }
    printf("liked successfully\n");
    return 1;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "post.h"

void post_f(account *loggedin_acc)
{
    char *post_string = (char *)malloc(sizeof(char)), temp; 
    int length = 1;
    while ((temp = getchar()) != '\n') /*getting the post string*/
    {
        *(post_string + length - 1) = temp;
        post_string = (char *)realloc(post_string, sizeof(char) * (length + 1));
        length++;
    }
    *(post_string + length - 1) = '\0';
    post *adding_post = (post *)malloc(sizeof(post)); /*setting a new post and initializing it*/
    adding_post->post_string = (char *)malloc((strlen(post_string) + 1) * sizeof(char));
    strcpy(adding_post->post_string, post_string);
    free(post_string); /*making the memmory free*/
    (loggedin_acc->num_of_posts)++;
    adding_post->like = 0;
    adding_post->head_liker = NULL;
    adding_post->next_post = NULL;
    post *perv_post = loggedin_acc->post_head, *cur_post;
    if (perv_post == NULL)/*if there is no post before this setting the adding post to first post in list*/
    {
        adding_post->post_ID = 1;
        loggedin_acc->post_head = adding_post;
    }
    else
    {
        cur_post = perv_post->next_post;
        while (cur_post)/*setting the cur_post, the last post in the list*/
        {
            perv_post = cur_post;
            cur_post = cur_post->next_post;
        }
        adding_post->post_ID = (perv_post->post_ID) + 1; /*setting the ID of new post*/
        perv_post->next_post = adding_post; /*adding the new post into the end of the list*/
    }
    printf("posted successfully\n");
}
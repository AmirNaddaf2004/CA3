#include <string.h>
#include <stdlib.h>
#include "structures.h"
#include "delete.h"

int delete(account *loggedin_acc, int ID)
{
    if (loggedin_acc->num_of_posts == 0)
        return 0;
    post *perv_post = loggedin_acc->post_head, *cur_post = perv_post->next_post;
    if (perv_post->post_ID == ID) /*checking if user wants to delete the first post on the list*/
    {
        free(perv_post); /*making where the post saved free*/
        if (perv_post->next_post == NULL)
            loggedin_acc->post_head = NULL; /*updating the list and setting new head*/
        else
            loggedin_acc->post_head = cur_post; /*updating the list and setting new head*/
        (loggedin_acc->num_of_posts)--;         /*updating the number of posts*/
        return 1;
    }
    else
    {
        while (cur_post) /*finding the post which should be deleted*/
        {
            if (cur_post->post_ID == ID)
            {
                perv_post->next_post = cur_post->next_post; /*removing the post from the list*/
                free(cur_post);                             /*making where the post saved free*/
                (loggedin_acc->num_of_posts)--;             /*updating number of posts*/
                return 1;
            }
            perv_post = cur_post;
            cur_post = cur_post->next_post;
        }
    }
    return 0;
}

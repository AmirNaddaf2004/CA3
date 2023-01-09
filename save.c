#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "save.h"

void write_in_file(account *head_acc)
{
    FILE *acc_file = fopen("accounts.txt", "w"); /*opening files*/
    FILE *post_file = fopen("posts.txt", "w");
    account *cur_acc = head_acc->next_acc;
    while (cur_acc)
    {
        fwrite(cur_acc->username, sizeof(char), strlen(cur_acc->username), acc_file); /*writing account info in accounts file*/
        fprintf(acc_file, " ");
        fwrite(cur_acc->password, sizeof(char), strlen(cur_acc->password), acc_file);
        fprintf(acc_file, " ");
        fprintf(acc_file, "%d", cur_acc->num_of_posts);
        fprintf(acc_file, "\n");
        post *cur_post = cur_acc->post_head;
        while (cur_post) /*writing posts of the account in posts file*/
        {
            fwrite(cur_post->post_string, sizeof(char), strlen(cur_post->post_string), post_file);
            fprintf(post_file, " ");
            fwrite(cur_acc->username, sizeof(char), strlen(cur_acc->username), post_file);
            fprintf(post_file, " ");
            fprintf(post_file, "%d", cur_post->like);
            fprintf(post_file, "\n");
            cur_post = cur_post->next_post;
        }
        cur_acc = cur_acc->next_acc; /*going down in the list*/
    }
    fclose(acc_file); /*closing files*/
    fclose(post_file);
}

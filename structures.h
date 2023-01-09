#ifndef std
#define std
typedef struct posts post;
typedef struct accounts account;
typedef struct likers likers;

struct accounts
{
    char *username;
    char *password;
    post *post_head;
    int num_of_posts;
    account *next_acc;
};
struct posts
{
    char *post_string;
    int post_ID;
    int like;
    likers *head_liker;
    post *next_post;
};
struct likers
{
    char *username;
    likers *next_like;
};

#endif

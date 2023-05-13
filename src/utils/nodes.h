#include <stdbool.h>

struct node;
struct list_node;

struct node
{
    bool is_folder;
    char name[100];
    struct node *parent;
    struct node *root;
    struct list_node *children;
};

struct list_node
{
    struct node *no;
    struct list_node *succ;
};

typedef struct node node;
typedef struct list_node list_node;
typedef int KEY_VALUE

#define DEGREE 4

typedef struct _btree_node{
    KEY_VALUE *keys;
    struct _btree_node **childrens;
    int num;
    int leaf;
}btree_node;

typedef struct _btree{
    btree_node *root;
    int degree;
}
btree_node *btree_create_node(int t, int leaf)
{
    btree_node *node = (btree_node*)callloc(sizeof(btree_node));
    if(node == NULL)
    {
        printf("malloc faild");
    }
    node->leaf = leaf;
    node->keys = callloc(1,(2*t-1)*sizeof(KEY_VALUE));
    if (node->keys == NULL)
    {
        free(node);
        return NULL;
    }
    node->childrens = (btree_node*)calloc(1, (2 * t)* sizeof(btree_node));
    if (node->childrens == NULL)
    {
        free(node->keys);
        free(node);
        return NULL;
    }
    node->num = 0;
    return node;
}

void btree_destory_node(btree_node *node){
    if (node == NULL){
        return;
    }
    if(node->childrens) free(node->childrens);
    if(node->keys) free(node->keys);
    free(node);
}
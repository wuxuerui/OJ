typedef int KEY_VALUE;
#define BLACK       0
#define RED         1
typedef struct _rbtree_node {
    unsigned char color;
    struct rbtree_node *left;
    struct rbtree_node *right;
    struct rbtree_node *parent;
    KEY_VALUE key;

    void *value;
}rbtree_node;
typedef struct _rbtree{
    struct _rbtree_node *root;
    struct _rbtree_node *nil;
}rbtree;
/*
    x                           y
  /   \       左右旋转          /  \
  a     y      <=>            x   c
       / \                   / \
       b  c                 a   b

*/
///左旋，右旋同理，x换y left换rightright right换left
void rbtree_left_rotate(rbtree *T, rbtree_node *x)
{
    ///三对六个方向
    rbtree_node *y = x->right;
    x->right = y->left;
    if(y->left != T->nil){
        y->left->parent = x;
    }

    y->parent = x->parent;
    if(x->parent == T->nil){
        T->root = y;
    }
    else if (x == x->parent->left){
        x->parent->left = y;
    }
    else{
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void rbtree_insert(rbtree *T, rbtree_node *z)
{
    rbtree_node *y = T->nil;
    rbtree_node *x = T->root;
    while(x != T->nil)
    {
        y = x;
        if(z->key < x->key){
            x = x->left;
        }else if (z->key > x->key){
            x= x->right
        }else{
            return ;
        }
    }
    z->parent = y;
    if (y == T->nil)
    {
        T->root = z;
    }else if (z->key < y->key){
        y->left = z;
    }else{
        y->right = z;
    }
    z->left = T->nil;
    z->right = T->nil;
}

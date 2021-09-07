#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node {
    struct tree_node *parent;
    struct tree_node *left;
    struct tree_node *right;
    int data;
    int color;
} tree_node;

typedef struct rbtree {
    tree_node *root;
    tree_node *NIL;
} rbtree;

tree_node *new_tree_node(int data) {
    tree_node *n = malloc(sizeof(tree_node));

    n -> parent = NULL;
    n -> left = NULL;
    n -> right = NULL;
    n -> data = data;
    n -> color = 1;

    return n;
}

rbtree* new_rbtree() {
    rbtree *t = malloc(sizeof(rbtree));
    tree_node *nil_node = malloc(sizeof(tree_node));

    nil_node -> parent = NULL;
    nil_node -> left = NULL;
    nil_node -> right = NULL;
    nil_node -> data = 0;
    nil_node -> color = 0;
    t -> NIL = nil_node;
    t -> root = t -> NIL;

    return t;
}

void left_rotation(rbtree *t, tree_node *x) {
    tree_node *y = x -> right;

    x -> right = y -> left;

    if (y -> left != t -> NIL) {
        y -> left -> parent = x;
    }
    
    y -> parent = x -> parent;

    if (x -> parent == t -> NIL) {
        t -> root = y;
    }
    else if (x == x -> parent -> left) {
        x -> parent -> left = y;
    }
    else {
        x -> parent -> right = y;
    }
    y -> left = x;
    x -> parent = y;
}

void right_rotation(rbtree *t, tree_node *x) {
    tree_node *y = x -> left;

    x -> left = y -> right;

    if (y -> right != t -> NIL) {
        y -> right -> parent = x;
    }

    y -> parent = x -> parent;

    if (x -> parent == t -> NIL) {
        t -> root = y;
    }
    else if (x == x -> parent -> right) {
        x -> parent -> right = y;
    }
    else {
        x -> parent -> left = y;
    }
    y -> right = x;
    x -> parent = y;
}

void insertion_fixup(rbtree *t, tree_node *z) {
    while (z -> parent -> color == 1) {
        if (z -> parent == z -> parent -> parent -> left) {
            tree_node *y = z -> parent -> parent -> right;

            if (y -> color == 1) {
                z -> parent -> color = 0;
                y -> color = 0;
                z -> parent -> parent -> color = 1;
                z = z -> parent -> parent;
            }
            else {
                if (z == z -> parent -> right) {
                    z = z -> parent;
                    left_rotation(t, z);
                }
                z -> parent -> color = 0;
                z -> parent -> parent -> color = 1;
                right_rotation(t, z -> parent -> parent);
            }
        }
        else {
            tree_node *y = z -> parent -> parent -> left;

            if (y -> color == 1) {
                z -> parent -> color = 0;
                y -> color = 0;
                z -> parent -> parent -> color = 1;
                z = z -> parent -> parent;
            }
            else {
                if (z == z -> parent -> left) {
                    z = z -> parent;
                    right_rotation(t, z);
                }
                z -> parent -> color = 0;
                z -> parent -> parent -> color = 1;
                left_rotation(t, z -> parent -> parent);
            }
        }
    }
    t -> root -> color = 0;
}

void insertion(rbtree *t, tree_node *z) {
    tree_node *y = t -> NIL;
    tree_node *temp = t -> root;

    while (temp != t -> NIL) {
        y = temp;
        if (z -> data < temp -> data) {
            temp = temp -> left;
        }
        else {
            temp = temp -> right;
        }
    }

    z -> parent = y;

    if (y == t -> NIL) {
        t -> root = z;
    }
    else if (z -> data < y -> data) {
        y -> left = z;
    }
    else {
        y -> right = z;
    }

    z -> left = t -> NIL;
    z -> right = t -> NIL;

    insertion_fixup(t, z);  
}

void inorder(rbtree *t, tree_node *n) {
    if (n != t -> NIL) {
        inorder(t, n -> left);
        printf("%d \n", n -> data);
        inorder(t, n -> right);
    }
}

int main() {
    rbtree *t = new_rbtree();

    tree_node *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l, *m;

    a = new_tree_node(10);
    b = new_tree_node(20);
    c = new_tree_node(30);
    d = new_tree_node(100);
    e = new_tree_node(90);
    f = new_tree_node(40);
    g = new_tree_node(50);
    h = new_tree_node(60);
    i = new_tree_node(70);
    j = new_tree_node(80);
    k = new_tree_node(150);
    l = new_tree_node(110);
    m = new_tree_node(120);

    insertion(t, a);
    insertion(t, b);
    insertion(t, c);
    insertion(t, d);
    insertion(t, e);
    insertion(t, f);
    insertion(t, g);
    insertion(t, h);
    insertion(t, i);
    insertion(t, j);
    insertion(t, k);
    insertion(t, l);
    insertion(t, m);

    inorder(t, t -> root);

    return 0;
}
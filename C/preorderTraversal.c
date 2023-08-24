// From: https://www.hackerrank.com/challenges/tree-preorder-traversal/problem

#include <stdlib.h>
#include <stdio.h>

struct node {

    int data;
    struct node *left;
    struct node *right;

};


void preOrder( struct node *root) {
    if (root != NULL)
    {
        printf("%d ", root->data);
    }
    if (root->left != NULL)
    {
        preOrder(root->left);
    }
    if (root->right != NULL)
    {
        preOrder(root->right);
    }
}

#include <stdio.h>
#include <stdlib.h>
typedef struct
{ // unanimous structure- structures with no name, starts with typedef
    int node;
    struct TREE1 *left;
    struct TREE1 *right;
} TREE1;

struct Tree
{
    int data;
    struct TREE2 *left;
    struct TREE2 *right;
};
typedef struct Tree TREE2; // aliasing
TREE1 *insert_into_bst(TREE1 *root, int data)
{
    TREE1 *newnode;
    newnode = (TREE1 *)malloc(sizeof(TREE1));
    if (newnode == NULL)
    {
        printf("memory allocation failed");
        return NULL;
    }
    newnode->node = data;
    newnode->left = NULL;
    newnode->right = NULL;
    if (root == NULL)
    {
        return newnode;
    }

    TREE1 *parent, *curr;
    parent = NULL;
    curr = root;
    while (curr != NULL)
    {
        parent = curr;
        if (newnode->node < curr->node)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
    if (newnode->node < parent->node)
    {
        parent->left = newnode;
    }
    else
    {
        parent->right = newnode;
    }
    return root;
}

TREE1 *delete_from_bst(TREE1 *root, int data)
{
    if (root == NULL)
    {
        printf("tree is empty");
        return root;
    }
    TREE1 *cur, *parent, *succ, *p;
    cur = root;
    parent = NULL;
    while (cur != NULL && cur->node != data)
    {
        parent = cur;
        if (data < cur->node)
        {
            cur = cur->left;
        }
        else
        {
            cur = cur->right;
        }
    }
    if (cur == NULL)
    {
        printf("no such data present in the tree\n");
        return root;
    }
    if (cur->left == NULL)
    {
        p = cur->right;
    }
    else if (cur->right == NULL)
    {
        p = cur->left;
    }
    else
    {
        succ = cur->right;
        while (succ->left != NULL)
        {
            succ = succ->left;
        }
        succ->left = cur->left;
        p = cur->right;
    }
    if (parent == NULL)
    {
        // root deletion
        free(cur);
        printf("root deleted");
        return p;
    }

    if (cur== parent->left)
    {
        parent->left = p;
    }
    else
    {
        parent->right = p;
    }
    free(cur);
    printf("deletion successfull");
    return root;
}
void inorder(TREE1 *root)
{ // left root right
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d\t", root->node);
        inorder(root->right);
    }
}
void preorder(TREE1 *root)
{ // root left right

    if (root != NULL)
    {
        printf("%d\t", root->node);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(TREE1 *root)
{ // right root left
    if (root != NULL)
    {
        postorder(root->right);
        printf("%d\t", root->node);
        postorder(root->left);
    }
}

int main()
{
    TREE1 *root = NULL;
    root = insert_into_bst(root, 10);
    root = insert_into_bst(root, 7);
    root = insert_into_bst(root, 15);
    root = delete_from_bst(root,10);
    printf("\n");
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
}
//lazy propagaton in segment tree- persistent
//to implemet the same in bst
//maintain a array with 1/0 mapped to each number of tree
//only when asked to print the tree actions are taken
//not good to have lazy propagation on bst 
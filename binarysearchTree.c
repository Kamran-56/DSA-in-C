#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *right;
    struct node *left;
};

struct node *createNode(int data)
{
    struct node *p;                  // Creating a node pointer
    p = malloc(sizeof(struct node)); // Allocating memory in the heap
    p->data = data;                  // Setting the data
    p->left = NULL;                  // Setting the left and right children to null
    p->right = NULL;
    return p; // Finally returning the created node
}

// A binary Search Tree is a binary tree where the value of any node is greater than the left subtree and less than the right subtree.
struct node *search(struct node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (key == root->data)
    {
        return root;
    }
    else if (key < root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}

/*
Traversal in binary tree

1.preorder traversal:
from root visit left subtree then right subtree

2.postorder traversal:
visit left subtree then right subtree and at last visit root

3.In order traversal:
left subtree then root then right subtree

*/

// Pre-order traversal: Root -> Left Subtree -> Right Subtree
void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Post-order traversal: Left Subtree -> Right Subtree -> Root
void postOrder(struct node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

// In-order traversal: Left Subtree -> Root -> Right Subtree
void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main()
{
    struct node *temp = createNode(6);
    struct node *temp1 = createNode(2);
    struct node *temp2 = createNode(8);
    struct node *temp3 = createNode(1);
    struct node *temp4 = createNode(4);

    temp->left = temp1;
    temp->right = temp2;
    temp1->left = temp3;
    temp1->right = temp4;

    /*
               6
              / \
             2   8
            / \
           1   4
   */

    printf("Pre-order Traversal: ");
    preOrder(temp);
    printf("\n");

    printf("Post-order Traversal: ");
    postOrder(temp);
    printf("\n");

    printf("In-order Traversal: ");
    inOrder(temp);
    printf("\n");

    struct node *n = search(temp, 6);
    if (n != NULL)
    {
        printf("Found: %d", n->data);
    }
    else
    {
        printf("Element not found");
    }

    return 0;
}

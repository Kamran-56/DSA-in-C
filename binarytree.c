#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* right;
    struct node* left;
};

struct node* createNode(int data) {
    struct node *p; // Creating a node pointer
    p = malloc(sizeof(struct node)); // Allocating memory in the heap
    p->data = data; // Setting the data
    p->left = NULL; // Setting the left and right children to null
    p->right = NULL;
    return p; // Finally returning the created node
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
void preOrder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Post-order traversal: Left Subtree -> Right Subtree -> Root
void postOrder(struct node *root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

// In-order traversal: Left Subtree -> Root -> Right Subtree
void inOrder(struct node *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main() {
    struct node* temp = createNode(2);
    struct node* temp1 = createNode(6);
    struct node* temp2 = createNode(8);
    struct node* temp3 = createNode(1);
    struct node* temp4 = createNode(9);

    temp->left = temp1;
    temp->right = temp2;
    temp1->left = temp3;
    temp1->right = temp4;

    /*
                2
               / \
              6   8
             / \
            1   9
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

    return 0;
}

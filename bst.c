#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node *BSTNODE;

BSTNODE createNode(int item) {
    BSTNODE temp = (BSTNODE)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

BSTNODE insertNode(BSTNODE root, int item) {
    if(root == NULL)
        return createNode(item);

    if(item < root->data)
        root->left = insertNode(root->left, item);
    else
        root->right = insertNode(root->right, item);

    return root;
}

void inorder(BSTNODE root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    BSTNODE root = NULL;

    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);

    printf("Inorder Traversal:\n");
    inorder(root);

    return 0;
}

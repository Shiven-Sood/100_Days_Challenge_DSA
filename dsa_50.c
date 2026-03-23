#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int bst_search(struct Node* root, int key) {
    while (root != NULL) {
        if (root->val == key)
            return 1;
        else if (key < root->val)
            root = root->left;
        else
            root = root->right;
    }
    return 0;
}

int main() {
    struct Node* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);

    printf("%d\n", bst_search(root, 6));
    printf("%d\n", bst_search(root, 7));

    return 0;
}
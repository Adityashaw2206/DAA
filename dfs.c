#include <stdio.h>

#include <stdlib.h>

struct Node {

int data;

struct Node* left;

struct Node* right;

};

struct Node* newNode(int data) {

struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

temp->data = data;

temp->left = temp->right = NULL;

return temp;

}

void dfs(struct Node* root) {

if(root == NULL)

return;

printf("%d ",root->data);

dfs(root -> left ) ;

dfs(root ->right);

}

int main() {

struct Node* root = NULL;

root = newNode(1);

root->left = newNode(8);

root->right = newNode(7);

root->left->left = newNode(4);

root->left->right = newNode (2);

printf("DFS:");

dfs(root);

return 0;

}
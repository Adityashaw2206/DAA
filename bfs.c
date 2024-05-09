#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node* left;
struct Node *right;
};

struct Node *newNode(int data) {

    struct Node *temp =(struct Node*)malloc(sizeof(struct Node));
    temp->data =data;
    temp->left= temp->right = NULL;
    return temp;
}
void bfs(struct Node* root){
    if(root == NULL)
        return;
    struct Queue{
        struct Node *node;
        struct Queue* next;
    };
    struct Queue *front= NULL, *rear=NULL;
    struct Queue *newNode=(struct Queue*)malloc(sizeof(struct Queue));
    newNode->node =root;
    newNode->next = NULL;
    front=rear=newNode;

    while(front){
        struct Node *current =front ->node;
        printf("%d ", current ->data);

        if (current->left){
            newNode =(struct Queue*)malloc(sizeof(struct Queue));
            newNode->node =current -> left;
            newNode->next=NULL;
            rear-> next=newNode;
            rear=newNode;
        }

        if(current->right){
            newNode =(struct Queue*)malloc(sizeof(struct Queue));
            newNode->node=current->right;
            newNode->next=NULL;
            rear-> next=newNode;
            rear=newNode;
        }

        struct Queue* temp =front;
        front =front->next;
        free(temp);
    }
}

int main(){

    struct Node *root= NULL;
    root= newNode(1);
    root->left =newNode(8);
    root->right = newNode(7);
    root->left->left = newNode(4);
    root->left->right = newNode(2);
    printf("BFS:");
    bfs(root);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newnode(int data)
{
    struct node *temp = (struct node*)malloc(sizeof (struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
void bfs(struct node *root)
{
    if(root == NULL)
        return;
    struct queue{
        struct node *node;
        struct queue *next;
    };
    struct queue *front = NULL,*rear = NULL;
    struct queue *newnode = (struct queue *)malloc(sizeof(struct queue));
    newnode->node = root;
    newnode->next = NULL;
    front = rear = newnode;
    while(front)
    {
        struct node *curr = front->node;
        printf("%d ",curr->data);
        if(curr->left)
        {
            newnode = (struct queue *)malloc(sizeof(struct queue));
            newnode->node = curr->left;
            newnode->next = NULL;
            rear->next = newnode;
            rear = newnode;

        }
        if(curr->right)
        {
            newnode = (struct queue *)malloc(sizeof(struct queue));
            newnode->node = curr->right;
            newnode->next = NULL;
            rear->next = newnode;
            rear = newnode;
        }
        struct queue *temp = front;
        front = front->next ;
        free(temp);
    }
}
int main()
{
    struct node *root = NULL;
    root= newNode(1);
    root->left =newNode(8);
    root->right = newNode(7);
    root->left->left = newNode(4);
    root->left->right = newNode(2);
    printf("BFS:");
    bfs(root);
    return 0;
}
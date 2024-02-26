#include<stdio.h>
#include<stdlib.h>

typedef struct bst {
    int data;
    struct bst *rchild, *lchild;
} node;

node* getnode();
void insert(node*, node*);
void inorder(node*);
void preorder(node*);
void postorder(node*);
int search(node*, int);

int n;

node* getnode() {
    node *temp;
    temp = (node*)malloc(sizeof(node));
    temp->lchild = NULL;
    temp->rchild = NULL;
    return temp;
}

void main() {
    int ch;
    int key, ans = 1;
    node *newnode, *root, *temp, *parent;
    root = NULL;
    while (1) {
        printf("1.create 2.search 3.traverse 4.exit\n");
        printf("enter choice\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                while (ans == 1) {
                    newnode = getnode();
                    printf("enter the element\n");
                    scanf("%d", &newnode->data);
                    if (root == NULL)
                        root = newnode;
                    else
                        insert(root, newnode);
                    printf("want to continue[0/1]\n");
                    scanf("%d", &ans);
                }
                break;
            case 2:
                printf("enter the element to search\n");
                scanf("%d", &key);
                search(root, key);
                if (n == 1)
                    printf("search successful\n");
                else
                    printf("search unsuccessful\n");
                break;
            case 3:
                if (root == NULL)
                    printf("tree is empty\n");
                else {
                    printf("\n inorder traversal\n");
                    inorder(root);
                    printf("\n postorder traversal\n");
                    postorder(root);
                    printf("\n preorder traversal\n");
                    preorder(root);
                }
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("wrong choice\n");
                break;
        }
    }
}

void insert(node *root, node *newnode) {
    if (root->data < newnode->data) {
        if (root->rchild == NULL)
            root->rchild = newnode;
        else
            insert(root->rchild, newnode);
    } else {
        if (root->lchild == NULL)
            root->lchild = newnode;
        else
            insert(root->lchild, newnode);
    }
}

void inorder(node *ptr) {
    if (ptr != NULL) {
        inorder(ptr->lchild);
        printf("%d\t", ptr->data);
        inorder(ptr->rchild);
    }
}

void preorder(node *ptr) {
    if (ptr != NULL) {
        printf("%d\t", ptr->data);
        preorder(ptr->lchild);
        preorder(ptr->rchild);
    }
}

void postorder(node *ptr) {
    if (ptr != NULL) {
        postorder(ptr->lchild);
        postorder(ptr->rchild);
        printf("%d\t", ptr->data);
    }
}

int search(node *root, int key) {
    node *temp;
    temp = root;
    if (root != NULL) {
        if (temp->data == key)
            n = 1;
        else if (key > temp->data)
            search(temp->rchild, key);
        else
            search(temp->lchild, key);
    } else
        n = 0;
    return n;
}

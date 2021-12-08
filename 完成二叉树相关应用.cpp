#include <string.h>

#include <iostream>
using namespace std;

typedef char DataType;

//二叉树结点定义
struct node {
    DataType data;                 //存放结点数据
    struct node *lchild, *rchild;  //左右孩子指针
};
typedef struct node BiTree;
typedef struct node *ptree;

//函数可直接使用，功能：输出结点数据
void print(DataType d) { cout << d << " "; }

struct node *create_newnode(char info) {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = info;
    node->lchild = NULL;
    node->rchild = NULL;
    return node;
}

/*
函数名：createBiTree
函数功能：创建二叉树，并返回二叉树的根结点指针
参数：无
返回值：二叉树的根结点指针
*/
BiTree *createBiTree(void) {
    //请在此处填写代码， 完成二叉树和创建，返回值是二叉树的根结点指针
    /********** Begin **********/

    char str[100] = {};
    scanf("%s", str);
    BiTree *tree = create_newnode(str[0]);
    BiTree *parent[100];
    int right = 0, top = 0;
    parent[0] = tree;
    for (int i = 1; i < strlen(str); i++) {
        if (str[i] == '#') {
            right++;
        }
        if (right == 0) {
            struct node *node = create_newnode(str[i]);
            parent[top]->lchild = node;
            top++;
            parent[top] = node;
        }
        if (right > 0) {
            if (str[i] != '#') {
                struct node *node = create_newnode(str[i]);
                parent[top]->rchild = node;
                top++;
                parent[top] = node;
                right = 0;
            } else {
                if (right == 1 && parent[top]->rchild == NULL) {
                    continue;
                }
                if (right == 2) {
                    if (top > 0) {
                        top--;
                    }
                    while (parent[top]->rchild != NULL && top > 0) {
                        top--;
                    }
                    right = 1;
                }
            }
        }
    }

    return tree;
    /********** End *********/
}
/*
函数名：preOrder
函数功能：先根遍历二叉树
参数：二叉树根结点指针
返回值：无
*/

void right_children(BiTree *root) {
    if (root == NULL) return;
    printf("%c ", root->data);
    right_children(root->rchild);
}

void preOrder(BiTree *root, char ch) {
    if (root == NULL) return;
    if (root->data == ch) {
        right_children(root->rchild);
        return;
    } else {
        preOrder(root->lchild, ch);
        preOrder(root->rchild, ch);
    }
}

int main(void) {
    BiTree *T;
    T = createBiTree();  //调用创建二叉树功能，得到二叉树的根结点指针

    char ch;
    cin >> ch;        //输入某人的代号
    preOrder(T, ch);  //调用函数输出ch的所有兄弟姐妹

    return 1;
}

// void preOrder(BiTree *root) {
//     if (root == NULL) return;
//     printf("%c ", root->data);
//     preOrder(root->lchild);
//     preOrder(root->rchild);
// }

// void inOrder(BiTree *root) {
//     if (root == NULL) return;
//     inOrder(root->lchild);
//     printf("%c ", root->data);
//     inOrder(root->rchild);
// }

// void postOrder(BiTree *root) {
//     if (root == NULL) return;
//     postOrder(root->lchild);
//     postOrder(root->rchild);
//     printf("%c ", root->data);
// }

// int main(void) {
//     BiTree *T;
//     T = createBiTree();

//     preOrder(T);
//     cout << endl;
//     inOrder(T);
//     cout << endl;
//     postOrder(T);

//     return 1;
// }
#include <string.h>

#include <iostream>
using namespace std;

typedef char DataType;

//二叉树数据结构
struct node {
    DataType info;                 //存放结点数据
    struct node *lchild, *rchild;  //指向左右孩子的指针
};

typedef struct node *BiTree;

struct node *create_newnode(char info) {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->info = info;
    node->lchild = NULL;
    node->rchild = NULL;
    return node;
}

/*创建二叉树
  函数名：createBiTree
  参数：无
  返回值：二叉树根结点指针
  */
BiTree createBiTree(void) {
    //请在此处填写代码， 完成二叉树和创建，返回值是二叉树的根结点指针
    /********** Begin **********/

    char str[100];
    scanf("%s", str);
    BiTree tree = create_newnode(str[0]), parent[100];
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

void visit(BiTree T) {
    //输出结点T的数据
    cout << T->info;
}

int count;
int countLeaf(BiTree root) {
    //请在此处填写代码， 计算二叉树中树叶的个数
    /********** Begin **********/
    if (root == NULL) return 0;
    if (root->lchild == NULL && root->rchild == NULL) {
        count++;
    }
    countLeaf(root->lchild);
    countLeaf(root->rchild);

    return count;
    /********** End **********/
}

void changeLR(BiTree root) {
    //请在此处填写代码， 完成二叉树左右子树互换
    /********** Begin **********/
    if (root == NULL) return;
    changeLR(root->lchild);
    changeLR(root->rchild);
    struct node *temp;
    temp = root->lchild;
    root->lchild = root->rchild;
    root->rchild = temp;
    /********** End **********/
}

void inOrder(BiTree root) {
    if (root == NULL) return;
    inOrder(root->lchild);
    visit(root);
    inOrder(root->rchild);
}

int countFullNode(BiTree root) {
    //请在此处填写代码，计算二叉树中满结点的个数
    /********** Begin **********/
    if (root == NULL) return 0;
    if (root->lchild != NULL && root->rchild != NULL) {
        count++;
    }
    countFullNode(root->lchild);
    countFullNode(root->rchild);

    return count;

    /*********** End-**********/
}


int main(void) {
    BiTree root = createBiTree();
    // inOrder(root);
    // cout << countLeaf(root);
    // changeLR(root);
    // count = 0;
    printf("%d", countFullNode(root));
    // inOrder(root);
}
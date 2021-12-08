#include <stdio.h>

typedef struct Node {
    int weight;
    struct Node *father, *left, *right;
} node;

void sort_seq(node *nodes[], int front, int rear) {
    int min;
    node *temp;
    for (int i = front; i < rear; i++) {
        min = i;
        for (int j = i; j < rear; j++) {
            if (nodes[min]->weight > nodes[j]->weight) {
                min = j;
            }
        }
        temp = nodes[min];
        nodes[min] = nodes[i];
        nodes[i] = temp;
    }
}

void init_nodes(node *nodes[], int weights[], int n) {
    for (int i = 0; i < 2 * n - 1; i++) {
        node *new_node = (node *)malloc(sizeof(node));
        new_node->weight = 0;
        nodes[i] = new_node;
    }
    for (int i = 0; i < n; i++) {
        nodes[i]->weight = weights[i];
    }
}

void encoding(node *root) {
    node *father = root, *child;
    int encoding[10] = {};
    int count = 0;
    while (father) {
        child = father;
        father = child->father;
        if (father && father->left == child) {
            encoding[count] = 0;
            count++;
        }
        if (father && father->right == child) {
            // printf("1");
            encoding[count] = 1;
            count++;
        }
    }

    char temp;
    for (int i = 0; i < (count + 1) / 2; i++) {
        temp = encoding[i];
        encoding[i] = encoding[count - i];
        encoding[count - i] = temp;
    }

    printf("%d ", root->weight);
    for (int i = 1; i < count + 1; i++) {
        printf("%d", encoding[i]);
    }
    printf("\n");
}

node *Huffman(int weights[], int n) {
    node *nodes[2 * n - 1];
    int front = 0, rear = n;
    init_nodes(nodes, weights, n);
    while (rear < 2 * n - 1) {
        sort_seq(nodes, front, rear);
        nodes[rear]->weight = nodes[front]->weight + nodes[front + 1]->weight;
        nodes[rear]->left = nodes[front];
        nodes[rear]->right = nodes[front + 1];
        nodes[front]->father = nodes[rear];
        nodes[front + 1]->father = nodes[rear];
        front += 2;
        rear += 1;
    }
    return nodes[2 * n - 2];
}

void preOrder(node *root) {
    if (root->left == NULL && root->right == NULL) {
        encoding(root);
        return;
    }
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);
    int weights[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }
    node *root = Huffman(weights, n);
    preOrder(root);

    return 0;
}

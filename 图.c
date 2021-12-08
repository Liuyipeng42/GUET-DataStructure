#include <stdio.h>
#include <stdlib.h>
#define N 6
//邻接矩阵数据结构
typedef struct {
    int vcount;  //顶点数
    int ecount;
    int type;        // 0 无向图，1 有向图
    char vexs[N];    // 顶点信息
    int arcs[N][N];  //关系矩阵
} GraphMatrix;

//邻接表数据结构
struct EdgeNode {               //边表中的结点
    int endvex;                 //相邻顶点在顶点表中下标
    int weight;                 //边的权
    struct EdgeNode *nextedge;  //链字段
};
typedef struct EdgeNode *EdgeList;

typedef struct {
    char vertex;  //记录顶点信息
    int degree;   //用于记录顶点的入度，在拓扑排序时需使用
    int mark;
    EdgeList edgelist;  //指向边表的指针
} VexNode;

typedef struct {
    VexNode vexs[N];  // N个顶点
    int type;         // 0 无向图，1 有向图
    int vcount;       //顶点数
} GraphList;

/*完成图初始化
 */
void printGraph(GraphMatrix *G) {  //本函数输出图的邻接矩阵
    int i, j;
    for (i = 0; i < G->vcount; i++) {
        //  printf("%c ",G->vexs[i]);
        for (j = 0; j < G->vcount; j++) printf("%d ", G->arcs[i][j]);
        printf("\n");
    }
}

/*完成图初始化-邻接矩阵
 */
GraphMatrix *initGraphMatrix() {
    /*第一行输入图的类型、图的顶点数和边数，第二行输入各条边的两顶点的编号，按顶点编号从小到大的顺序输入。
  输出邻接矩阵，不需要考虑输入的数字非法情况，不输入顶点的信息*/
    GraphMatrix *matrix = (GraphMatrix *)malloc(sizeof(GraphMatrix));
    scanf("%d %d %d", &matrix->type, &matrix->vcount, &matrix->ecount);
    int node_1, node_2;
    if (matrix->type == 0) {
        for (int i = 0; i < matrix->ecount; i++) {
            scanf("%d %d", &node_1, &node_2);
            matrix->arcs[node_1][node_2] = 1;
            matrix->arcs[node_2][node_1] = 1;
            matrix->vexs[node_1] = node_1;
            matrix->vexs[node_2] = node_2;
        }
    }
    return matrix;
}
/*完成图初始化-邻接表,并完成输出图的邻接表函数
 */
void insert_node(VexNode *link, int node, int weight) {
    struct EdgeNode *new_node = (struct EdgeNode *)malloc(sizeof(VexNode));
    new_node->endvex = node;
    new_node->weight = weight;
    new_node->nextedge = link->edgelist;
    link->edgelist = new_node;
}

GraphList *initGraphList() {
    /*第一行输入图的类型、图的顶点数和边数，第二行输入各条边的两顶点的编号，按顶点编号从小到大的顺序输入。输出邻接表。不需考虑输入的数字非法情况，输入顶点的信息*/
    GraphList *G = (GraphList *)malloc(sizeof(GraphList));
    int edge_num;
    scanf("%d %d %d", &G->type, &G->vcount, &edge_num);
    int node_1, node_2;
    if (G->type) {
        for (int i = 0; i < edge_num; i++) {
            scanf("%d %d", &node_1, &node_2);
            (&G->vexs[node_1])->vertex = node_1;
            (&G->vexs[node_2])->vertex = node_2;
            insert_node(&G->vexs[node_1], node_2, 0);
            (&G->vexs[node_2])->degree++;
            (&G->vexs[node_1])->mark = 0;
        }
    } else {
        int weight = 0;
        for (int i = 0; i < edge_num; i++) {
            scanf("%d %d %d", &node_1, &node_2, &weight);
            // scanf("%d %d", &node_1, &node_2);
            (&G->vexs[node_1])->vertex = node_1;
            (&G->vexs[node_2])->vertex = node_2;
            insert_node(&G->vexs[node_1], node_2, weight);
            insert_node(&G->vexs[node_2], node_1, weight);
        }
    }

    return G;
}

void printList(VexNode *link) {
    /*在此处完成任务，输出head为表头链表中的数据，每输出一个数据换一行*/
    struct EdgeNode *end = link->edgelist;
    printf("%d->", link->vertex);
    int first = 1;
    while (end) {
        if (first) {
            printf("%d", end->endvex);
            first = 0;
        } else {
            printf("->%d", end->endvex);
        }

        end = end->nextedge;
    }
}

void printGraphLit(GraphList *G) {
    /*输出邻接表，输出格式：顶点->邻接顶点编号->...*/
    for (int i = 0; i < G->vcount; i++) {
        printList(&G->vexs[i]);
        printf("\n");
    }
}

/*完成图的广度遍历（周游），可根据需要添加自定义函数+
 */
int check(GraphList *G) {
    for (int i = 0; i < G->vcount; i++) {
        if ((&G->vexs[i])->mark == 0) {
            return 0;
        }
    }
    return 1;
}

void BFS_list(GraphList *G) {
    VexNode *queue[15];
    int front = 0, rear = 0;
    queue[rear] = &G->vexs[0];
    queue[0]->mark = 1;
    rear++;
    int all_scaned = 0;
    while (all_scaned == 0) {
        struct EdgeNode *end = queue[front]->edgelist;
        while (end) {
            if ((&G->vexs[end->endvex])->mark == 0) {
                queue[rear] = &G->vexs[end->endvex];
                queue[rear]->mark = 1;
                rear++;
            }
            end = end->nextedge;
        }
        all_scaned = check(G);
        printf("%d ", queue[front]->vertex);
        front++;
    }
    for (int i = front; i < rear; i++) {
        printf("%d ", queue[i]->vertex);
    }
}

/*完成图的深度遍历（周游），可根据需要添加自定义函数
 */
struct EdgeNode *first_adjacent(GraphList *G, VexNode *node) {
    return node->edgelist;
}

struct EdgeNode *next_adjacent(GraphList *G, struct EdgeNode *node) {
    if (node) {
        return node->nextedge;
    }
    return NULL;
}

void DFS(GraphList *G, VexNode v) {
    struct EdgeNode *v1;
    (&G->vexs[(&v)->vertex])->mark = 1;
    printf("%d ", (&v)->vertex);
    for (v1 = first_adjacent(G, &v); v1 != NULL; v1 = next_adjacent(G, v1)) {
        if ((&G->vexs[v1->endvex])->mark == 0) {
            DFS(G, G->vexs[v1->endvex]);
        }
    }
}

void DFS_list(GraphList *G) { DFS(G, G->vexs[0]); }

void del_node_edge(GraphList *G, VexNode *del_node) {
    (&G->vexs[del_node->vertex])->mark == 1;
    struct EdgeNode *end = del_node->edgelist;
    while (end) {
        (&G->vexs[end->endvex])->degree--;
        end = end->nextedge;
    }
}

void zero_degree(GraphList *G) {
    for (int i = 0; i < G->vcount; i++) {
        if ((&G->vexs[i])->degree == 0 && (&G->vexs[i])->mark == 0) {
            (&G->vexs[i])->mark = 1;
            del_node_edge(G, &G->vexs[i]);
            printf("%d ", (&G->vexs[i])->vertex);
            return;
        }
    }
    return NULL;
}

/*生成图的拓扑排序，可根据需要添加自定义函数
 */
void Top_list(GraphList *G) {
    for (int i = 0; i < G->vcount; i++) {
        zero_degree(G);
    }
}

void get_shortest_edge(GraphList *G, int shortest_edge[]) {
    int first = 1;
    shortest_edge[0] = 0;
    shortest_edge[1] = (&G->vexs[0])->edgelist->endvex;
    shortest_edge[2] = (&G->vexs[0])->edgelist->weight;

    for (int i = 0; i < G->vcount; i++) {
        if ((&G->vexs[i])->mark == 1) {
            struct EdgeNode *end = (&G->vexs[i])->edgelist;
            while (end) {
                if (end->weight < shortest_edge[2] &&
                    (&G->vexs[end->endvex])->mark == 0) {
                    shortest_edge[0] = (&G->vexs[i])->vertex;
                    shortest_edge[1] = end->endvex;
                    shortest_edge[2] = end->weight;
                }
                end = end->nextedge;
            }
        }
    }
    (&G->vexs[shortest_edge[1]])->mark = 1;
}

void Prim_list(GraphList *G) {
    int matrix[G->vcount][G->vcount], shortest_edge[3];
    for (int i = 0; i < G->vcount; i++) {
        for (int j = 0; j < G->vcount; j++) {
            matrix[i][j] = 0;
        }
    }
    (&G->vexs[0])->mark = 1;
    while (check(G) == 0) {
        get_shortest_edge(G, shortest_edge);
        matrix[shortest_edge[0]][shortest_edge[1]] = 1;
    }

    for (int i = 0; i < G->vcount; i++) {
        for (int j = 0; j < G->vcount; j++) {
            if (matrix[i][j]) {
                printf("%d %d\n", i, j);
            }
        }
    }
}

int main(void) {
    GraphList *G=initGraphList( );
    Prim_list(G);
}
//0 6 10 0 1 10 1 2 5 2 3 9 1 3 7 1 5 11 3 5 14 0 5 21 0 4 19 3 4 18 4 5 33
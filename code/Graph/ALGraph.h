#define MaxVertexNum 100
typedef char VertexType;

typedef struct ArcNode {
    int adjvex;
    struct ArcNode *nextarc;
}ArcNode;

typedef struct VNode{
    VertexType data;
    ArcNode *firstarc;
}VNode,AdjList[MaxVertexNum];

typedef struct{
    AdjList vertices;
    int vexnum,arcnum;
}ALGraph;

//返回首个邻接顶点下标
int FirstNeighborhood(ALGraph G, VertexType x);
//返回下一个邻接顶点下标
int NextNeighborhood(ALGraph G,VertexType x);
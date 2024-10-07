#define MaxVertexNum 100
typedef int VertexType; 
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
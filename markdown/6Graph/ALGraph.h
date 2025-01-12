#define MaxVertexNum 100
typedef int VertexType; 

/** @brief 边结点
 *  @param adjvex 该弧指向的顶点的位置 */
typedef struct ArcNode {
    int adjvex;
    struct ArcNode *nextarc;
}ArcNode;

/// @brief 顶点结点
typedef struct VNode{
    VertexType data;
    ArcNode *firstarc;
}VNode,AdjList[MaxVertexNum];

typedef struct{
    AdjList vertices;
    int vexnum,arcnum;
}ALGraph;
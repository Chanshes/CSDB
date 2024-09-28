#include <stdio.h>
#include "ALGraph.h"

void DFS_Traverse(ALGraph G){
    int Stack[MaxVertexNum];
    int vex,top=-1;
    bool visited[MaxVertexNum];
    for(int i=0;i<G.vexnum;i++)
        visited[i]=false;
    for(int i=0;i<G.vexnum;i++){
        vex = i;
        if(!visited[i]){
            while(top!=-1||vex!=-1){
                while(vex!=-1){
                    if(!visited[vex]){
                        Stack[++top]=vex;
                        visited[vex]=true;
                        vex=FirstNeighborhood(G,G.vertices[vex].data);
                    }
                    else
                        vex=-1;
                }
                vex=NextNeighborhood(G,G.vertices[Stack[top--]].data);
            }
        }
    }
}

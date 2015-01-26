#include <iostream>
#include <stdlib.h>
#define M 20
#define Max 20

using namespace std;

typedef struct{
    int Begin;
    int End;
    int weight;
}edge;

typedef struct{
    int adj;
    int weight;
}AdjMatrix[Max][Max];

typedef struct{
    AdjMatrix arc;
    int vexnum,arcnum;
}Mgraph;

void CreateGraph(Mgraph *G){    //create a graph
    cout << "Please input the graph' edges and vertexs:";
    cin >> G->arcnum >> G->vexnum;

    for(int i=1;i<=G->vexnum;i++){  //initial the adjacent matrix
        for(int j=1;j<=G->vexnum;j++)
            G->arc[i][j].adj = G->arc[i][j].adj = 0;
    }

    int m,n;
    for(int i=1;i<=G->arcnum;i++){
        cout << "Input the two vertexs on a edge:";
        cin >> m >> n;

        while(m<1 || m>G->vexnum || n<1 || n>G->vexnum ){
            cout << "Input is over the scope" << endl;
            cout << "Input the two vertexs of a edge again:";
            cin >> m >> n;
        }

        G->arc[m][n].adj = G->arc[n][m].adj = 1;

        cout << "Input the weight of this edge:";
        cin >> G->arc[n][m].weight;
        G->arc[m][n].weight = G->arc[n][m].weight;
    }

    cout << "The adjacent matrix is:" << endl;
    for(int i=1;i<=G->vexnum;i++){
        for(int j=1;j<=G->vexnum;j++)
            cout << G->arc[i][j].adj;
        cout << endl;
    }

    /*
    cout << "weight";
    for(int i=1;i<=G->vexnum;i++){
        for(int j=1;j<=G->vexnum;j++)
            cout << G->arc[i][j].weight;
        cout << endl;
    }*/
}

//swap the weight Begin and End
void Swapw(edge *edges,int i,int j){
    int temp;
    temp = edges[i].Begin;
    edges[i].Begin = edges[j].Begin;
    edges[j].Begin = temp;

    temp = edges[i].End;
    edges[i].End = edges[j].End;
    edges[j].End = temp;

    temp = edges[i].weight;
    edges[i].weight = edges[j].weight;
    edges[j].weight = temp;
}

//sort the weight
void Sort(edge edges[],Mgraph *G){
   for(int i=1;i<=G->vexnum;i++){
        for(int j=i+1;j<=G->vexnum;j++){
            if(edges[i].weight > edges[j].weight)
                Swapw(edges,i,j);
        }
   }
}

int Find(int *parent,int f){    //find the end
    while(parent[f]>0){
        f = parent[f];
    }
    return f;
}

void MiniSpanTree(Mgraph *G){
    edge edges[M];
    int parent[M];

    int k=1;
    //get a edge
    for(int i=1;i<=G->vexnum;i++){
        for(int j=i+1;j<=G->vexnum;j++){
            if(G->arc[i][j].adj == 1){
                edges[k].Begin = i;
                edges[k].End = j;
                edges[k].weight = G->arc[i][j].weight;
                k++;
            }
        }
    }

    Sort(edges,G);
    for(int i=1;i<=G->arcnum;i++){
        parent[i] = 0;
    }

    cout << "The minimum spanning tree is:";
    int m,n;
    for(int i=1;i<=G->arcnum;i++){
        n = Find(parent,edges[i].Begin);
        m = Find(parent,edges[i].End);

        if(n != m){
            parent[n] = m;
            cout << '(' << edges[i].Begin<<','<<edges[i].End << ')'<<','<< edges[i].weight << "  -_-  ";
        }
    }
}

int main()
{
    Mgraph *G;
    G = new Mgraph;

    CreateGraph(G);
    MiniSpanTree(G);
    return 0;
}

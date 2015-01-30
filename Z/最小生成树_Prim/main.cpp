#include <iostream>
#include <string.h>
#define VER 100     //there are 100 vertexs at most;
#define MAX 10000   //the edges weight <= 10000

using namespace std;

int adj[VER][VER],low[VER],visited[VER];
int ver,edge;

void prim()
{
    int pos,min0,cur_pos[VER];
    memset(visited,0,sizeof(visited));
    visited[1]=1;pos=1;

    for(int i=1;i<=ver;i++)
        if(i!=pos){
            low[i]=adj[pos][i];
            cur_pos[i] = pos;
        }

    for(int i=1;i<ver;i++){       //find the minimum weight and record the position
        min0=MAX;
        for(int j=1;j<=ver;j++){
            if(visited[j]==0&&min0>low[j]){
                min0=low[j];
                pos=j;
            }
        }
        cout << '(' << pos << ',' << cur_pos[pos] << ')' << min0 << endl;

        visited[pos]=1;

        for(int j=1;j<=ver;j++){  //update the weight
            if(visited[j]==0&&low[j]>adj[pos][j]){
                low[j]=adj[pos][j];
                cur_pos[j] = pos;
            }
        }
    }
}

int main()
{
    cout << "Please input the number of vertexs:";
    cin >> ver;
    cout << "Please input the number of edges:";
    cin >> edge;

    for(int i = 1;i<=ver;i++){
        for(int j=1;j<=ver;j++){
            adj[i][j] = MAX;
        }
    }

    int m,n,weight;
    for(int i = 1;i<=edge;i++){
        cout << "Input the two vertexs on a edge:";
        cin >> m >> n;
        cout << "Input the weight of this edge:";
        cin >> weight;

        adj[m][n] = adj[n][m] = weight;
    }
    prim();
    return 0;
}

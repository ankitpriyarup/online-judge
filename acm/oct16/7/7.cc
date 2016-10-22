#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

struct par {
    int x, y;
    char c;
} temp;

void order(par &p){
    if(p.x > p.y)
        swap(p.x, p.y);
}


bool visited[105][105];
queue<par> bfs;
vector<par> adj[105];
int cases, n, m;

void expand(par state){
    int one = state.x, two = state.y;
    for(int i=0; i<adj[one].size(); i++){
        for(int e=0; e<adj[two].size(); e++){
            if(adj[one][i].c == adj[two][e].c){
                temp.x = adj[one][i].x;
                temp.y = adj[two][e].x;
                order(temp);
                if(!visited[temp.x][temp.y]){
                    visited[temp.x][temp.y] = true;
                    bfs.push(temp);
                }
            }
        }
    }
}

void dobfs(){
    for(int i=0; i<n; i++){
        temp.x = temp.y = i;
        bfs.push(temp);
        visited[i][i] = true;
        for(int e=0; e<adj[i].size(); e++){
            temp.x = i;
            temp.y = adj[i][e].x;
            order(temp);
            if(!visited[temp.x][temp.y]){
                visited[temp.x][temp.y]=true;
                bfs.push(temp);
            }
        }
    }
    while(bfs.size() > 0){
        expand(bfs.front());
        bfs.pop();
    }
}


int main(){
    scanf("%d",&cases);
    while(cases--){
        scanf("%d%d",&n,&m);

        for(int i=0; i<=n; i++){
            for(int e=0; e<=n; e++){
                visited[i][e] = false;
            }
            adj[i].clear();
        }

        for(int i=1; i<=m; i++){
            int a, b;
            char c;
            scanf("%d%d",&a,&b);
            cin>>c;
            temp.x = b;
            temp.c = c;
            adj[a].push_back(temp);
            temp.x=a;
            adj[b].push_back(temp);
        }
        dobfs();
        for(int i=0; i<n; i++){
            if(visited[0][i]){
                printf("%d ",i);
            }
        }
        printf("\n");
    }
    return 0;
}

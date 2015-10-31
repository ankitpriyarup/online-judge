#include <iostream>
#include <queue>
#include <climits>
#include <cstdio>
#include <vector>
#include <map>

#define MAX_N 2000

using namespace std;


//vector<map<int, int> > graph;
//vector<map<int, int> > residual;

vector<vector<pair<int, int> > > graph;
vector<vector<pair<int, int> > > residual;

// int graph[MAX_N + 5][MAX_N + 5];
// int residual[MAX_N + 5][MAX_N + 5];
bool visited[MAX_N + 5];
int  parent[MAX_N + 5];


bool bfs(int source, int sink, int n)
{
    for (int i = 0; i < n; ++i)
    {
        visited[i] = false;
        parent[i] = -1;
    }
    queue<int> q;
    visited[source] = true;
    parent[source] = -1;
    q.push(source);

    while (!q.empty())
    {
        int next = q.front();
        q.pop();

        if (next == sink)
            break;
   
        for (int i = 0; i < (int)residual[next].size(); ++i)
        {
            int node = residual[next][i].first;
            int weight = residual[next][i].second;

            if (!visited[node] && weight > 0)
            {
                parent[node] = next;
                q.push(node);
                visited[node] = true;
            }
        }
    }

    return visited[sink];
}

/*
void printGraph(int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            printf("%5d ", residual[i][j]);
        printf("\n");
    }
}
*/

int ford(int source, int sink, int n)
{
    residual.clear();
    for (int i = 0; i < n; ++i)
    {
       //residual.push_back(map<int, int>(graph[i]));
       residual.push_back(vector<pair<int, int> >(graph[i]));
    }
    // for (int i = 0; i < n; ++i)
    //     for (int j = 0; j < n; ++j)
    //        residual[i][j] = graph[i][j];

    //printGraph(n);
    int flow = 0;
    while (bfs(source, sink, n))
    {
        //for (int i = 0; i < n; ++i)
        //    cout << parent[i] << " ";
        //cout << endl;
        int cap = INT_MAX;
        int current = sink;
        while (current != source)
        {
            int p = parent[current];
            for (auto it = residual[p].begin(); it != residual[p].end(); it++) {
                if (it->first == current) {
                    cap = min(cap, it->second);
                    break;
                }
            }
            //cap = min(cap, residual[p][current]);
            current = p;

        }
         
        current = sink;
        while (current != source)
        {
            int p = parent[current];
            for (auto it = residual[p].begin(); it != residual[p].end(); ++it) {
                if (it->first == current) {
                    it->second -= cap;
                    break;
                }
            }
            //residual[p][current] -= cap;
            bool added = false;
            for (auto it = residual[current].begin(); it != residual[current].end(); ++it) {
                if (it->first == p) {
                    it->second += cap;
                    added = true;
                    break;
                }
            }
            if (!added) {
                residual[current].push_back(make_pair(p, cap));
            }
            //residual[current][p] += cap;
            current = p;
        }

        flow += cap;
    }

    return flow;
}

int main()
{
    int t;
   // scanf("%d", &t);
    cin >> t;

    while (t-- > 0)
    {
        graph.clear();
        residual.clear();

        int n, m;
        //scanf("%d %d", &n, &m);
        cin >> n >> m;

        /*for (int i = 0; i < n + m + 2; ++i)
            for (int j = 0; j < n + m + 2; ++j)
                graph[i][j] = 0;
        */

        for (int i = 0; i < n + m + 2; ++i)
        {
            graph.push_back(vector<pair<int, int> >());
        }

        for (int i = 0; i < n; ++i)
            //graph[n + m][i] = 1;
            graph[n + m].push_back(make_pair(i, 1));
        
        for (int i = 0; i < m; ++i)
            //graph[n + i][n + m + 1] = 1;
            graph[n + i].push_back(make_pair(n + m + 1, 1));

        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            for (int j = 0; j < x; ++j)
            {
                int y;
                cin >> y;
                //graph[i][n + y - 1] = 1;
                graph[i].push_back(make_pair(n + y - 1, 1));
            }
        }
        
        cout << ford(n + m, n + m + 1, n + m + 2) << endl;
        //printf("%d\n", ford(n + m, n + m + 1, n + m + 2));
    }
}

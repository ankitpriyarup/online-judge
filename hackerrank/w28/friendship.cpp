#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXN = 100005;

int comp_id[MAXN];
int comp_size[MAXN];

vector<int> graph[MAXN];

void dfs(int node) {
    for (int child : graph[node]) {
        if (comp_id[child] == -1) {
            comp_id[child] = comp_id[node];
            ++comp_size[comp_id[child]];
            dfs(child);
        }
    }
}

int main() {
    int queries;
    cin >> queries;
    
    int num_people, num_friendships;
    while (queries-- > 0) {
        cin >> num_people >> num_friendships;
        for (int i = 0; i < MAXN; ++i) {
            graph[i].clear();
        }
        
        int x, y;
        for (int i = 0; i < num_friendships; ++i) {
            cin >> x >> y;
            --x;
            --y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        
        memset(comp_id, -1, sizeof(comp_id));
        memset(comp_size, 0, sizeof(comp_size));
        int next_id = 0;

        for (int i = 0; i < num_people; ++i) {
            if (comp_id[i] == -1) {
                comp_id[i] = next_id;
                ++comp_size[comp_id[i]];
                dfs(i);
                ++next_id;
            }
        }
        
        sort(comp_size, comp_size + next_id);

        long long extra_edges = num_friendships;
        long long cur = 0;
        long long total = 0;

        for (int i = next_id - 1; i >= 0; --i) {
            extra_edges -= comp_size[i] - 1;

            for (int j = 1; j < comp_size[i]; ++j) {
                cur += 2LL * j;
                total += cur;
            }
        }
        
        total += cur * extra_edges;
        
        cout << total << '\n';
    }

    return 0;
}


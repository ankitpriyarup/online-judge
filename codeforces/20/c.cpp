#include <cstdio>
#include <queue>

using namespace std;

int N, M;
//int edges[100010][3];
vector<pair<int, int> > edges[100010];
int previous[100010];
bool seen[100010];

struct node {
    int n, prev;
    long long dist;
    node(int n, long long dist, int prev) : n(n), dist(dist), prev(prev) {};
};

bool operator<(node n1, node n2) {
    return n1.dist > n2.dist;
}

int main() {
    scanf("%d %d", &N, &M);
    int a, b, w;
    for(int i=0;i<M;i++) {
        scanf("%d %d %d", &a, &b, &w);
        edges[a - 1].push_back(make_pair(b - 1, w));
        edges[b - 1].push_back(make_pair(a - 1, w));
        previous[a - 1] = -1;
        previous[b - 1] = -1;
    }

    priority_queue<node> pq;
    pq.push(node(0, 0LL, -1));
    while(!pq.empty()) {
        node cur = pq.top();
        pq.pop();
        if(seen[cur.n]) {
            continue;
        }

        seen[cur.n] = true;
        previous[cur.n] = cur.prev;

        if(cur.n == N - 1) {
            break;
        }

        for(auto it = edges[cur.n].begin(); it != edges[cur.n].end(); it++) {
            pq.push(node(it->first, it->second + cur.dist, cur.n));
        }
    }
    vector<int> ans;
    if(!seen[N - 1]) {
        printf("-1\n");
    } else {
        int cur = N - 1;
        while(cur > 0) {
            ans.push_back(cur + 1);
            cur = previous[cur];
        }
        printf("1");
        for(vector<int>::reverse_iterator it = ans.rbegin(); it != ans.rend(); it++) {
            printf(" %d", *it);
        }
        printf("\n");
    }
    return 0;
}

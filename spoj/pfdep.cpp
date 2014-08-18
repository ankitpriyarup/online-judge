#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <functional>
 
using namespace std;
int N, M; 
vector<set<int> > edges;
bool seen[101] = {0};
vector<int> ans;

int main() {
    for(int i=0;i<=100;i++) {
        set<int> temp;
        edges.push_back(temp);
    }
    cin >> N >> M;
    int s, t, k;
    for(int i=0;i<M;i++) {
        cin >> t >> k;
        for(int j=0;j<k;j++) {
            cin >> s;
            edges[t].insert(s);
        }
    }
    //initialize priority queue
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i=1;i<=N;i++) {
        if(edges[i].size() == 0) {
            pq.push(i);
        }
    }
    bool first = true;
    while(!pq.empty()) {
        int cur = pq.top();
        pq.pop();
        if(seen[cur]) continue;

        seen[cur] = true;
        cout << (first ? "" : " " ) << cur;
        first = false;
        for(int i=1;i<=N;i++) {
            edges[i].erase(cur);
            if(edges[i].size() == 0) {
                pq.push(i);
            }
        }
    }
    cout << '\n';
    return 0;
}

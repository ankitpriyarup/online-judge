#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, vector<int> > graph;
    vector<int> roots;
    for (int i = 0; i < n; i++) {
        graph[i + 1] = vector<int>();
    }
    int parent;
    for (int i = 0; i < n; i++) {
        cin >> parent;
        if (parent == -1) {
            roots.push_back(i + 1);
        } else {
            graph[parent].push_back(i + 1);
        }
    }

    queue<int> q;
    int depth = 0;
    for (int i = 0; i < roots.size(); i++) {
        int count = 0;
        q.push(roots[i]);
        while (q.size()) {
            int size = q.size();
            while (size-- > 0) {
                int node = q.front();
                q.pop();
                for (int j = 0; j < graph[node].size(); j++) {
                    q.push(graph[node][j]);
                }
            }
            count++;
        }
        depth = max(depth, count);
    }

    cout << depth << endl;

    return 0;
}

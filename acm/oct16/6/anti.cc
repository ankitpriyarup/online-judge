#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int N;
int total = 0;
map<string, int> lookup;
vector<int> graph[1003];
bool visit[1003];

int get_id(string name) {
    if (lookup.find(name) == lookup.end()) {
        lookup[name] = total;
        ++total;
    }

    return lookup[name];
}

int bfs(int x) {
    queue<int> q;
    q.push(x);
    memset(visit, 0, sizeof(visit));

    int count = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (visit[cur]) {
            continue;
        }
        visit[cur] = true;
        count++;

        for (int nextn : graph[cur]) {
            if (!visit[nextn]) {
                q.push(nextn);
            }
        }
    }

    return count;
}

int main() {
    int T;
    string s, name;

    cin >> T;
    getline(cin, s);
    while (T-- > 0) {
        total = 0;

        cin >> N;
        getline(cin, s);
        for (int i = 0; i < N; ++i) {
            graph[i].clear();
        }
        lookup.clear();

        for (int i = 0; i < N; ++i) {
            getline(cin, s);
            istringstream iss(s);

            iss >> name;
            int id = get_id(name);

            while (iss >> name) {
                int to_id = get_id(name);
                graph[id].push_back(to_id);
            }
        }

        int minCC = 1111;
        for (int i = 0; i < N; ++i) {
            int b = bfs(i);
            minCC = min(b, minCC);
        }

        cout << minCC << '\n';
    }
    return 0;
}

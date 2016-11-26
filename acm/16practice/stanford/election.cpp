#include <iostream>
#include <queue>
#include <set>
#include <map>

using namespace std;

int u, v, m;

set<string> brainwashed;
set<string> targets;
map<string, set<string> > adjList;
queue<string> q;

int main() {
    int T;
    cin >> T;
    string name, name2;
    while (T-- > 0) {
        cin >> u >> v >> m;
        brainwashed.clear();
        targets.clear();
        adjList.clear();
        q = queue<string>();

        for (int i = 0; i < u; ++i) {
            cin >> name;
            brainwashed.insert(name);
            q.push(name);
        }

        for (int i = 0; i < v; ++i) {
            cin >> name;
            targets.insert(name);
        }

        for (int i = 0; i < m; ++i) {
            cin >> name >> name2;
            adjList[name].insert(name2);
        }

        while (!q.empty()) {
            name = q.front();
            q.pop();

            for (string next : adjList[name]) {
                if (brainwashed.find(next) == brainwashed.end()) {
                    brainwashed.insert(next);
                    q.push(next);
                }
            }
        }

        bool started = false;
        for (string name : targets) {
            if (brainwashed.find(name) != brainwashed.end()) {
                if (started) cout << ' ';
                cout << name;
                started = true;
            }
        }
        cout << '\n';
    }

    return 0;
}


#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <queue>
#include <map>

using namespace std;

const int MAX_C = 55;
const int MAX_R = 55;
map<string, int> colors;

struct edge {
    string end;
    string color;
    int quant;

    edge(): end(""), color(""), quant(0) {};
    edge(string e, string c, int q): end(e), color(c), quant(q) {};
};

map<string, vector<edge> > graph;
set<string> in_stack;
int len;

string init;
int best_len;
vector<string> out;
map<string, string> previous;

void dfs(string cur, int len) {
    // cout << "dfs(" << cur << ", " << len << ")\n";

    if (len > best_len) {
        best_len = len;
        string s = cur;
        out.clear();
        while (s != init) {
            out.push_back(s);
            s = previous[s];
        }
        out.push_back(init);
    }

    for (edge e : graph[cur]) {
        if (in_stack.find(e.end) == in_stack.end() and colors[e.color] >= e.quant) {
            in_stack.insert(e.end);
            colors[e.color] -= e.quant;
            previous[e.end] = cur;

            dfs(e.end, len + 1);

            colors[e.color] += e.quant;
            in_stack.erase(e.end);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    int ncolors, routes;
    cin >> ncolors >> routes;

    cin >> init;

    string name;
    int amt;

    for (int i = 0; i < ncolors; ++i) {
        cin >> name >> amt;
        colors[name] = amt;
    }

    string start, end, color;
    int quant;
    for (int i = 0; i < routes; ++i) {
        cin >> start >> end >> color >> quant;
        graph[start].push_back(edge {end, color, quant});
        graph[end].push_back(edge {start, color, quant});
    }

    in_stack.insert(init);
    dfs(init, 1);

    // cout << out.size() << '\n';
    for (int i = out.size() - 1; i >= 0; --i) {
        cout << out[i] << ' ';
    }
    cout << '\n';
    return 0;
}

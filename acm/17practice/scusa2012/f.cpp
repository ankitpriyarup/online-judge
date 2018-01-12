#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;
using ll = long long;

const int MAXP = 103;
int p, b, d;
string name[MAXP];
map<string, vector<string> > depmap;
map<string, vector<string> > inverse;

map<string, int> in_degree;
set<string> closure;

void find_closure(const string src) {
    in_degree.clear();
    closure.clear();

    queue<string> q;
    q.push(src);
    closure.insert(src);
    while (!q.empty()) {
        string cur = q.front();
        q.pop();

        for (string child : inverse[cur]) {
            ++in_degree[cur];
            if (closure.find(child) == closure.end()) {
                closure.insert(child);
                q.push(child);
            }
        }
    }
}

vector<string> ans;

void top_sort() {
    int exp_size = closure.size();
    ans.clear();
    set<string> q;

    for (string s : closure) {
        if (in_degree[s] == 0) {
            q.insert(s);
        }
    }

    while (!q.empty()) {
        string cur = *q.begin();
        q.erase(q.begin());

        ans.push_back(cur);
        for (string child : depmap[cur]) {
            --in_degree[child];
            if (in_degree[child] == 0) {
                q.insert(child);
            }
        }
    }

    if (ans.size() != exp_size) {
        cout << "This build is not possible.\n";
    } else {
        for (string s : ans) {
            cout << s << '\n';
        }
    }
}

void solve() {
    cin >> p;
    cin >> b;

    depmap.clear();
    inverse.clear();

    int deps;
    string junk, dep;

    for (int i = 0; i < p; ++i) {
        cin >> deps >> name[i];
        for (int j = 0; j < deps; ++j) {
            cin >> dep;

            depmap[dep].push_back(name[i]);
            inverse[name[i]].push_back(dep);
        }
    }

    for (int i = 0; i < b; ++i) {
        cin >> junk >> dep;
        find_closure(dep);

        cout << "Build " << (i + 1) << ":\n";
        top_sort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    for (int case_num = 1; case_num <= T; ++case_num) {
        cout << "Product " << case_num << ":\n";
        solve();

        if (case_num < T) {
            cout << "\n";
        }
    }

    return 0;
}

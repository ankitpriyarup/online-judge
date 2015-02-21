#include <iostream>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

int T, N;
string names[1001];
string a, b;
int tree[1001];
bool visited[1001];
int tree_count = 0;

void dfs (int start, int cut) {
    if (visited[start] || start == cut) {
        return;
    }

    visited[start] = true;
    tree_count++;

    for (int i = 0; i < N; i++) {
        if (tree[i] == start) {
            dfs(i, cut);
        }
    }
}

int main() {
    cin >> T;
    for (int case_num = 0; case_num < T; case_num++) {
        map<string, int> name_to_index;
        cin >> N >> names[0];
        for (int i = 1; i < N; i++) {
            cin >> a >> b;
            names[i] = b;
            name_to_index[b] = i;
            tree[i] = name_to_index[a];
        }

        int cut = 0;
        int min_max_tree = N;
        for (int i = 0; i < N; i++) {
            memset(visited, 0, sizeof(visited));
            int tree_size = 0;
            for (int j = 0; j < N; j++) {
                if (!visited[j]) {
                    tree_count = 0;
                    dfs(j, i);
                    tree_size = max(tree_size, tree_count); 
                }
            }
//            cout << "Cutting out " << i << " gives tree size " << tree_size << '\n';
            if (tree_size < min_max_tree) {
                min_max_tree = tree_size;
                cut = i;
            }
        }

        cout << names[cut] << '\n';
    }
    return 0;
}

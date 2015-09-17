#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N, score[500005];                                                   
long long tree_score[500005];

void set_score(int node, int parent, vector<vector<int> > &tree) {
    if (tree_score[node] != -1LL) {
        return;
    }
    
    tree_score[node] = score[node];
    for (auto it = tree[node].begin(); it != tree[node].end(); ++it) {
        if (*it != parent) {
            set_score(*it, node, tree);
            tree_score[node] += tree_score[*it];
        }
    }
}

long long get_score(int node, int parent) {
    if (parent >= 0 && parent < N) {
        if (tree_score[node] > tree_score[parent]) {
            return tree_score[0] - tree_score[parent];
        } else {
            return tree_score[node];
        }
    } else {
        return tree_score[0];
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> score[i];
    }
    
    vector<vector<int> > tree(N + 1);
    
    int a, b;
    for (int i = 0; i < N - 1; ++i) {
        cin >> a >> b;
        a--;
        b--;
        
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    memset(tree_score, -1, sizeof(tree_score));
    set_score(0, -1, tree);
    
    long long opponent_score = get_score(0, -1);
    for (int i = 0; i < N; ++i) {
        long long max_subtree = 0LL;
        for (auto it = tree[i].begin(); it != tree[i].end(); ++it) {
            max_subtree = max(max_subtree, get_score(*it, i));
        }
        opponent_score = min(opponent_score, max_subtree);
    }
    
    cout << tree_score[0] - opponent_score << '\n';
    
    return 0;
}

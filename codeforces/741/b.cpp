#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int num_people, friend_pairs, max_weight;

// disjoint set data structure
int parent[1003];

int find(int x) {
    int a = parent[x];
    while (a != parent[a]) {
        a = parent[a];
    }

    parent[x] = a;
    return a;
}

void ds_union(int x, int y) {
    int x_parent = find(x);
    int y_parent = find(y);
    parent[x_parent] = y_parent;
}

int weight[1003];
int beauty[1003];

// Converts from the union find number to the index in the vector
int group_inv[1003];

vector<vector<int> > groups;
int group_beauty[1003];
int group_weight[1003];

long long dp[1003][1003];

int main() {
    cin >> num_people >> friend_pairs >> max_weight;
    for (int i = 0; i < num_people; ++i) {
        cin >> weight[i];
    }

    for (int i = 0; i < num_people; ++i) {
        cin >> beauty[i];

        parent[i] = i;
    }

    int a, b;
    for (int i = 0; i < friend_pairs; ++i) {
        cin >> a >> b;
        ds_union(a - 1, b - 1);
    }

    /*
    for (int i = 0; i < num_people; ++i) {
        cout << parent[i] << ' ';
    }
    cout << '\n';
    */

    memset(group_inv, -1, sizeof(group_inv));
    memset(group_weight, 0, sizeof(group_weight));
    memset(group_beauty, 0, sizeof(group_beauty));
    groups.clear();

    for (int i = 0; i < num_people; ++i) {
        int group = find(i);
        if (group_inv[group] == -1) {
            group_inv[group] = groups.size();
            groups.push_back(vector<int>());
        }

        groups[group_inv[group]].push_back(i);
        group_weight[group_inv[group]] += weight[i];
        group_beauty[group_inv[group]] += beauty[i];
    }

    int num_groups = groups.size();
    // Print out all the groups
    /*
    for (int i = 0; i < num_groups; ++i) {
        cout << "Group " << i << '\n';
        for (int person : groups[i]) {
            cout << person << ' ';
        }
        cout << '\n';
        cout << group_weight[i] << ' ' << group_beauty[i] << '\n';
    }
    */

    // Time for knapsack
    memset(dp[0], 0, sizeof(dp[0]));

    for (int i = 1; i <= num_groups; ++i) {
        for (int j = 1; j <= max_weight; ++j) {
            // Don't take anything
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);

            // Try adding the whole group
            if (group_weight[i - 1] <= j) {
                dp[i][j] = max(dp[i][j], group_beauty[i - 1] + dp[i - 1][j - group_weight[i - 1]]);
            }

            // Try adding individuals
            for (int person : groups[i - 1]) {
                if (weight[person] <= j) {
                    dp[i][j] = max(dp[i][j], beauty[person] + dp[i - 1][j - weight[person]]);
                }
            }
        }
    }

    cout << dp[num_groups][max_weight] << '\n';

    return 0;
}

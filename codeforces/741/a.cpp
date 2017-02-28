#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>

using namespace std;

int n;
int a[102];
bool visited[102];

void dfs(int node, int& size, int& last) {
    // cout << "dfs(" << node << ", " << size << ")\n";
    if (visited[node]) {
        last = node;
    } else {
        visited[node] = true;
        size += 1;
        dfs(a[node], size, last);
    }
}

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    bool works = true;
    long long ans = 1;

    memset(visited, 0, sizeof(visited));
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            int start = i;
            int last = i;
            int size = 0;
            dfs(i, size, last);

            // cout << i << ' ' << start << ' ' << last << ' ' << size << '\n';
            if (start != last) {
                works = false;
                break;
            }

            int cost = (size & 1) ? size : size >> 1;
            ans = lcm(ans, cost);
        }
    }

    cout << (works ? ans : -1) << '\n';

    return 0;
}

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <set>
#include <queue>
#define MAX_N 21

using namespace std;

int N, H;
long long heights[MAX_N], weights[MAX_N], strengths[MAX_N];
long long height[(1 << 21)];
long long weak_link[(1 << 21)];

int main() {
    ifstream fin("guard.in");
    ofstream fout("guard.out");
    fin >> N >> H;

    for (int i = 0; i < N; i++) {
        fin >> heights[i] >> weights[i] >> strengths[i];
    }

    height[0] = 0LL;
    weak_link[0] = 2000000000LL;

    long long ans = -1;
    for (int i = 1; i <= (1 << N); i++) {
        weak_link[i] = 0LL;
        for (int j = 1, pos = 0; j <= i; j *= 2, pos++) {
            if (i & j) {
                // add cow with position pos to subset i & ~j
                int old_subset = i & ~j;
                if (weights[pos] <= weak_link[old_subset]) {
                    height[i] = height[old_subset] + heights[pos];
                    weak_link[i] = max(weak_link[i], min(weak_link[old_subset] - weights[pos], strengths[pos]));
                    if (height[i] >= H) {
                        ans = max(ans, weak_link[i]);
                    }
                }
            }
        }
    }

    if (ans >= 0) {
        fout << ans << '\n';
    } else {
        fout << "Mark is too tall\n";
    }
    return 0;
}

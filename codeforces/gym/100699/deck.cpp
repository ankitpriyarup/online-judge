#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <unordered_set>
#include <unordered_map>

constexpr int MAX_N = 1005;

using namespace std;

int n;
int arr[MAX_N];
vector<int> dp[MAX_N];

bool better(vector<int> &a, vector<int> &b) {
    for (int i = 0; i < min(a.size(), b.size()); i++) {
        if (a[i] > b[i]) return true;
        if (b[i] > a[i]) return false;
    }

    return a.size() >= b.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    scanf(" %d", &n);
    for (int i = 1; i <= n; i++) {
        scanf(" %d", &arr[i]);
    }

    dp[2].push_back(max(arr[1], arr[2]));
    for (int i = 3; i <= n; i++) {
        vector<int> opt1 = dp[i-2];
        opt1.push_back(max(arr[i], arr[i-1]));
        vector<int> opt2 = dp[i-3];
        opt2.push_back(max(max(arr[i], arr[i-1]), arr[i-2]));
        sort(opt1.rbegin(), opt1.rend());
        sort(opt2.rbegin(), opt2.rend());
        if (better(opt1, opt2)) {
            dp[i] = opt1;
        } else {
            dp[i] = opt2;
        }
    }

    for (int x : dp[n]) {
        printf("%d\n", x);
    }

    return 0;
}

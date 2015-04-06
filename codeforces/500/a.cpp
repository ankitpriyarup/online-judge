#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

int N, T;
int a[30003];
int main() {
    cin >> N >> T;
    for (int i = 1; i < N; i++) {
        cin >> a[i];
    }

    int pos = 1;
    while (pos < T) {
        pos += a[pos];
    }

    if (pos == T) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}

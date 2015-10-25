#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    pair<int, int> a[1000006];
    pair<int, int> b[1000006];
    int c = 1;

    while (cin >> N) {
        int t;
        for (int i = 0; i < N; ++i) {
            cin >> t;
            a[i] = make_pair(t, i);
        }

        for (int i = 0; i < N; ++i) {
            cin >> t;
            b[i] = make_pair(t, i);
        }

        sort(a, a + N);
        sort(b, b + N);
        int j = N - 1;
        while (j >= 0 && a[j].second == b[j].second) {
            j--;
        }

        if (j < 0) {
            cout << "Case " << c++ << ": agree" << '\n';
        } else {
            cout << "Case " << c++ << ": " << (N - j) << '\n';
        }
    }
    return 0;
}


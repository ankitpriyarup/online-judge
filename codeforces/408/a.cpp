#include <iostream>
#include <algorithm>

using namespace std;

int N;
int k[101];
int t;
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> k[i];
    }

    int best = 0x7fffffff;
    for (int i = 0; i < N; i++) {
        int cur = 0;
        for (int j = 0; j < k[i]; j++) {
            cin >> t;
            cur += 5*t;
            cur += 15;
        }
        best = min(best, cur);
    }

    cout << best << '\n';
    return 0;
}

#include <iostream>

using namespace std;

long long ways[55];
long long ans[55];

void solve(long long N, long long offset, long long K, long long bump) {
    //cout << N << ' ' << offset << ' ' << K << ' ' << bump << '\n';
    if (N == 0) {
        return;
    }

    if (K > ways[N - 1]) {
        ans[offset] = 2 + bump;
        ans[offset + 1] = 1 + bump;
        solve(N - 2, offset + 2, K - ways[N - 1], bump + 2);
    } else {
        ans[offset] = 1 + bump;
        solve(N - 1, offset + 1, K, bump + 1);
    }
}

int main() {
    long long N, K;
    cin >> N >> K;

    ways[0] = 1;
    ways[1] = 1;
    ways[2] = 2;
    for (int i = 3; i < 55; i++) {
        ways[i] = ways[i - 1] + ways[i - 2];
    }

    solve(N, 0, K, 0);

    cout << ans[0];
    for (int i = 1; i < N; i++) {
        cout << ' ' << ans[i];
    }

    cout << '\n';
}

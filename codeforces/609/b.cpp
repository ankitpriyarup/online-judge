#include <iostream>

using namespace std;

int N, M;
int genre[11];
int main() {
    cin >> N >> M;
    int x;
    for (int i = 0; i < N; ++i) {
        cin >> x;
        genre[x]++;
    }

    long long ans = 1LL * N * (N - 1) / 2LL;
    for (int i = 0; i <= M; ++i) {
        x = genre[i];
        ans -= 1LL * x * (x - 1) / 2LL;
    }

    cout << ans << '\n';
    return 0;
}

#include <iostream>

using namespace std;

int N, M, K;

int main() {
    cin >> N >> K;

    int last = -1;

    int a;
    int ans = 0;
    for (int i = 0; i < K; ++i) {
        cin >> M;
        for (int j = 0; j < M; ++j) {
            cin >> a;
            if (a == 1) {
                last = 1;
            } else if (a == last + 1) {
                last++;
            }
        }

        if (last > 1) {
            ans -= 2 * (last - 1);
        }

        last = -1;

        ans += (M - 1);
    }

    ans += (N - 1);
    cout << ans << '\n';
    
    return 0;
}

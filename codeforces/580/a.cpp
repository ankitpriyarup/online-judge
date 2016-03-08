#include <iostream>

using namespace std;

int main() {
    int N;
    int x;
    cin >> N;
    int ans = 0;
    int cur = 0;
    int last = -1;
    for (int i = 0; i < N; ++i) {
        cin >> x;
        if (x >= last) {
            cur += 1;
            last = x;
        } else {
            ans = max(ans, cur);
            cur = 1;
            last = x;
        }
    }

    cout << max(ans, cur) << '\n';
}

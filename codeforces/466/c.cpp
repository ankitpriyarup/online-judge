#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int a[N];
    long long sum = 0LL;

    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    if (sum % 3 != 0) {
        cout << "0\n";
        return 0;
    }

    long long target = sum / 3;
    int suffix[N];
    sum = a[N - 1];
    suffix[N - 1] = (sum == target);

    for (int i = N - 2; i >= 0; --i) {
        suffix[i] = suffix[i + 1];
        sum += a[i];
        suffix[i] += (sum == target);
    }
    sum = 0LL;
    long long ans = 0LL;
    for (int i = 0; i < N - 2; ++i) {
        sum += a[i];
        if (sum == target) {
            ans += suffix[i + 2];
        }
    }
    
    cout << ans << '\n';
    return 0;
}

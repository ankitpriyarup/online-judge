#include <iostream>
#include <algorithm>

using namespace std;

int N;
long long a[100005];

int main() {
    cin >> N;
    long long sum = 0;

    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    sort(a, a + N);
    reverse(a, a + N);

    long long per = sum / N;
    long long extra = sum % N;

    long long ans = 0;
    for (int i = 0; i < N; ++i) {
        long long target = extra > 0 ? per + 1 : per;
        if (a[i] > target) {
            ans += a[i] - target;
        } else if (a[i] < target) {
            ans += target - a[i];
        }

        extra--;
    }

    cout << ans / 2LL << '\n';
    return 0;
}

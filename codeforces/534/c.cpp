#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
long long A;
int d[200005];
long long ans[200005];
long long sum;

int main() {
    cin >> N >> A;

    for (int i = 0; i < N; i++) {
        cin >> d[i];
        sum += d[i];
    }

    for (int i = 0; i < N; i++) {
        long long without = sum - d[i];
        long long minn = max(A - without, 1LL);
        long long maxx = min(A - (N - 1), 0LL + d[i]);
        //cout << minn << " -> " << maxx << '\n';
        
        ans[i] = d[i] - (maxx - minn + 1);
    }

    cout << ans[0];
    for (int i = 1; i < N; i++) {
        cout << " " << ans[i];
    }
    cout << '\n';

    return 0;
}

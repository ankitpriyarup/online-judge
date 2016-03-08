#include <iostream>
#include <cstring>

#define MAX_N 100005
using namespace std;

int N;
int fenwick[MAX_N];

// update the backing array at index by delta
void update(int index, int delta) {
    for (int i = index; i <= N; i += (i & -i)) {
        fenwick[i] += delta;
    }
}

int get(int a) {
    int ans = 0;
    for (int i = a; i > 0; i -= (i & -i)) {
        ans += fenwick[i];
    }

    return ans;
}

int sum(int a, int b) {
    return get(b) - get(a - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;

    N = s.size();
    int a[N];
    memset(a, 0, sizeof(a));
    for (int i = 1; i < N; ++i) {
        if (s[i] == s[i - 1]) {
            a[i - 1] = 1;
        }
    }

    /*
    cout << '\n';
    for (int i = 0; i < N; ++i) {
        cout << a[i] << ' ';
    }
    cout << '\n';
    */

    for (int i = 0; i < N; ++i) {
        update(i + 1, a[i]);
    }

    int M;
    cin >> M;

    int x, y;
    while (M-- > 0) {
        cin >> x >> y;
        cout << sum(x, y - 1) << '\n';
    }

    return 0;
}

#include <iostream>
#include <algorithm>
#include <utility>
#define MAX_N 200005
using namespace std;

int N, Q, l, r;
int a[MAX_N];
int seg[MAX_N];
int freq[MAX_N];

int main() {
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a, a + N, greater<int>());

    for (int i = 0; i < Q; i++) {
        cin >> l >> r;
        l--;
        r--;
        seg[l]++;
        seg[r + 1]--;
    }
    
    int count = 0;
    for(int i = 0; i < N; i ++) {
        count += seg[i];
        freq[i] = count;
    }
    sort(freq, freq + N, greater<int>());
    long long max = 0LL;
    for (int i = 0; i < N; i++) {
        max += 1LL * a[i] * freq[i];
    }
    cout << max << '\n';
    return 0;
}

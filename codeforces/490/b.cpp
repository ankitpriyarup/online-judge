#include <iostream>
#include <queue>
#include <cstring>
#include <set>
#include <algorithm>

using namespace std;

int N, a, b;
int fb[1000001], bf[1000001];
int ans[200001];

int main() {
    cin >> N;
    memset(fb, -1, sizeof fb);
    memset(bf, -1, sizeof bf);
    set<int> aSet;
    set<int> bSet;

    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        fb[a] = b;
        bf[b] = a;
        if (bSet.count(a) == 0) {
            aSet.insert(a);
        }
        bSet.insert(b);
        aSet.erase(b);
    }

    ans[0] = *aSet.begin();
    ans[1] = fb[0];

    for (int i = 2; i < N; i++) {
        ans[i] = fb[ans[i - 2]];
    }

    cout << ans[0];
    for (int i = 1; i < N; i++) {
        cout << " " << ans[i];
    }
    cout << '\n';
}

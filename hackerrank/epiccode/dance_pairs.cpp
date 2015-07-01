#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#include <utility>
#include <map>

using namespace std;

int N, K;
int boys[100005];
int girls[100005];

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> boys[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> girls[i];
    }
    sort(boys, boys + N);
    sort(girls, girls + N);

    int bp = 0;
    int gp = 0;
    int ans = 0;

    while (bp < N && gp < N) {
        int diff = boys[bp] - girls[gp];
        if (diff <= K && -K <= diff) {
            bp++;
            gp++;
            ans++;
        } else if (boys[bp] < girls[gp]) {
            bp++;
        } else {
            gp++;
        }
    }

    cout << ans << '\n';

    return 0;
}

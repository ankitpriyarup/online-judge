#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#include <utility>
#include <map>

using namespace std;

int N, M;
int boys[101];
int girls[101];
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> boys[i];
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> girls[i];
    }
    sort(boys, boys + N);
    sort(girls, girls + M);

    int bp = 0;
    int gp = 0;
    int ans = 0;

    while (bp < N && gp < M) {
        int diff = boys[bp] - girls[gp];
        if (diff <= 1 && -1 <= diff) {
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

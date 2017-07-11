#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>

using namespace std;

int n;
string words[15];

int same(const string& a, const string& b) {
    int i = 0;
    int j = 0;
    int ret = 0;

    while (i < a.size() and j < b.size()) {
        if (a[i] == b[j]) {
            ++ret;
            ++i;
            ++j;
        } else if (a[i] < b[j]) {
            ++i;
        } else {
            ++j;
        }
    }

    return ret;
}

int score() {
    int ret = 0;
    for (int i = 1; i < n; ++i) {
        ret += same(words[i - 1], words[i]);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    sort(words, words + n);
    int ans = 1e9;
    do {
        ans = min(ans, score());
    } while (next_permutation(words, words + n));

    cout << ans << '\n';

    return 0;
}

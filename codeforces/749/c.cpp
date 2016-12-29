#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int n;
char s[200005];
bool skip[200005];

int get_next(int expected, int a, int b) {
    if (expected == a or expected == b) {
        return expected;
    }

    if ((a > expected) == (b > expected)) {
        return min(a, b);
    } else {
        return max(a, b);
    }
}

int main() {
    cin >> n;
    cin >> s;

    memset(skip, 0, sizeof(skip));

    queue<int> d;
    queue<int> r;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'D') {
            d.push(i);
        } else {
            r.push(i);
        }
    }

    int i = 0;
    while (!d.empty() and !r.empty()) {
        int cur_d = d.front();
        int cur_r = r.front();
        d.pop();
        r.pop();

        i = get_next(i, cur_d, cur_r);

        if (i == cur_d) {
            d.push(cur_d);
        } else if (i == cur_r){
            r.push(cur_r);
        }

        ++i;
        i %= n;
    }

    if (d.empty()) {
        cout << 'R';
    } else {
        cout << 'D';
    }

    return 0;
}

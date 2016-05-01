#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, p;
    string s;
    cin >> n >> p;
    cin >> s;
    p--;
    int score = 0;
    if (n % 2 == 1 and p == n / 2) {
        score++;
        p--;
    }
    if (p >= n / 2) {
        p = (n / 2) - (p - (n / 2));
        if (n % 2 == 0)
            p--;
    }

    int start = 0;
    int end = n - 1;
    while (start < end and s[start] == s[end]) {
        start++;
        end--;
    }
    int i, j;
    int lastchange = -1;
    for (i = start, j = end; i < j; ++i, --j) {
        int a = s[i] - 'a';
        int b = s[j] - 'a';
        int diff = min((a - b + 26) % 26, (b - a + 26) % 26);
        if (diff > 0) lastchange = i;
        score += diff;
    }
    if (lastchange == -1) {
        cout << 0 << '\n';
    } else {
        //cout << start << ' ' << p << ' ' << lastchange << '\n';
        if (start <= p && p <= lastchange) {
            score += 2 * min(p - start, lastchange - p) + max(p - start, lastchange - p);
        } else if (p <= start && p <= lastchange) {
            score += lastchange - p;
        } else {
            score += p - start;
        }
        cout << score << '\n';
    }
    return 0;
}

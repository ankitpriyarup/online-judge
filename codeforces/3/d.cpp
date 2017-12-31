#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>

using namespace std;
using ll = long long;
using pii = pair<ll, int>;

constexpr int MAXN = 50004;
char s[MAXN];

int main() {
    scanf("%s", s);
    int n = strlen(s);
    ll score = 0;

    int prefix = 0;
    bool poss = true;

    int a, b;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            ++prefix;
        } else if (s[i] == ')') {
            --prefix;
        } else {
            scanf("%d %d", &a, &b);
            s[i] = ')';
            score += b;
            pq.push({a - b, i});
            // printf("Pushed %d %d\n", a - b, i);
            --prefix;
        }

        if (prefix < 0 and !pq.empty()) {
            pii cur = pq.top();
            pq.pop();

            // printf("Popped %d %d\n", cur.first, cur.second);
            score += cur.first;
            prefix += 2;
            s[cur.second] = '(';
        }

        if (prefix < 0) {
            poss = false;
            break;
        }
    }

    if (!poss or prefix != 0)
        return printf("%d\n", -1), 0;

    printf("%I64d\n", score);
    // printf("%lld\n", score);
    printf("%s\n", s);

    return 0;
}

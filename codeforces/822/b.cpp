#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

const int MAXN = 1003;
int n, m;
char s[MAXN], t[MAXN];

int main() {
    scanf("%d %d", &n, &m);
    scanf("%s %s", s, t);

    vector<int> ans;
    int best = n + 1;
    int pos = 0;
    for (int i = 0; i + n <= m; ++i) {
        int diff = 0;
        for (int j = 0; j < n; ++j) {
            if (s[j] != t[i + j]) {
                ++diff;
            }
        }

        if (diff < best) {
            best = diff;
            pos = i;
            ans.clear();
            for (int j = 0; j < n; ++j) {
                if (s[j] != t[i + j])
                    ans.push_back(j + 1);
            }
        }
    }

    printf("%d\n", ans.size());
    for (int x : ans) {
        printf("%d ", x);
    }
    printf("\n");

    return 0;
}

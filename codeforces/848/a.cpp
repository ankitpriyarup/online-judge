#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <queue>
#include <map>

using namespace std;

const int MAXN = 100005;
int n;
int a[MAXN];
char s[MAXN];

int main() {
    scanf("%d", &n);
    if (n == 0) {
        printf("%c\n", 'a');
        return 0;
    }

    memset(s, 0, sizeof(s));
    int score = 0;
    int ptr = 0;
    for (char c = 'a'; score < n; ++c) {
        s[ptr] = c;
        ++ptr;

        for (int i = 1; score + i <= n; ++i) {
            s[ptr] = c;
            ++ptr;
            score += i;
        }
    }

    printf("%s\n", s);

    return 0;
}

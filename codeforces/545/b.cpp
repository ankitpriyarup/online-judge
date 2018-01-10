#include <cstdio>
#include <cstring>

using namespace std;

constexpr int MAXN = 100005;
int n;
char s[MAXN];
char t[MAXN];

int main() {
    scanf("%s", s);
    scanf("%s", t);

    n = strlen(s);
    int score = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] != t[i]) ++score;
    }

    if (score & 1) {
        printf("impossible\n");
        return 0;
    }

    score >>= 1;
    for (int i = 0; i < n; ++i) {
        if (score and s[i] != t[i]) {
            --score;
            s[i] = t[i];
        }
    }

    printf("%s\n", s);

    return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int counts[3];
char s[55];

int main() {
    scanf("%s", s);

    int n = strlen(s);

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'T')
            ++counts[0];
        else if (s[i] == 'C')
            ++counts[1];
        else
            ++counts[2];
    }

    // printf("%d %d %d\n", counts[0], counts[1], counts[2]);
    long long score = 7LL * min(counts[0], min(counts[1], counts[2]));
    for (int i = 0; i < 3; ++i) {
        score += 1LL * counts[i] * counts[i];
    }

    printf("%lld\n", score);

    return 0;
}

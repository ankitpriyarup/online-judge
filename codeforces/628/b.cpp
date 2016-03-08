#include <cstdio>

using namespace std;

char s[300005];

int main() {
    scanf("%s", s);

    long long ans = 0;
    if ((s[0] - '0') % 4 == 0) {
        ans++;
    }

    for (int i = 1; s[i] != '\0'; ++i) {
        char tens = s[i - 1] - '0';
        char ones = s[i] - '0';
        int val = 10 * tens + ones;
        if (val % 4 == 0) {
            ans += i;
        }
        if (ones % 4 == 0) {
            ans++;
        }
    }

    printf("%I64d\n", ans);

    return 0;
}

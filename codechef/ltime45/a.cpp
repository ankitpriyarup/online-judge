#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

int n;

char word[15];

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    scanf("%d", &T);

    while (T-- > 0) {
        scanf("%d", &n);
        bool was_cookie = false;
        bool good = true;
        for (int i = 0; i < n; ++i) {
            scanf("%s", word);

            if (was_cookie and word[0] == 'm') {
                was_cookie = false;
            } else if (was_cookie) {
                good = false;
            }

            if (word[0] == 'c') {
                was_cookie = true;
            }
        }

        if (was_cookie) {
            good = false;
        }

        printf("%s\n", good ? "YES" : "NO");
    }
    return 0;
}

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

char buf[100005];
int freq[30];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%s", buf);

    vector<char> stk;
    int n = strlen(buf);

    for (int i = 0; i < n; ++i) {
        ++freq[buf[i] - 'a'];
    }

    int ptr = 0;
    for (int i = 0; i < n; ++i) {
        // printf("i: %d\n", i);

        while (ptr < 30 and freq[ptr] == 0) ++ptr;

        while (ptr < 30 and !stk.empty() and stk.back() <= ptr + 'a') {
            printf("%c", stk.back());
            stk.pop_back();

            while (ptr < 30 and freq[ptr] == 0) ++ptr;
        }

        while (ptr < 30 and freq[ptr] == 0) ++ptr;

        if (ptr < 30 and buf[i] - 'a' == ptr) {
            --freq[ptr];
            printf("%c", buf[i]);
        } else {
            --freq[buf[i] - 'a'];
            stk.push_back(buf[i]);
        }
    }

    while (!stk.empty()) {
        printf("%c", stk.back());
        stk.pop_back();
    }

    printf("\n");

    return 0;
}

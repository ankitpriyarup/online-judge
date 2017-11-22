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
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <complex>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int freq[500];
char buf[300005];

int main() {
    memset(freq, 0, sizeof(freq));
    int q;
    scanf(" %d\n", &q);

    while (q-- > 0) {
        gets(buf);
        for (size_t i = 0; buf[i] != '\0'; ++i) {
            ++freq[buf[i]];
        }
    }

    for (char c = 'a'; c <= 'z'; ++c) {
        if (freq[c] > 0) {
            printf("%c %d\n", c, freq[c]);
            // cout << c << ' ' << freq[c] << '\n';
        }
    }
    for (char c = 'A'; c <= 'Z'; ++c) {
        if (freq[c] > 0) {
            printf("%c %d\n", c, freq[c]);
            // cout << c << ' ' << freq[c] << '\n';
        }
    }

    return 0;
}

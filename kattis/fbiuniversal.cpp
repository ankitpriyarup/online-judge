#include <iostream>
#include <iomanip>
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

char word[15];
char translate[300];
char base[] = "0123456789ACDEFHJKLMNPRTVWX";
int dot[] = {2, 4, 5, 7, 8, 10, 11, 13};
int inv[300];

void precomp() {
    memset(translate, 0, sizeof(translate));
    translate['B'] = '8';
    translate['G'] = 'C';
    translate['I'] = '1';
    translate['O'] = '0';
    translate['Q'] = '0';
    translate['S'] = '5';
    translate['U'] = 'V';
    translate['Y'] = 'V';
    translate['Z'] = '2';
    for (int i = 0; i < 27; ++i) {
        inv[base[i]] = i;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    precomp();

    int T;
    scanf("%d", &T);
    int case_num;

    while (T-- > 0) {
        scanf("%d %s", &case_num, word);
        int n = strlen(word);
        int check = 0;
        ll val = 0LL;
        for (int i = 0; i < n - 1; ++i) {
            if (translate[word[i]] != 0) {
                word[i] = translate[word[i]];
            }
            check += dot[i] * inv[word[i]];
            val *= 27;
            val += inv[word[i]];
        }

        if ((check % 27) == inv[word[n - 1]]) {
            printf("%d %lld\n", case_num, val);
        } else {
            printf("%d Invalid\n", case_num);
        }
    }

    return 0;
}

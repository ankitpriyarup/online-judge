#include <cmath>
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100005;
const int MAXA = 30;
int n, k;
char s[MAXN];

// freq[i][j] = # of occurences of char j at positions i-end
int freq[MAXN][MAXA];
int last[MAXA];

int main() {
    scanf("%s", s);
    scanf("%d", &k);
    n = strlen(s);
    
    memset(freq, 0, sizeof(freq));
    memset(last, -1, sizeof(last));
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < MAXA; ++j) {
            freq[i][j] = freq[i + 1][j];
        }

        int c = s[i] - 'a';
        ++freq[i][c];
        last[c] = max(last[c], i);
    }

    // range is [0, n - 1]
    // if there are > k 'z' in the range, take all of them
    // range is now from after the last 'z' to the end
    // repeat for all chars in desc order

    int start = 0;
    vector<pair<char, int> > v;

    for (int j = 25; j >= 0; --j) {
        if (freq[start][j] >= k) {
            v.push_back(make_pair('a' + j, freq[start][j]));

            start = last[j] + 1;
        }
    }
    
    for (pair<char, int> p : v) {
        for (int i = 0; i < p.second; ++i) {
            printf("%c", p.first);
        }
    }
    printf("\n");

    return 0;
}

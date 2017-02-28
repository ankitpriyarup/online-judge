#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <bitset>

using namespace std;

const int MAXN = 100005;
const int SQRTN = sqrt(MAXN);

int n;
int a[MAXN];

struct query {
    int start, end, index;
};

bool cmp(query q1, query q2) {
    int bucket1 = q1.start / SQRTN;
    int bucket2 = q2.start / SQRTN;

    if (bucket1 == bucket2) {
        return q1.end < q2.end;
    } else {
        return bucket1 < bucket2;
    }
}

vector<query> queries;
int output[MAXN];

int ans = 0;
int freq[MAXN];

void add(int pos) {
    // printf("add(%d)\n", pos);
    ++freq[a[pos]];
    if (freq[a[pos]] > 0 and (freq[a[pos]] % 2 == 0)) {
        ++ans;
    } else if (freq[a[pos]] > 1 and freq[a[pos]] % 2 == 1) {
        --ans;
    }

    /*
    for (int i = 1; i <= 3; ++i) {
        printf("%d ", freq[i]);
    }
    printf("| %d\n", ans);
    */
}

void remove(int pos) {
    // printf("remove(%d)\n", pos);
    --freq[a[pos]];
    if (freq[a[pos]] > 0 and freq[a[pos]] % 2 == 0) {
        ++ans;
    } else if (freq[a[pos]] > 0 and freq[a[pos]] % 2 == 1) {
        --ans;
    }

    /*
    for (int i = 1; i <= 3; ++i) {
        printf("%d ", freq[i]);
    }
    printf("| %d\n", ans);
    */
}

int main() {
    ios_base::sync_with_stdio(false);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }

    int q;
    scanf("%d", &q);

    int start, end;
    for (int i = 0; i < q; ++i) {
        scanf("%d %d", &start, &end);
        queries.push_back({start, end, i});
    }

    memset(freq, 0, sizeof(freq));
    sort(queries.begin(), queries.end(), cmp);

    int currentL = 1, currentR = 1;
    for (int i = 0; i < q; ++i) {
        int L = queries[i].start;
        int R = queries[i].end;

        while (currentL < L) {
            remove(currentL);
            currentL++;
        }

        while (currentL > L) {
            currentL--;
            add(currentL);
        }

        while (currentR <= R) {
            add(currentR);
            currentR++;
        }

        while (currentR > R + 1) {
            currentR--;
            remove(currentR);
        }

        output[queries[i].index] = ans;
    }

    for (int i = 0; i < q; ++i) {
        cout << output[i] << '\n';
    }

    return 0;
}

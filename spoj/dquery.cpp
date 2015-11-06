#include <iostream>
#include <cmath>

#define MAXN 300003
#define MAXQ 200002
#define MAXA 1000000
using namespace std;

struct query {
    int start, end, index;
    query(): start(0), end(0), index(0) {}
    query(int start, int end, int index): start(start), end(end), index(index) {}
};

const int sqrtN = sqrt(MAXN);

bool cmp(query q1, query q2) {
    int bucket1 = q1.start / sqrtN;
    int bucket2 = q2.start / sqrtN;

    if (bucket1 == bucket2) {
        return q1.end < q2.end;
    } else {
        return bucket1 < bucket2;
    }
}

int cnt[MAXA];
int a[MAXN];
int ans = 0;

void add(int i) {
    if (cnt[a[i]] == 0) {
        ans++;
    }
    cnt[a[i]]++;
}

void remove(int i) {
    cnt[a[i]]--;
    if (cnt[a[i]] == 0) {
        ans--;
    }
}

// DQUERY on SPOJ
int main() {
    ios_base::sync_with_stdio(false);

    int N, Q;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    cin >> Q;
    query queries[MAXQ];
    int out[Q];

    int start, end;
    for (int i = 0; i < Q; ++i) {
        cin >> start >> end;
        start--;
        end--;
        queries[i] = query(start, end, i);
    }

    sort(queries, queries + Q, cmp);
    memset(cnt, 0, sizeof(cnt));

    int currentL = 0, currentR = 0;
    for (int i = 0; i < Q; ++i) {
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

        out[queries[i].index] = ans;
    }

    for (int i = 0; i < Q; ++i) {
        cout << out[i] << '\n';
    }
}

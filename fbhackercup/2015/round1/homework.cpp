#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <queue>

#define MAXN 10000001
using namespace std;

int T, A, B, K;
int primacity[MAXN];

void gen_primes() {
    memset(primacity, 0, sizeof(primacity));
    primacity[2] = 1;
    for (int i = 3; i < MAXN; i++) {
        if (i % 2 == 0) {
            primacity[i]++;
        }
        else if (primacity[i] == 0) {
            primacity[i]++;
            for (int j = 2 * i; j < MAXN; j += i) {
                primacity[j]++;
            }
        }
    }
}

int solve() {
    int ans = 0;
    for (int i = A; i <= B; i++) {
        if (primacity[i] == K) {
            ans++;
        }
    }
    
    return ans;
}

int main() {
    gen_primes();

    cin >> T;
    for (int case_num = 1; case_num <= T; case_num++) {
        cin >> A >> B >> K;
        cout << "Case #" << case_num << ": " << solve() << '\n';
    }
    return 0;
}

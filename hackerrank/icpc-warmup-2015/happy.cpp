#include <iostream>
#include <cstring>

#define DEBUG 0
#define MAXN 10000

using namespace std;

bool prime[MAXN + 5];

void gen_sieve() {
    memset(prime, 0, sizeof(prime));
    prime[2] = 1;
    for (int i = 3; i <= MAXN; i += 2) {
        prime[i] = 1;
    }

    for (int i = 3; i * i <= MAXN; i += 2) {
        if (prime[i]) {
            for (int j = i * i; j <= MAXN; j += 2 * i) {
                prime[j] = 0;
            }
        }
    }
}

int advance(int n) {
    int sqsum = 0;
    int last;
    while (n >= 10) {
        last = n % 10;
        sqsum += last * last;
        n /= 10;
    }

    sqsum += n * n;
    return sqsum;
}

bool happy(int n) {
    if (!prime[n]) return false;

    int step1 = advance(n);
    int step2 = advance(step1);

    while (step2 != 1) {
        if (step1 == step2 && step1 != 1) {
            return false;
        }

        step1 = advance(step1);
        step2 = advance(advance(step2));
    }
    return true;
}

int main() {
    int T, K, M;
    gen_sieve();
    cin >> T;
    while (T-- > 0) {
        cin >> K >> M;
        cout << K << ' ' << M << ' ' << (happy(M) ? "YES" : "NO") << '\n';
    }
    return 0;
}

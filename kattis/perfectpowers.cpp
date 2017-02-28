#include <iostream>
#include <limits>
#include <cstring>
#include <algorithm>
#include <utility>
#include <set>

using namespace std;

const long long MAX_INT = numeric_limits<int>::max() + 3LL;
set<long long> powers[35];
long long cur_pow[50000];

int main() {
    for (long long i = 2; i * i <= MAX_INT; ++i) {
        cur_pow[i] = i * i;
        powers[2].insert(cur_pow[i]);
    }

    for (int power = 3; power <= 33; ++power) {
        for (long long i = 2; i * i <= MAX_INT; ++i) {
            cur_pow[i] *= i;
            if (cur_pow[i] <= 3 or cur_pow[i] > MAX_INT) {
                break;
            }

            powers[power].insert(cur_pow[i]);
            if (power % 2 == 1) {
                powers[power].insert(-cur_pow[i]);
            }
        }
    }

    long long n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }

        bool found = false;
        for (int i = 33; i >= 2; --i) {
            if (powers[i].find(n) != powers[i].end()) {
                found = true;
                cout << i << '\n';
                break;
            }
        }

        if (!found) {
            cout << 1 << '\n';
        }
    }
}

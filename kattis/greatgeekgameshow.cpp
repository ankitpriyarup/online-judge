#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <numeric>
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;

    // Prob. Permutation has max cycle k
    // D(i <= k) = 1.0
    // D(n) = sum_{i = 1}^k P(n, i) D(n - i)
    // Where P(n, i) is the probability a permutation of length n has first cycle i
    // P(n, i) = (n - 1 choose i - 1) * (i - 1)! * (n - i)! / n!
    // P(n, i) = (n - 1)! / (i - 1)! / (n - i)! * (i - 1)! * (n - i)! / n!
    // P(n, i) = (n - 1)! / n!
    // P(n, i) = 1 / n
    // D(n) = sum_{i = 1}^k 1 / n D(n - i)
    // D(n) = (sum_{i = 1}^k D(n - i)) / n
    // Just keep a sliding window of length k
    deque<double> d(k, 1.0);
    double sum = k;
    for (int i = k + 1; i <= n; ++i) {
        double new_d = sum / i;
        d.push_back(new_d);
        sum += new_d;
        sum -= d.front();
        d.pop_front();
    }

    cout << d.back() << '\n';

    return 0;
}

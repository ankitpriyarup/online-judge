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
using vi = vector<int>;

void print_vec(const vi& v) {
    printf("%lu", v.size());
    for (int val : v) {
        printf(" %d", val);
    }
    printf("\n");
}

int mod3(const vi& v) {
    int sum = 0;
    for (int x : v) {
        sum += x;
        sum %= 3;
    }

    return sum;
}

void sub(vi& v, const int& m) {
    v[0] -= m;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] < 0) {
            v[i] += 10;
            if (i + 1 < v.size())
                --v[i + 1];
            else
                v.push_back(-1);
        } else if (v[i] >= 10) {
            v[i] -= 10;
            if (i + 1 < v.size())
                v[i + 1] += 1;
            else
                v.push_back(1);
        } else {
            break;
        }
    }
}

vi div3(const vi& v) {
    vector<int> res;
    int cur = 0;
    for (int i = v.size() - 1; i >= 0; --i) {
        cur *= 10;
        cur += v[i];

        int k = cur / 3;
        res.push_back(k);
        cur -= 3 * k;
    }

    reverse(begin(res), end(res));
    while (!res.empty() and res.back() == 0)
        res.pop_back();

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q;
    cin >> q;
    string s;

    while (q-- > 0) {
        vi v;
        cin >> s;
        for (int i = s.size() - 1; i >= 0; --i) {
            v.push_back(s[i] - '0');
        }

        vi pos, neg;
        int i = 0;
        while (!v.empty()) {
            int m = mod3(v);
            if (m == 1) {
                pos.push_back(i);
                sub(v, 1);
            } else if (m == 2) {
                neg.push_back(i);
                sub(v, -1);
            }

            v = div3(v);
            ++i;
        }

        print_vec(pos);
        print_vec(neg);
    }

    return 0;
}

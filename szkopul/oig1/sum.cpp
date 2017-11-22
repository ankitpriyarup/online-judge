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

struct bigint {
    bool is_neg;
    vector<int> digits;
    int shift;

    bigint(string word) {
        if (word[0] == '+' or word[0] == '-') {
            is_neg = (word[0] == '-');
            word = word.substr(1);
        } else {
            is_neg = false;
        }

        shift = 0;
        bool in_dec = false;
        for (char c : word) {
            if (in_dec) ++shift;
            if (c == ',') {
                in_dec = true;
            } else {
                digits.push_back(c - '0');
            }
        }

        if (digits.empty()) is_neg = false;
    }

    bigint(bool is_neg, vector<int> digits, int shift): is_neg(is_neg), digits(digits), shift(shift) { }

    void shift_up(int x) {
        while (shift < digits.size() and digits[0] == 0) {
            digits.erase(digits.begin());
        }

        while (x-- > 0) {
            digits.push_back(0);
            ++shift;
        }
    }

    vector<int> sum(const bigint& a, const bigint& b) const {
        vector<int> a_dig(begin(a.digits), end(a.digits));
        vector<int> b_dig(begin(b.digits), end(b.digits));
        reverse(begin(a_dig), end(a_dig));
        reverse(begin(b_dig), end(b_dig));

        int carry = 0;
        vector<int> res;
        for (int i = 0; i < max(a_dig.size(), b_dig.size()); ++i) {
            int s = (i < a_dig.size() ? a_dig[i] : 0) + (i < b_dig.size() ? b_dig[i] : 0) + carry;
            res.push_back(s % 10);
            carry = s / 10;
        }

        reverse(begin(res), end(res));

        return res;
    }

    vector<int> sub(const bigint& a, const bigint& b) const {
        vector<int> a_dig(begin(a.digits), end(a.digits));
        vector<int> b_dig(begin(b.digits), end(b.digits));
        reverse(begin(a_dig), end(a_dig));
        reverse(begin(b_dig), end(b_dig));

        vector<int> res;
        for (int i = 0; i < b_dig.size(); ++i) {
            while (a_dig[i] < b_dig[i]) {
                a_dig[i] += 10;
                a_dig[i + 1] -= 1;
            }

            res.push_back(a_dig[i] - b_dig[i]);
        }

        for (int i = b_dig.size(); i < a_dig.size(); ++i) {
            while (a_dig[i] < 0) {
                a_dig[i] += 10;
                a_dig[i + 1] -= 1;
            }

            res.push_back(a_dig[i]);
        }

        reverse(begin(res), end(res));

        return res;
    }

    bigint operator+(const bigint& other) const {
        assert(shift == other.shift);

        if (is_neg == other.is_neg) {
            return bigint(is_neg, sum(*this, other), shift);
        } else {
            if (*this < other) {
                return bigint(other.is_neg, sub(other, *this), shift);
            } else {
                return bigint(is_neg, sub(*this, other), shift);
            }
        }
    }

    void debug() const {
        cout << "With shift " << shift << '\n';
        if (is_neg) cout << "-";
        for (int x : digits) {
            cout << x;
        }

        cout << '\n';
    }

    void to_string() const {
        string res;
        bool has_dec = false;
        for (int i = 0; i < digits.size(); ++i) {
            if (i + shift == digits.size()) {
                res.push_back(',');
                has_dec = true;
            }
            res.push_back('0' + digits[i]);
        }

        while (!res.empty() and res[0] == '0')
            res = res.substr(1);
        while (has_dec and !res.empty() and res.back() == '0')
            res.pop_back();

        if (!res.empty() and res.back() == ',')
            res.pop_back();

        if (!res.empty() and res[0] == ',') {
            res = "0" + res;
        }

        if (is_neg and !res.empty()) cout << "-";
        cout << (res.empty() ? "0" : res) << '\n';
    }

    bool operator<(const bigint& other) const {
        assert(shift == other.shift);
        if (digits.size() == other.digits.size()) {
            return digits < other.digits;
        } else {
            return digits.size() < other.digits.size();
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q;
    cin >> q;

    string word;
    vector<bigint> vals;

    while (q-- > 0) {
        cin >> word;
        bigint cur(word);
        vals.push_back(cur);
    }

    bigint res("0");
    for (bigint& b : vals) {
        int max_shift = max(res.shift, b.shift);
        res.shift_up(max_shift - res.shift);
        b.shift_up(max_shift - b.shift);
        // res.debug();
        // b.debug();

        res = res + b;
    }

    res.to_string();

    return 0;
}

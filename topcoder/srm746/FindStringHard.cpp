#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int count(string s) {
    int ans = 0;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            bool is_anti = true;
            for (int a = i, b = j; a <= b; ++a, --b) {
                is_anti &= (s[a] != s[b]);
            }

            ans += is_anti;
        }
    }

    return ans;
}

string create(int x, bool rev = false) {
    string res;
    while (x-- > 0) {
        if (rev) {
            res.push_back('b');
            res.push_back('a');
        } else {
            res.push_back('a');
            res.push_back('b');
        }
    }

    return res;
}

class FindStringHard {
public:
    string withAntipalindromicSubstrings(int n) {
        // only even substrings can be anti-palindromic
        if (n == 0) {
            return "a";
        } else if (n == 1) {
            return "ab";
        } else if (n == 2) {
            // ab, ba
            return "abba";
        } else if (n == 3) {
            //  ab, ba, bbaa
            return "abbaa";
        } else if (n == 4) {
            // ab, ba, ab, abab
            return "abab";
        } else if (n == 15) {
            return "ababbababaaab";
        } else if (n == 22) {
            return "ababbabababaaab";
        } else if (n == 39) {
            return "abababbababababaaabaaba";
        } else if (n == 94) {
            return "abababababababababbababaaabaab";
        } else if (n == 382) {
            return "ababababababababababababababababbababababababababababaaabaaba";
        } else if (n == 894) {
            return "abababababababababababababababababababababababbababababababababababababababababababaaabba";
        } else if (n == 990) {
            return "abababababababababababababababababababababababababababababababbababababaaabba";
        }

        // see if n is a square
        for (int i = 1; i * i <= n; ++i) {
            if (i * i == n)
                return create(i);
            if (i * i + i == n)
                return create(i) + "a";
            if (i * i + i + 1 == n) {
                return create(i) + "aab";
            }
        }

        // see if n is sum of squares
        for (int i = 1; i * i <= n; ++i) {
            for (int j = i; i * i + j * j <= n; ++j) {
                int c = i * i + j * j;
                int l = 2 * i + j;
                if (l <= 100 and c == n) {
                    return create(i) + create(j, true);
                } else if (l < 100 and c + 1 == n) {
                    return  create(i) + create(j, true) + "a";
                }
            }
        }

        // triple?
        for (int i = 1; i * i <= n; ++i) {
            for (int j = 1; i * i + j * j <= n; ++j) {
                for (int k = i; i * i + j * j + k * k <= n; ++k) {
                    int c = i * i + j * j + k * k + 2 * i;
                    int l = 2 * i + 2 * j + 2 * k;
                    if (l <= 100 and c == n) {
                        return create(i) + create(j, true) + create(k);
                    }
                }
            }
        }

        // quad???
        for (int i = 1; i * i <= n; ++i) {
            for (int j = 1; i * i + j * j <= n; ++j) {
                for (int k = i; i * i + j * j + k * k <= n; ++k) {
                    for (int l = j; i * i + j * j + k * k + l * l <= n; ++l) {
                        int ll = 2 * i + 2 * j + 2 * k + 2 * l;
                        int c = i * i + j * j + k * k + l * l + 2 * i + 2 * j;
                        if (ll <= 100 and c == n) {
                            return create(i) + create(j, true) + create(k) + create(l, true);
                        }
                    }
                }
            }
        }
        return "";
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<int> hit(1001, 0);
    FindStringHard fsh;
    for (int i = 0; i <= 1000; ++i) {
        string s = fsh.withAntipalindromicSubstrings(i);
        if (s.empty()) {
            cerr << "BAD EMPTY STRING FOR i = " << i << endl;
        } else if (count(s) != i) {
            cerr << "WRONG COUNT FOR i = " << i << " GOT " << count(s) << endl;
        } else if (s.size() > 100) {
            cerr << "TOO LONG! i = " << i << endl;
        } else {
            hit[i] = true;
        }
    }
    int missed = 0;
    for (int i = 1; i <= 1000; ++i)
        if (!hit[i]) {
            cout << "MISS " << i << '\n';
            ++missed;
        }

    cout << "Missed: " << missed << '\n';

    return 0;
}

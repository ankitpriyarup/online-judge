#include <bits/stdc++.h>

using namespace std;
using H = unsigned long long;

constexpr int MAXN = 3e6 + 6;
constexpr int MAXM = 1e5 + 5;

inline bool is_vowel(char c) {
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

string words[MAXM];
string vowel_free[MAXM];
int scores[MAXM];

int n;
string no_vowels;
// bes
int dp[MAXN];
int word[MAXN];

namespace Hasher {
    // MOd 2^64. We should probably try and break this with Thue-Morse.
    H B = 97;

    H prefixes[MAXN];
    H powers[MAXN];

    void init() {
        //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
        //B = uniform_int_distribution<int>(30, 60)(rng);
        //B = 2 * B + 1;
        B = 97;
    }

    H hash(const string& s) {
        H res = 0;
        for (char c : s) {
            res = res * B + c;
        }

        return res;
    }

    void load(const string& s) {
        powers[0] = 1;
        for (int i = 0; i < s.size(); ++i) {
            prefixes[i + 1] = prefixes[i] * B + s[i];
            powers[i + 1] = powers[i] * B;
        }
    }

    // hash [a, b)
    H get_hash(int a, int b) {
        return prefixes[b] - prefixes[a] * powers[b - a];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int m;
    cin >> m;

    // all possible valid lengths
    vector<int> lengths(m);

    // hash -> (score, id)
    unordered_map<H, pair<int, int>> dict;
    Hasher::init();

    // read and parse the input. Save vowel free versions of all strings
    for (int i = 0; i < m; ++i) {
        cin >> words[i];
        for (char c : words[i]) {
            if (is_vowel(c)) {
                ++scores[i];
            } else {
                vowel_free[i].push_back(c);
            }
        }

        lengths[i] = vowel_free[i].size();
        H h = Hasher::hash(vowel_free[i]);
        dict[h] = max(dict[h], make_pair(scores[i], i));
    }

    // only get unique lengths
    sort(begin(lengths), end(lengths));
    lengths.erase(unique(begin(lengths), end(lengths)), end(lengths));

    cin >> no_vowels;
    n = no_vowels.size();

    Hasher::load(no_vowels);

    memset(dp, -1, sizeof(dp));
    memset(word, -1, sizeof(word));
    word[n] = 0;
    dp[n] = 0;
    for (int i = n - 1; i >= 0; --i) {
        for (int length : lengths) {
            if (i + length > n) {
                break;
            }
            H hash = Hasher::get_hash(i, i + length);
            auto it = dict.find(hash);
            if (it == end(dict)) {
                continue;
            }

            int score, id;
            tie(score, id) = it->second;

            int new_val = dp[i + length] + score;
            if (word[i + length] >= 0 and new_val > dp[i]) {
                dp[i] = new_val;
                word[i] = id;
            }
        }
    }

    int ptr = 0;
    while (ptr < n) {
        cout << words[word[ptr]] << ' ';
        ptr += vowel_free[word[ptr]].size();
    }
    cout << '\n';

    return 0;
}

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

    int num_s;
    cin >> num_s;
    vector<string> syllables(num_s);
    for (int i = 0; i < num_s; ++i) {
        cin >> syllables[i];
    }

    bool valid = true;
    vector<int> goal = {5, 7, 5};

    string line;
    getline(cin, line);
    for (int j = 0; j < 3; ++j) {
        getline(cin, line);
        istringstream iss(line);
        bitset<8> poss;
        poss[0] = 1;
        string word;
        while (iss >> word) {
            int m = word.size();
            vector<vector<int>> dp(m + 1, vector<int>(8, 0));
            dp[m][0] = 1;
            for (int i = m - 1; i >= 0; --i) {
                for (const string& s : syllables) {
                    if (i + s.size() > m)
                        continue;
                    if (word.substr(i, s.size()) == s) {
                        for (int k = 0; k + 1 < 8; ++k) {
                            dp[i][k + 1] |= dp[i + s.size()][k];
                        }
                    }
                }
            }

            bitset<8> new_poss;
            for (int k = 0; k < 8; ++k) {
                if (dp[0][k]) {
                    new_poss |= (poss << k);
                }
            }

            poss = new_poss;
        }

        valid &= poss[goal[j]];
    }

    if (valid) {
        cout << "haiku\n";
    } else {
        cout << "come back next year\n";
    }
    
    return 0;
}

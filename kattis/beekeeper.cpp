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

bool isv(char c) {
    return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or c == 'y';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    while (cin >> n) {
        if (n == 0) break;
        string best_word = "";
        int score = -1;
        string word;
        while (n-- > 0) {
            cin >> word;
            int cur_score = 0;
            for (int i = 1; i < word.size(); ++i) {
                if (isv(word[i]) and word[i - 1] == word[i]) {
                    ++cur_score;
                }
            }

            // cout << word << ' ' << cur_score << '\n';

            if (cur_score > score) {
                score = cur_score;
                best_word = word;
            }
        }

        cout << best_word << '\n';
    }
    
    return 0;
}

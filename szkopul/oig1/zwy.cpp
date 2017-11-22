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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    scanf("%d", &n);
    int max_score = -1003;
    string ans = "";
    int score;
    for (int i = 0; i < n; ++i) {
        char c = 'A' + i;
        scanf("%d", &score);
        if (score > max_score) {
            max_score = score;
            ans = "";
        }

        if (score == max_score) {
            ans.push_back(c);
        }
    }

    printf("%s\n", ans.c_str());
    
    return 0;
}

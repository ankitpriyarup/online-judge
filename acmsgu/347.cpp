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

string words[103];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> words[i];

    // TODO: if A is a prefix of B, which comes first?
    // A comes first if A + B < B + A, otherwise B comes first
    sort(words, words + n, [](const string& a, const string& b) {
        return a + b < b + a;
    });

    for (int i = 0; i < n; ++i)
        cout << words[i];
    
    return 0;
}

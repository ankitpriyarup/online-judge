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

int n;

bool cmp(const string& a, const string& b) {
    if (a.size() == b.size()) {
        return a < b;
    }

    return a.size() < b.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    string s;
    vector<string> v;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        v.push_back(s);
    }
    sort(begin(v), end(v), cmp);

    for (int i = 0; i < n; ++i) {
        cout << v[i] << '\n';
    }
    
    return 0;
}

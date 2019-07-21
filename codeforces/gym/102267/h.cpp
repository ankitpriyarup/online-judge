#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr double PI = 3.14159265358979323;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int v, s;
    cin >> v >> s;
    double theta = 2.0 * PI / v;
    double phi = PI * (v - 2) / v;

    // a / sinA = b / sinB
    double side = s * sin(phi / 2.0) / sin(theta);

    cout << fixed << setprecision(10) << (PI * side * side) << '\n';
    
    return 0;
}

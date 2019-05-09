#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int m;
    while (cin >> m) {
        if (m == 0) break;

        vi widths = {0};
        vi heights = {0};

        int w, h;
        while (cin >> w >> h) {
            if (w == -1 and h == -1) break;
            if (widths.back() + w > m) {
                widths.push_back(0);
                heights.push_back(0);
            }
            widths.back() += w;
            heights.back() = max(heights.back(), h);
        }

        int max_w = *max_element(all(widths));
        int tot_h = accumulate(all(heights), 0);
        
        cout << max_w << " x " << tot_h << '\n';
    }
    
    return 0;
}

#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int main() {
    long long n;
    int k;

    cin >> n >> k;
    vector<long long> div;
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            div.push_back(i);

            long long ni = n / i;
            if (i != ni) {
                div.push_back(ni);
            }
        }
    }

    sort(div.begin(), div.end());

    if (k <= div.size()) {
        cout << div[k - 1] << '\n';
    } else {
        cout << -1 << '\n';
    }

    return 0;
}

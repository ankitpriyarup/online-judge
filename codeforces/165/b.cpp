#include <iostream>

using namespace std;
int n, k;

bool works(int v) {
    int code_lines = v;
    for (int power = k; v / power > 0; power *= k) {
        code_lines += v / power;
    }
    return code_lines >= n;
}

int main() {
    cin >> n >> k;

    int lo = 0;
    int hi = 1000000000;

    while(lo + 1 < hi) {
        int mid = (lo + hi) >> 1;
        if (works(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    cout << hi << '\n';
    return 0;
}

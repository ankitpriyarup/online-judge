#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, k;
string s;

bool works(int size) {
    //cout << "Trying " << size << '\n';
    int ac = 0;
    int bc = 0;
    for (int i = 0; i < size; ++i) {
        if (s[i] == 'a') ++ac;
        else ++bc;
    }
    if (ac <= k || bc <= k) {
        //cout << "First chars match" << '\n';
        return true;
    }


    for (int i = size; i < n; ++i) {
        if (s[i - size] == 'a') --ac;
        else --bc;

        if (s[i] == 'a') ++ac;
        else ++bc;
        if (ac <= k || bc <= k) {
            //cout << "Match at " << i << '\n';
            return true;
        }
    }

    return false;
}

int main() {
    cin >> n >> k;
    cin >> s;
    if (works(n)) {
        cout << n << '\n';
    } else {
        int lo = 0;
        int hi = n;
        while (lo + 1 < hi) {
            int mid = (lo + hi) / 2;
            if (works(mid)) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        cout << lo << '\n';
    }
    return 0;
}

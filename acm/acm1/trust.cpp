#include <iostream>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

int T, N, M, X, Y;
int main() {
    cin >> T;
    for (int case_num = 0; case_num < T; case_num++) {
        cin >> N >> M >> X >> Y;
        if (M < N * X) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}

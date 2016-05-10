#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <utility>

using namespace std;

int N, P;
int B[100005];

int main() {
    int T;
    cin >> T;
    for (int case_num = 1; case_num <= T; case_num++) {
        cin >> N >> P;

        for (int i = 0; i < N; ++i) {
            cin >> B[i];
        }

        int start = 0;
        long long cur = 0;
        
        long long ans = 0;
        for (int end = 1; end <= N; ++end) {
            cur += B[end - 1];
            while (start < end and cur > P) {
                cur -= B[start];
                start++;
            }

            ans += end - start;
        }

        cout << "Case #" << case_num << ": " << ans << '\n';
    }

    return 0;
}

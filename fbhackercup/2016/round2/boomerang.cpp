#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#include <utility>

using namespace std;

int N;
string A, B;
int dpl[100005];
int dpr[100005];

int main() {
    int T;
    cin >> T;
    for (int case_num = 1; case_num <= T; ++case_num) {
        cin >> N;
        cin >> A >> B;
        dpl[0] = (A[0] == B[0]) ? 0 : 1;
        int changes = 0;
        for (int i = 1; i < N; ++i) {
            changes +=  B[i] == B[i - 1] ? 0 : 1;
            if (B[i] == A[i]) {
                dpl[i] = dpl[i - 1];
            } else {
                dpl[i] = 1 + changes;
            }
        }

        dpr[N - 1] = (A[N - 1] == B[N - 1]) ? 0 : 1;
        changes = 0;
        for (int i = N - 2; i >= 0; --i) {
            changes += B[i] == B[i + 1] ? 0 : 1;
            if (B[i] == A[i]) {
                dpr[i] = dpr[i + 1];
            } else {
                dpr[i] = 1 + changes;
            }
        }

        int ans = min(dpl[N - 1], dpr[0]);
        for (int i = 0; i < N - 1; ++i) {
            ans = min(ans, max(dpl[i], dpr[i + 1]));
        }

        cout << "Case #" << case_num << ": " << ans << '\n';
    }
    return 0;
}

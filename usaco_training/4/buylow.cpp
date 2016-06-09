/*
ID: rednano1
PROG: buylow
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <set>
#include <utility>

using namespace std;

int n;
int a[5003];
// length of the LDS ending here
int dp1[5003];
// Number of ways to get to an LDS of maximum length ending here.
int dp2[5003];

int main() {
    ifstream fin("buylow.in");
    ofstream fout("buylow.out");

    fin >> n;
    for (int i = 0; i < n; ++i) {
        fin >> a[i];
    }
    fin.close();

    int best_length = 1;
    memset(dp1, 0, sizeof(dp1));
    memset(dp2, 0, sizeof(dp2));

    for (int i = 0; i < n; ++i) {
        int length = 1;
        int count = 1;
        set<int> prev_val;
        for (int j = i - 1; j >= 0; --j) {
            if (a[i] < a[j] and length < dp1[j] + 1) {
                length = dp1[j] + 1;
                count = dp2[j];
                prev_val.clear();
                prev_val.insert(a[j]);
            } else if (a[i] < a[j] and length == dp1[j] + 1 and prev_val.find(a[j]) == prev_val.end()) {
                cout << i << " " << j << " " << count << " " <<  dp2[j] << '\n';
                count += dp2[j];
                prev_val.insert(a[j]);
            }

            cout << i << ' ' << j << ' ' << count << '\n';
        }

        dp1[i] = length;
        dp2[i] = count;
        best_length = max(best_length, length);
    }

    long long total_count = 0LL;
    set<int> last;
    for (int i = n - 1; i >= 0; --i) {
        if (dp1[i] == best_length && last.find(a[i]) == last.end()) {
            total_count += dp2[i];
            last.insert(a[i]);
        }
    }

    fout << best_length << ' ' << total_count << '\n';
    fout.close();

    for (int i = 0; i < n; ++i)
        cout << a[i] << ' ';
    cout << '\n';

    for (int i = 0; i < n; ++i)
        cout << dp1[i] << ' ';
    cout << '\n';

    for (int i = 0; i < n; ++i)
        cout << dp2[i] << ' ';
    cout << '\n';
    return 0;
}

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

const int MAXN = 100005;
const int K = 4;

int n;
int top[MAXN], bottom[MAXN], inverse[MAXN];

int dp[MAXN];
int lis_len = 0;

int main() {
    ifstream fin("nocross.in");
    ofstream fout("nocross.out");

    fin >> n;
    for (int i = 1; i <= n; ++i) {
        fin >> top[i];
        inverse[top[i]] = i;
    }

    for (int i = 1; i <= n; ++i) {
        fin >> bottom[i];
    }

    lis_len = 0;
    memset(dp, 0, sizeof(dp));
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        int cur = bottom[i];
        vector<int> inds;
        for (int j = min(n, cur + K); j >= max(1, cur - K); --j) {
            // find the index of j on the top bank
            inds.push_back(inverse[j]);
        }


        // iterate from furthest right bridge to furthest left to avoid
        // counting multiple bridges from the same source
        sort(inds.begin(), inds.end());
        for (int j = inds.size() - 1; j >= 0; --j) {
            int top_ind = inds[j];
            if (top_ind > dp[lis_len]) {
                // See if you can append it to the end
                ++lis_len;
                dp[lis_len] = top_ind;
            } else if (top_ind < dp[1]){
                // See if this is the furthest left so far
                dp[1] = top_ind;
            } else if (top_ind == dp[1]) {
                continue;
            } else {
                // find the largest x such that dp[x] < top_ind
                int lo = 1;
                int hi = lis_len;

                while (lo + 1 < hi) {
                    int mid = lo + (hi - lo) / 2;
                    if (dp[mid] < top_ind) {
                        lo = mid;
                    } else {
                        hi = mid;
                    }
                }

                dp[hi] = top_ind;
            }
        }
    }

    fout << lis_len << '\n';
    return 0;
}

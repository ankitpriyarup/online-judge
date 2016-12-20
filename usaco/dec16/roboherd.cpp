/**
 * Brute force. Runs too slowly
 */

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

int n, k;

int main() {
    ifstream fin("roboherd.in");
    ofstream fout("roboherd.out");

    fin >> n >> k;

    int m;
    long long x;
    fin >> m;

    vector<long long> candidates;
    for (int i = 0; i < m; ++i) {
        fin >> x;
        candidates.push_back(x);
    }

    sort(candidates.begin(), candidates.end());

    // O(n * m * k) = TOO SLOW :(
    for (int i = 1; i < n; ++i) {
        fin >> m;
        vector<long long> new_candidates;

        for (int j = 0; j < m; ++j) {
            fin >> x;

            for (size_t l = 0; l < candidates.size(); ++l) {
                new_candidates.push_back(x + candidates[l]);
            }
        }

        sort(new_candidates.begin(), new_candidates.end());

        if ((int) new_candidates.size() > k) {
            new_candidates.resize(k);
        }

        candidates = new_candidates;
    }
    fin.close();

    long long ans = 0LL;
    for (long long x : candidates) {
        ans += x;
    }

    fout << ans << '\n';
    fout.close();

    return 0;
}

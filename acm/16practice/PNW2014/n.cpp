#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main() {
    int T, x;
    cin >> T;

    int V;
    while (T-- > 0) {
        cin >> V;
        map<int, int> freq;
        for (int i = 0; i < V; ++i) {
            cin >> x;
            freq[x]++;
        }

        int bestValue = -1;
        int bestCount = 0;

        for (auto it = freq.begin(); it != freq.end(); ++it) {
            if (it->second > bestCount) {
                bestValue = it->first;
                bestCount = it->second;
            } else if (it->second == bestCount) {
                bestValue = min(it->first, bestValue);
            }
        }

        cout << bestValue << '\n';
    }
    return 0;
}

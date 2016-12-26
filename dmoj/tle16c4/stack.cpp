#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int n;
int w[100005];
long long best_of_size[100005];
const long long INF = 1e15;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        best_of_size[i] = INF;
    }
    sort(w, w + n);

    best_of_size[1] = w[0];
    int ans = 1;
    int biggest_pile = 1;
    for (int i = 1; i < n; ++i) {
        if (w[i] <= best_of_size[1]) {
            best_of_size[1] = w[i];
        } else if (w[i] >= best_of_size[biggest_pile]) {
            best_of_size[biggest_pile + 1] = best_of_size[biggest_pile] + w[i];
            ++biggest_pile;
        } else {
            int lo = 1;
            int hi = biggest_pile;
            while (lo + 1 < hi) {
                int mid = lo + (hi - lo) / 2;
                if (w[i] >= best_of_size[mid]) {
                    lo = mid;
                } else {
                    hi = mid;
                }
            }

            best_of_size[lo + 1] = min(best_of_size[lo + 1], w[i] + best_of_size[lo]);
        }
    }

    cout << biggest_pile << '\n';

    return 0;
}

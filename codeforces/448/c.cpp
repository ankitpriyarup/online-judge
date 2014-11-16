#include <iostream>
#include <algorithm>

using namespace std;

int N, fence[5005];

int find_min_index(int l, int r) {
    int min_index = l, min_value = fence[l];
    for (int i = l; i <= r; i++) {
        if (fence[i] < min_value) {
            min_index = i;
            min_value = fence[i];
        }
    }

    return min_index;
}

int solve(int l, int r, int painted) {
    //cout << l << " " << r << '\n';

    if (l > r) {
        return 0;
    }

    int best = r - l + 1;
    int min_index = find_min_index(l, r);
    //cout << "min_index: " << min_index << '\n';

    best = min(best, fence[min_index] - painted + solve(l, min_index - 1, fence[min_index]) + solve(min_index + 1, r, fence[min_index]));
    return best;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> fence[i];
    }
    cout << solve(0, N - 1, 0) << '\n';
    return 0;
}

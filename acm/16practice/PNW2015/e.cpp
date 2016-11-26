#include <iostream>
#include <cstring>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> scores;

int main() {
    cin >> n;

    int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        scores.push_back(x);
    }

    sort(scores.begin(), scores.end());

    int start = 0;
    int end = n - 1;
    int worstTeam = 0x3f3f3f3f;
    while (start < end) {
        worstTeam = min(worstTeam, scores[start] + scores[end]);
        ++start;
        --end;
    }

    cout << worstTeam << '\n';
    return 0;
}

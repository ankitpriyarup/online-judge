#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <queue>
#include <vector>
#define MAXC 200005

using namespace std;

int C, P, X, L;

int total_partners[MAXC];
int remaining_partners[MAXC];
bool has_left[MAXC];
vector<int> graph[MAXC];

int main() {
    cin >> C >> P >> X >> L;
    --X;
    --L;

    memset(total_partners, 0, sizeof(total_partners));
    memset(remaining_partners, 0, sizeof(remaining_partners));
    memset(has_left, 0, sizeof(has_left));
    int A, B;
    for (int i = 0; i < P; ++i) {
        cin >> A >> B;
        --A;
        --B;

        total_partners[A]++;
        total_partners[B]++;
        remaining_partners[A]++;
        remaining_partners[B]++;

        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    queue<int> leave;
    leave.push(L);
    has_left[L] = true;
    while (!leave.empty()) {
        int bad = leave.front();
        leave.pop();

        if (bad == X) break;

        for (int partner : graph[bad]) {
            if (has_left[partner]) continue;
            remaining_partners[partner]--;
            if (2 * remaining_partners[partner] <= total_partners[partner]) {
                has_left[partner] = true;
                leave.push(partner);
            }
        }
    }

    cout << (has_left[X] ? "leave" : "stay") << '\n';
    return 0;
}

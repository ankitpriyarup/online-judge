#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, t, x, y, z;
int main() {
    cin >> N;
    queue<int> q1;
    queue<int> q2;
    queue<int> q3;

    for (int i = 1; i <= N; i++) {
        cin >> t;
        if (t == 1) {
            q1.push(i);
        } else if (t == 2) {
            q2.push(i);
        } else {
            q3.push(i);
        }
    }

    int min_size = min(q1.size(), min(q2.size(), q3.size()));
    cout << min_size << '\n';

    while (!q1.empty() && !q2.empty() && !q3.empty()) {
        x = q1.front();
        y = q2.front();
        z = q3.front();
        q1.pop();
        q2.pop();
        q3.pop();
        
        cout << x << " " << y << " " << z << '\n';
    }

    return 0;
}

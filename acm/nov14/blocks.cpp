#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>

using namespace std;

int T, N;
int want[1000000];

int main() {
    cin >> T;
    while (T-- > 0) {
        cin >> N;
        for(int i = 0; i < N; i++) {
            cin >> want[i];
            want[i]--;
        }
        // 0 is STACK, 1 is PLACE
        vector<bool> moves;
        stack<int> stak;

        int pos = 0;
        int front = 0;
        bool works = true;
        while (pos < N) {
            if (!stak.empty() && stak.top() == want[pos]) {
                moves.push_back(1);
                stak.pop();
                pos++;
            } else {
                if (front < N) {
                    moves.push_back(0);
                    stak.push(front);
                    front++;
                } else {
                    works = false;
                    break;
                }
            }
        }

        if (works) {
            cout << "YES" << '\n';    
            for (auto it=moves.begin(); it != moves.end(); it++) {
                cout << (*it ? "PLACE" : "STACK") << '\n';
            }
        } else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}

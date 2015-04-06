#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <forward_list>
#include <queue>
#include <set>
#include <map>

using namespace std;

int N, M;
int w[505];
bool used[505];
int b[1001];
forward_list<int> stack;
forward_list<int>::iterator it;
/*void printlist() {
    cout << "stack contains:";
    for (int& x: stack) cout << ' ' << x;
    cout << '\n';
}*/

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> w[i];
        used[i] = false;
    }

    //printlist();
    for (int i = 0; i < M; i++) {
        cin >> b[i];
        b[i]--;

        if (!used[b[i]]) {
            if (stack.empty()) {
                it = stack.insert_after(stack.before_begin(), b[i]);
            } else {
                it = stack.insert_after(it, b[i]);
            }
            used[b[i]] = true;
        }
    }
    //printlist();

    long long ans = 0LL;
    for (int i = 0; i < M; i++) {
        forward_list<int>::iterator prev = stack.before_begin();
        it = stack.begin();
        //cout << "Looking for " << b[i] << '\n';
        while (*it != b[i]) {
            ans += w[*it];
            it++;
            prev++;
        }
        stack.erase_after(prev);
        stack.push_front(b[i]);
    }

    cout << ans << '\n';
    return 0;
}

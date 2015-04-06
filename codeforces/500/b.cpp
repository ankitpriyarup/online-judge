#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

int N;
int p[303];
char A[303][303];
bool visited[303];
priority_queue<int> positions;
priority_queue<int> values;

void dfs(int x) {
    positions.push(x);
    values.push(p[x]);
    visited[x] = true;
    for (int i = 0; i < N; i++) {
        if (A[i][x] == '1' && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> p[i];
        visited[i] = false;
    }

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int pos, val;
    //int counter = 0;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            dfs(i);
            //cout << "COUNTER: " << counter << '\n';
            //counter++;

            while (!positions.empty()) {
                pos = positions.top();
                positions.pop();

                val = values.top();
                values.pop();
                //cout << "POS: " << pos << " VAL: " << val << '\n';
                p[pos] = val;
            }
        }
    }

    cout << p[0];
    for (int i = 1; i < N; i++) {
        cout << " " << p[i];
    }
    cout << '\n';
    return 0;
}

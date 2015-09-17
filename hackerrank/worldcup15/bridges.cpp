#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int T, N, Y[50005], subgraph[50005];
    cin >> T;
    while (T-- > 0) {
        cin >> N;
        for (int i = 0; i < N; ++i) {
            cin >> Y[i];
            Y[i]--;
        }

        memset(subgraph, -1, sizeof(subgraph));
        int max_comp = 0;
        int j;
        for (int i = 0; i < N; ++i) {
            if (subgraph[i] != -1) {
                continue;
            }

            j = i;
            while (subgraph[j] == -1) {
                subgraph[j] = max_comp;
                j = Y[j];
            }

            max_comp += 1;
        }

        /*
        for (int i = 0; i < N; ++i) {
            cout << subgraph[i] << ' ';
        }
        */

        cout << (max_comp - 1) << '\n';
    }

    return 0;
}

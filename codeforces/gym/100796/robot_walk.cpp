#include <iostream>

using namespace std;

int main() {
    int N, M, X;
    string S, P;
    cin >> N >> X >> S >> M >> P;

    X--;
    cout << S[X];
    for (int i = 0; i < M; ++i) {
        X += (P[i] == 'R' ? 1 : -1);
        cout << S[X];
    }
    cout << '\n';

    return 0;
}

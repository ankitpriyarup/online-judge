#include <iostream>

using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;
    int smilies = 0;
    int frownies = 0;
    for (int i = 0; i < N; ++i) {
        if (S[i] == ':') {
            if (i > 0 && S[i - 1] == ')') {
                frownies++;
            } else if (i > 0 && S[i - 1] == '(') {
                smilies++;
            }

            if (i < N - 1 && S[i + 1] == '(') {
                frownies++;
            } else if (i < N - 1 && S[i + 1] == ')') {
                smilies++;
            }
        }
    }

    if (frownies == smilies) {
        cout << "BORED\n";
    } else if (frownies > smilies) {
        cout << "SAD\n";
    } else {
        cout << "HAPPY\n";
    }
    return 0;
}

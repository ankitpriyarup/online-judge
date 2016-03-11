#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;

    string s;
    while (T-- > 0) {
        cin >> s;
        int shift = 0;
        int N = s.size();

        for (int i = 0; i < N; ++i) {
            if (!((i > 0 && s[i] == s[i - 1]) || (i < N - 1 && s[i] == s[i + 1]))) {
                ++shift;    
            }
        }

        cout << (1LL << shift) << '\n';
    }
    return 0;
}

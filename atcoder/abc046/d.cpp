#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int win = 0;
    int loss = 0;
    for (int i = 0; i < n; ++i) {
        bool my_paper = i & 1;
        if (!my_paper && s[i] == 'p') {
            ++loss;
        } else if (my_paper && s[i] == 'g') {
            ++win;
        }
    }

    cout << (win - loss) << '\n';
}

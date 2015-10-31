#include <iostream>

using namespace std;

int main() {
    int N;
    string s;
    cin >> N;
    while (N-- > 0) {
        cin >> s;

        if (s == "Dropbox") {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

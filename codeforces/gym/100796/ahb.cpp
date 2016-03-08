#include <iostream>
#include <string>

using namespace std;

int main() {
    string A, B;
    bool print = false;
    cin >> A >> B;

    for (int i = 0; A[i] != '\0'; ++i) {
        int d = abs(A[i] - B[i]);
        if (d != 0) {
            print = true;
        }

        if (print) {
            cout << d;
        }
    }

    if (!print) {
        cout << '0' << '\n';
    }

    cout << '\n';
    return 0;
}

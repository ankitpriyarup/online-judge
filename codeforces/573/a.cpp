#include <iostream>

using namespace std;

int a[100005];

int main() {
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        while (a[i] % 2 == 0) {
            a[i] /= 2;
        }

        while (a[i] % 3 == 0) {
            a[i] /= 3;
        }
    }

    for (int i = 1; i < N; i++) {
        if (a[i] != a[0]) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}

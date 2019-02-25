#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T-- > 0) {
        int a, b;
        cin >> a >> b;
        int n;
        cin >> n;
        ++b;
        while (a + 1 < b) {
            int m = a + ((b - a) >> 1);
            cout << m << endl;
            cout.flush();
            string resp;
            cin >> resp;
            if (resp == "CORRECT") {
                a = b;
                break;
            } else if (resp == "TOO_SMALL") {
                a = m;
            } else {
                b = m;
            }
        }
    }
    return 0;
}

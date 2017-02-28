#include <iostream>

using namespace std;

int main() {
    int num_cases;
    cin >> num_cases;

    int n, m;
    while (num_cases-- > 0) {
        cin >> n >> m;

        bool direct_path = false;
        int x, y;
        for (int i = 0; i < m; ++i) {
            cin >> x >> y;
            direct_path |= (x == 1) and (y == n);
        }

        cout << (direct_path ? "Jorah Mormont" : "Khal Drogo") << '\n';
    }

    return 0;
}

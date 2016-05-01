#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int x = 1;
    int y = 1;
    vector<int> tube;
    for (int cell = 0; cell < n * m; ++cell) {
        if (k > 1 and tube.size() >= 4) {
            cout << (tube.size() / 2);
            for (int x : tube) {
                cout << ' ' << x;
            }
            cout << '\n';
            tube.clear();
            --k;
        }

        //cout << x << ' ' << y << '\n';
        tube.push_back(x);
        tube.push_back(y);
        if (x % 2 == 1 and y == m)
            ++x;
        else if (x % 2 == 0 and y == 1)
            ++x;
        else if (x % 2 == 1)
            ++y;
        else
            --y;
    }

    cout << (tube.size() / 2);
    for (int x : tube) {
        cout << ' ' << x;
    }
    cout << '\n';
    return 0;
}

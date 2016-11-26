#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    int V, E;
    while (T-- > 0) {
        cin >> V >> E;
        cout << (2 - V + E) << '\n';
    }
    return 0;
}

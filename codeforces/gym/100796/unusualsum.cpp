#include <iostream>
#include <iomanip>

using namespace std;

double S(long long x) {
    if (x < 0LL)
        return 0.0;

    return x/(x + 1.0L);
}

int main() {
    int N;
    long long L, R;

    cin >> N;
    cout << setprecision(15);
    for (int i = 0; i < N; ++i) {
        cin >> L >> R;
        cout << (S(R) - S(L - 1)) << '\n';
    }

    return 0;
}

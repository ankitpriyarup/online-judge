#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int a[1001];
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(a, a + N);
    reverse(a, a + N);
    int count = 0;
    while (M > 0) {
        M -= a[count];
        count++;
    }

    cout << count << '\n';
    return 0;
}

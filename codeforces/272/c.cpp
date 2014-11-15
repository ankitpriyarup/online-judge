#include <iostream>
#include <algorithm>
#define MAX_N 100005
using namespace std;

int N, M, w, h;
long long a[MAX_N];
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> w >> h;
        w--; 
        if (w == 0) {
            cout << a[0] << '\n';
            a[0] += h;
        } else {
            int height = max(a[0], a[w]);
            cout << height << '\n';
            a[0] = height + h;
        }
    }
    return 0;
}

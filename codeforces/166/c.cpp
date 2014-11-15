#include <iostream>
#include <algorithm>
#define MAX_N 2000
using namespace std;

int N, X;
int a[MAX_N];

void printArray() {
    cout << a[0];
    for(int i = 1; i < N; i++) {
        cout << " " << a[i];
    }
    cout << '\n';
}

int main() {
    cin >> N >> X;
    bool hasMedian = false;
    for (int i = 0; i < N; i++) { 
        cin >> a[i];
        if (a[i] == X) {
            hasMedian = true;
        }
    }

    int count = 0;
    if (!hasMedian) {
        a[N++] = X;
        count++;
    }

    sort(a, a + N);
    while (a[(N + 1) / 2 - 1] != X) {
        if (a[(N + 1) / 2 - 1] < X) {
            a[N] = 100000;
        } else {
            a[N] = 1;
        }
        count++;
        N++;
        sort(a, a + N);
    }

    cout << count << '\n';
    return 0;
}

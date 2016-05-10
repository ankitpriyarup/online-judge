#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, d;
int a[10004];
int b[30004];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cin >> n >> d;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    memset(b, 0, sizeof(b));
    b[a[n - 1]]++;
    if (n >= 2)
        b[a[n - 2]]++;
    
    long long ans = 0LL;

    for (int i = n - 3; i >= 0; --i) {
        ans += b[a[i] + d] * b[a[i] + 2 * d];
        b[a[i]]++;
    }
    
    cout << ans << '\n';
    return 0;
}

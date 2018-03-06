#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <complex>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    int arr[n];
    for (int i = 0; i < n; ++i)
        arr[i] = i + 1;

    int ptr = 0;
    while (ptr < n) {
        if ((n - ptr) % b == 0) {
            if (b > 1) {
                rotate(arr + ptr, arr + ptr + 1, arr + ptr + b);
            }
            ptr += b;
        } else {
            if (ptr + a > n) {
                printf("%d\n", -1);
                return 0;
            }
            if (a > 1) {
                rotate(arr + ptr, arr + ptr + 1, arr + ptr + a);
            }
            ptr += a;
        }
    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

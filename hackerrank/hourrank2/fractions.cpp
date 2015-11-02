#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>
#include <queue>
#include <set>

using namespace std;

int N;
int a[1002];

int main() {
    cin >> N;
    int maxval = 0;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        maxval = max(maxval, a[i]);
    }

    int s = 0;
    for (int target = maxval; target >= 1; target--) {
        // see if it's possible for all numbers to hit target
        s = 0;
        bool works = true;
        for (int i = 0; i < N; ++i) {
            if (a[i] < target) {
                works = false;
                break;
            }

            int start = a[i] / target;
            while (start > 0 && a[i] / start == target) {
                start--;
            }

            start++;
            if (a[i] / start != target) {
                works = false;
                break;
            }

            s += start;
        }

        if (!works) {
            continue;
        } else {
            break;
        }
    }

    cout << s << '\n';
    return 0;
}

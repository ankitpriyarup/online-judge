#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N;
    while ((cin >> N) && N != 0) {
        vector<int> a;

        int x;
        for (int i = 0; i < N; ++i) {
            cin >> x;
            a.push_back(x);
        }
        sort(a.begin(), a.end());

        string s1 = "";
        string s2 = "";

        // make sure 0 isn't the first digit
        int taken = -2; 
        for (int i = 0; i < N; ++i) {
            if (a[i] != 0) {
                taken = i;
                s1 += ((char)(a[i] + '0'));
                s2 += ((char)(a[i + 1] + '0'));
                break;
            }
        }

        bool last = true;
        for (int i = 0; i < taken; ++i) {
            if (last) {
                s1 += '0';
            } else {
                s2 += '0';
            }

            last = !last;
        }

        for (int i = taken + 2; i < N; ++i) {
            if (last) {
                s1 += ((char)(a[i] + '0'));
            } else {
                s2 += ((char)(a[i] + '0'));
            }

            last = !last;
        }
        cout << (stol(s1) + stol(s2)) << '\n';
    }
}

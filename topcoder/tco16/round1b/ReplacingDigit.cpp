#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class ReplacingDigit {
    public:
        int getMaximumStockWorth(vector<int> A, vector<int> D) {
            vector<int> digits[10];
            int N = A.size();
            long long ans = 0LL;

            for (int i = 0; i < N; ++i) {
                int x = A[i];
                ans += x;

                int p = 0;
                while (x > 0) {
                    digits[p].push_back(x % 10);
                    x /= 10;
                    ++p;
                }
            }

            for (int i = 0; i < 10; ++i) {
                sort(digits[i].begin(), digits[i].end());
            }


            for (int x = 9; x >= 1; --x) {
                if (D[x - 1] <= 0) continue;

                for (int p = 8, pow = 100000000; p >= 0; p--, pow /= 10) {
                    int S = digits[p].size();

                    for (int i = 0; D[x - 1] && i < S; ++i) {
                        if (digits[p][i] < x) {
                            ans += pow * (x - digits[p][i]);
                            digits[p][i] = x;
                            D[x - 1]--;
                        }
                    }
                }
            }

            return ans;
        }
};

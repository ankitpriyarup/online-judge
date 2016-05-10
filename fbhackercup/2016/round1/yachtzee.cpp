#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <utility>

using namespace std;

int N, A, B;
long long C[100005];

/*
 * Let E be the expected value from 0 to T, where T is the time for building a
 * single yacht. Calculating this is simple. To calculate the expected value
 * between A and B, find the smallest multiple of T larger than or equal to A,
 * and take full blocks until B. Then handle the edges appropriately. Should be
 * a O(3N) = O(N) solution.
 */

/*
 * To find the expected value of a single yacht, consider that there are N
 * segments, each with cost Ci and the sum over all Ci = S.
 *
 * Expected value = Sum over all i of Ci / 2 * Ci / S = Ci^2 / 2S.
 *
 * E = Sigma(Ci^2) / 2S.
 */

long double find_ev(long long start, long long end) {
    long long pos = 0;
    long double ev = 0;
    long double denom = 2.0L * (end - start);

    for (int i = 0; i < N and pos <= end; ++i) {
        long long seg_start = max(pos, start);
        long long seg_end = min(end, pos + C[i]);
        
        long long y_start = seg_start - pos;
        long long y_end = seg_end - pos;

        pos += C[i];

        /*
        cout << "seg_start " << seg_start << '\n';
        cout << "seg_end " << seg_end << '\n';
        cout << "y_start " << y_start << '\n';
        cout << "y_end " << y_end << '\n';
        */

        if (seg_end <= seg_start or seg_start >= end) {
            continue;
        }

        ev += (y_end + y_start) * (seg_end - seg_start) / denom;
    }

    return ev;
}

int main() {
    int T;
    cin >> T;
    for (int case_num = 1; case_num <= T; ++case_num) {
        cin >> N >> A >> B;
        long double block_ev = 0;
        long long block_size = 0;
        for (int i = 0; i < N; ++i) {
            cin >> C[i];
            block_size += C[i];
            block_ev += C[i] * C[i];
        }

        block_ev /= 2.0L;
        block_ev /= block_size;

        // Find the smallest multiple of block_size larger than A
        long double total_width = B - A;
        long double ans;

        if (total_width <= block_size) {
            long long offset = (A / block_size) * block_size;
            ans = find_ev(A - offset, B - offset);
        } else {
            long long A_prime = (A / block_size + 1) * block_size;
            long long B_prime = (B / block_size) * block_size;
            ans = B_prime > A_prime ? block_ev * (B_prime - A_prime) / total_width : 0;

            if (A % block_size != 0) {
                long long K = A / block_size;
                long double ev = find_ev(A - K * block_size, block_size);
                ans += ev * ((K + 1) * block_size - A)/ total_width;
            }

            if (B % block_size != 0) {
                long long K = B / block_size;
                long double ev = find_ev(0, B - K * block_size);
                ans += ev * (B - K * block_size) / total_width;
            }
        }

        printf("Case #%d: %.09Lf\n", case_num, ans);
    }
    return 0;
}

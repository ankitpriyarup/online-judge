#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;

    while ((cin >> N) && N != 0) {
        cin >> K;
        vector<long long> scores(N, 0LL);

        int start = 0;
        while (true) {
            int rem = K % N;
            int div = K / N;

            for (int i = 0; i < rem; ++i) {
                scores[(start + i) % N] += div + 1;
            }

            for (int i = rem; i < N; ++i) {
                scores[(start + i) % N] += div;
            }

            /*
            for (auto it = scores.begin(); it != scores.end(); ++it) {
                cout << " " << *it;
            }
            cout << " | start: " << start << '\n';
            */
 
            int elim = (start + rem - 1 + N) % N;
            //cout << "erasing index " << elim << '\n';
            scores.erase(scores.begin() + elim);
            N--;

            // check if they're all equal
            int score0 = scores[0];
            bool done = true;
            for (int i = 0; i < N; ++i) {
                if (scores[i] != score0) {
                    done = false;
                    break;
                }
            }

            if (done) {
                cout << N << " " << score0 << '\n';
                break;
            }

            start = elim % N;
        }
    }
    return 0;
}

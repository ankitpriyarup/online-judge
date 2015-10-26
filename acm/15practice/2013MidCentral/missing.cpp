#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int N, K;
    while ((cin >> N) && N != 0) {
        cin >> K;
        int page[N];
        memset(page, -1, sizeof(page));
        int c = 1;
        for (int i = 0; i < N; i += 2) {
            if (page[i] != -1) {
                break;
            }

            page[i] = c;
            page[i + 1] = c;
            page[N - 1 - i] = c;
            page[N - 2 - i] = c;
            c++;
        }

        /*
        for (int i = 0; i < N; ++i) {
            cout << page[i] << ' ';
        }

        cout << '\n';
        */
        int ans[3];
        c = 0;
        for (int i = 0; i < N; ++i) {
            if (i != K - 1 && page[i] == page[K - 1]) {
                ans[c++] = i + 1;
            }
        }

        cout << ans[0] << " " <<  ans[1] << " " << ans[2] << '\n';
    }
    return 0;
}

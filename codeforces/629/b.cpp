#include <iostream>
#include <cstring>

using namespace std;

int N;
int male[400];
int female[400];

int main() {
    char c;
    int a, b;

    memset(male, 0, sizeof(male));
    memset(female, 0, sizeof(female));
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> c >> a >> b;
        if (c == 'M') {
            for (int i = a; i <= b; ++i)
                ++male[i];
        } else {
            for (int i = a; i <= b; ++i)
                ++female[i];
        }
    }

    int ans = 0;
    for (int time = 0; time < 400; ++time) {
        ans = max(ans, 2 * min(female[time], male[time]));
    }

    cout << ans << '\n';

    return 0;
}

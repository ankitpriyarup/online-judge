#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

string have, want;
int have_count[26];
int want_count[26];
int main() {
    cin >> have;
    cin >> want;

    for (int i = 0; i < 26; i++) {
        have_count[i] = 0;
        want_count[i] = 0;
    }

    for (int i = 0; i < have.size(); i++) {
        have_count[have[i] - 'a']++;
    }

    for (int i = 0; i < want.size(); i++) {
        want_count[want[i] - 'a']++;
    }

    int ans = 0;
    for (int i = 0; i < 26; i++) {
        if (have_count[i] == 0 && want_count[i] > 0) {
            ans = -1;
            break;
        }

        if (have_count[i] > want_count[i]) {
            ans += want_count[i];
        } else {
            ans += have_count[i];
        }
    }

    cout << ans << '\n';
    return 0;
}

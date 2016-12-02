#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    int activities, rank;
    string origin, activity;
    while (T-- > 0) {
        cin >> activities >> origin;
        bool indian = origin == "INDIAN";
        long long laddu = 0LL;
        while (activities-- > 0) {
            cin >> activity;
            if (activity == "CONTEST_WON") {
                cin >> rank;
                laddu += 300 + max(0, 20 - rank);
            } else if (activity == "TOP_CONTRIBUTOR") {
                laddu += 300;
            } else if (activity == "BUG_FOUND") {
                cin >> rank;
                laddu += rank;
            } else {
                laddu += 50;
            }
        }
        int cost = indian ? 200 : 400;

        cout << (laddu / cost) << '\n';
    }
    return 0;
}

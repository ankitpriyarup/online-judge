#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    int N = s.size();

    for (int strat = 0; strat < 3; strat++) {
        bool seat_up = s[0] == 'U';
        int count = 0;
        for (int i = 1; i < N; ++i) {
            bool seat_needed = s[i] == 'U';
            if (seat_needed != seat_up) {
                count++;
            }

            seat_up = seat_needed;

            bool next_seat = (strat == 0 ? true : (strat == 1 ? false : (s[i] == 'U')));

            if (next_seat != seat_up) {
                count++;
            }

            seat_up = next_seat;
        }

        cout << count << '\n';
    }

    return 0;
}

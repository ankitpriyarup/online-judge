#include <iostream>
#include <iomanip>

using namespace std;

string s;
int main() {
    cin >> s;
    int expected = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '+') {
            expected++;
        } else {
            expected--;
        }
    }

    cin >> s;
    int actual = 0;
    int question = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '+') {
            actual++;
        } else if (s[i] == '?') {
            question++;
        } else {
            actual--;
        }
    }

    int diff = expected - actual;
    if (diff < 0) {
        diff *= -1;
    }
    double num = 0.0;
    if (diff <= question && (question - diff) % 2 == 0) {
        int plus = diff + (question - diff) / 2;
        num = 1.0;
        for (int i = plus + 1; i <= question; i++) {
            num *= i;
        }
        for (int i = 2; i <= (question - plus); i++) {
            num /= i;
        }
    }
    double denom = (1 << question) + 0.0;
    cout << fixed << setprecision(12) << (num / denom) << '\n';
    return 0;
}

#include <iostream>

using namespace std;

long long convert(double d) {
    return 100.0 * d + 0.5;
}

long long apply_rate(long long rate, long long balance) {
    long long big_thing = rate * balance;
    bool round_up = big_thing % 10000 >= 5000;

    return big_thing / 10000 + round_up;
}

int main() {
    int num_cases;
    cin >> num_cases;

    double rate_double, balance_double, salary_double;
    long long rate, balance, salary;
    while (num_cases-- > 0) {
        cin >> rate_double >> balance_double >> salary_double;
        rate = convert(rate_double);
        balance = convert(balance_double);
        salary = convert(salary_double);


        int ans = -1;
        for (int month = 1; month <= 1200; ++month) {
            balance += apply_rate(rate, balance);
            balance -= salary;

            if (balance <= 0) {
                ans = month;
                break;
            }
        }

        if (ans == -1) {
            cout << "impossible\n";
        } else {
            cout << ans << '\n';
        }
    }

    return 0;
}

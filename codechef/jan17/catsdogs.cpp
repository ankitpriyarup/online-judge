#include <iostream>

using namespace std;

int main() {
    int num_cases;
    cin >> num_cases;

    long long cats, dogs, legs;
    while (num_cases-- > 0) {
        cin >> cats >> dogs >> legs;
        long long max_legs = 4 * (cats + dogs);
        long long no_leg_cats = min(cats, 2 * dogs);
        long long min_legs = 4 * (cats + dogs - no_leg_cats);

        bool valid = min_legs <= legs and legs <= max_legs and legs % 4 == 0;

        cout << (valid ? "yes" : "no") << '\n';
    }
    return 0;
}

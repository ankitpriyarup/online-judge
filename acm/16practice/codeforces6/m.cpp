#include <iostream>

using namespace std;

bool solve(long long n) {
    long long nums[4] = {0, 0, 0, 0};
    long long primes[] = {2, 3, 5, 7};
    for (int i = 0; i < 4; ++i) {
        while (n % primes[i] == 0) {
            n /= primes[i];
            ++nums[i];
        }
    }

    long long ans = ((nums[0] + nums[1]) % 3) ^ nums[2] ^ nums[3];
    //cout << ans << '\n';
    return ans == 0;
}

int main() {
    long long n;

    while (cin >> n) {
        cout << (solve(n) ? "Ollie" : "Stan") << " wins." << '\n';
    }

    return 0;
}

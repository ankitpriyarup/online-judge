#include <iostream>
#define MAX_N 1000006

using namespace std;

int N, a, b;
string s;
long long prefix[MAX_N], suffix[MAX_N], val = 0;

int main() {
    cin >> s;
    N = s.size();
    cin >> a >> b;

    prefix[0] = (s[0] - '0') % a;
    for (int i = 1; i < N; i++) {
        val = (10 * prefix[i - 1]) % a;
        val += (s[i] - '0');
        prefix[i] = val % a;
    }

    suffix[N - 1] = (s[N - 1] - '0') % b;
    long long digit = 10;
    for (int i = N - 2; i >= 0; i--) {
        val = digit * (s[i] - '0') + suffix[i + 1];        
        suffix[i] = val % b;
        digit *= 10;
        digit %= b;
    }

    for (int i = 1; i < N; i++) {
        // i is the first character of b
        if (prefix[i - 1] == 0 && suffix[i] == 0 && s[i] != '0') {
            cout << "YES\n"; 
            for (int j = 0; j < i; j++) {
                cout << s[j];
            }
            cout << '\n';
            for (int j = i; j < N; j++) {
                cout << s[j];
            }
            cout << '\n';
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}

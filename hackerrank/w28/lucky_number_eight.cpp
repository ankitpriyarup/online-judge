#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
char s[200005];
const int MOD = 1000000007;

inline int sum(int a, int b) {
    return (0LL + a + b) % MOD;
}

inline int prod(int a, int b) {
    return (1LL * a * b) % MOD;
}

// frequency of each digit seen so far
int freq[10];

// number of subsequences ending with digit
int single_before[10];

// number of subsequences ending in a pair
int double_before[10][10];

// Given a single digit, what is the smallest multiple of 8 that
// ends in that digit?
int start[] = {0, -1, 32, -1, 24, -1, 16, -1, 8, -1};

// modular exponentiation
// computes base^exp (mod 1e9 + 7)
int modpow(int base, long long exp) {
    int ret = 1;
    int cur = base;
    
    for (long long p = 1; p <= exp; p *= 2LL) {
        if (p & exp) {
            ret = prod(ret, cur);
        }
        
        cur = prod(cur, cur);
    }
    
    return ret;
}

int main() {
    cin >> n >> s;
    
	// set everything to 0
    int ans = 0;
    memset(freq, 0, sizeof(freq));
    memset(single_before, 0, sizeof(single_before));
    memset(double_before, 0, sizeof(double_before));    
    
    for (int i = 0; i < n; ++i) {
        int digit = s[i] - '0';
        int begin = start[digit];

		// there can be a multiple of 8 ending here
        if (begin != -1) {
            // Single digit
            if (digit == 0 or digit == 8) {
                ans = sum(ans, 1);
            }
        
            // 2 digit
            for (int mult = begin; mult < 100; mult += 40) {
                ans = sum(ans, freq[mult / 10]);
            }
        
            // n digit
            for (int mult = begin; mult < 1000; mult += 40) {
                int first = mult / 100;
                int second = (mult / 10) % 10;
                ans = sum(ans, double_before[first][second]);
            }
        }
        
        for (int i = 0; i < 10; ++i) {
            double_before[i][digit] = sum(double_before[i][digit], single_before[i]);
        }
        
        freq[digit]++;
        single_before[digit] = sum(single_before[digit], modpow(2, i));
    }
    
    cout << ans << '\n';
    
    return 0;
}

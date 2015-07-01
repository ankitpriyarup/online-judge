#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int N;
char S[1000006];
int sofar[30];
int main() {
    memset(sofar, 0, sizeof(sofar));
    cin >> N;
    cin >> S;
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        int c = S[i] - 'a';
        sofar[c]++;
        ans += sofar[c];
    }
    
    cout << ans << '\n';
    return 0;
}


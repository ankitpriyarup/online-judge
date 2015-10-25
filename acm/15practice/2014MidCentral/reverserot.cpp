#include <cmath>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

char rot(char in, int n) {
    if (in == '_') {
        in = 'Z' + 1;
    } else if (in == '.') {
        in = 'Z' + 2;
    }
    
    in += n;
    if (in > 'Z' + 2) {
        in -= 'A';
        in %= 28;
        in += 'A';
    }
    if (in == 'Z' + 1) {
        return '_';
    } else if (in == 'Z' + 2) {
        return '.';
    } else {
        return in;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    char s[45];
    char t[45];
    
    while (cin >> N) {
        if (N == 0) {
            break;
        }
        
        memset(s, 0, sizeof(s));
        memset(t, 0, sizeof(t));
        cin >> s;
        
        for (int i = strlen(s) - 1, j = 0; i >= 0; i--, j++) {
            t[j] = rot(s[i], N);
        }
        
        cout << t << '\n';
    }
    
    return 0;
}

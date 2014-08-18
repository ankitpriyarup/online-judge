#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int collatz[1000005] = {0};

int findCollatz(int n) {
    int x = n;
    int count = 0;
    while(x >= 1) {
        if(x <= 1000000 && collatz[x] > 0) {
            collatz[n] = count + collatz[x];
            return collatz[n];
        } else if(x % 2 == 0) {
            x /= 2;
        } else {
            x = 3*x + 1;
        }
        count++;
    }
    collatz[n] = count;
    return count;
}

int main(){
    collatz[1] = 1;
    int a, b, best;
    while(scanf("%d %d", &a, &b) != EOF) {
        bool flip = false;
        best = 0;
        if(a > b) {
            flip = true;
            int tmp = a;
            a = b;
            b = tmp;
        }
        for(int i=a;i<=b;i++) {
            best = max(best, findCollatz(i));
        }
        if(flip) {
            printf("%d %d %d\n", b, a, best);
        } else {
            printf("%d %d %d\n", a, b, best);
        }
    }
    return 0;
}


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

char vowels[] = "aeiou";
char consonants[] = "bcdfghjklmnpqrstvwxz";
char buffer[15];

int n;

void dfs(int i, bool vowel) {
    if (i == n) {
        printf("%s\n", buffer);
        return;
    }
    
    if (vowel) {
        for (int j = 0; j < 5; ++j) {
            buffer[i] = vowels[j];
            dfs(i + 1, false);
        }
    } else {
        for (int j = 0; j < 20; ++j) {
            buffer[i] = consonants[j];
            dfs(i + 1, true);
        }
    }
}

int main() {
    scanf("%d", &n);
    dfs(0, true);
    dfs(0, false);
    return 0;
}


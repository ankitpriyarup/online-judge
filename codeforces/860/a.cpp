#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

using ll = long long;

constexpr int MAXN = 3003;
char s[MAXN];
bool add_space[MAXN];

const string vowels = "aeiou";

inline bool is_vowel(const char& c) {
    return vowels.find(c) != string::npos;
}

int main() {
    scanf("%s", s);
    int n = strlen(s);

    // add_space[i] = space before i
    for (int i = 2; i < n; ++i) {
        bool all_consonant = !is_vowel(s[i - 2]) and !is_vowel(s[i - 1]) and !is_vowel(s[i]);
        bool distinct = s[i - 2] != s[i] or s[i - 1] != s[i] or s[i - 2] != s[i - 1];
        if (all_consonant and distinct and !add_space[i - 1]) {
            add_space[i] = true;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (add_space[i]) {
            printf(" ");
        }
        printf("%c", s[i]);
    }
    printf("\n");

    return 0;
}

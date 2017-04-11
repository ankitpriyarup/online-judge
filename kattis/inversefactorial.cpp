#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1000006;
const int NHASH = 3;
const int mods[] = {1000000007, 1000000009, 1000000021};

char inp[MAXN];
int target[NHASH];
int current[NHASH];

inline int sum(const int& a, const int& b, const int& mod) {
    int c = a + b;
    if (c >= mod) {
        c -= mod;
    }

    return c;
}

inline int prod(const int& a, const int& b, const int& mod) {
    return (1LL * a * b) % mod;
}

void find_hash() {
    int n = strlen(inp);
    int bases[NHASH];
    for (int j = 0; j < NHASH; ++j)
        bases[j] = 1;

    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < NHASH; ++j) {
            target[j] = sum(target[j], prod(inp[i] - '0', bases[j], mods[j]), mods[j]);
            bases[j] = prod(bases[j], 10, mods[j]);
        }
    }
}

inline bool done() {
    for (int j = 0; j < NHASH; ++j) {
        if (current[j] != target[j])
            return false;
    }

    return true;
}

int main() {
    scanf("%s", inp);
    find_hash();

    int n = 1;
    for (int j = 0; j < NHASH; ++j) 
        current[j] = 1;

    while (!done()) {
        ++n;
        for (int j = 0; j < NHASH; ++j) {
            current[j] = prod(current[j], n, mods[j]);
        }
    }

    printf("%d\n", n);

    return 0;
}

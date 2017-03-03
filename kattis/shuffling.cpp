#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1003;

int n;
int deck[MAXN];
int temp[MAXN];

char type[10];

void out_shuffle() {
    int a = 0;
    int b = (n + 1) / 2;
    int i = 0;
    while (a < n and b < n) {
        temp[i++] = deck[a++];
        temp[i++] = deck[b++];
    }

    if (i < n) {
        temp[i] = deck[a];
    }
}

void in_shuffle() {
    int a = 0;
    int b = n / 2;
    int i = 0;
    while (a < n and b < n) {
        temp[i++] = deck[b++];
        temp[i++] = deck[a++];
    }

    if (i < n) {
        temp[i] = deck[b];
    }
}

inline void shuffle() {
    if (type[0] == 'o')
        out_shuffle();
    else
        in_shuffle();

    memcpy(deck, temp, sizeof(temp));
}

bool done() {
    for (int i = 0; i < n; ++i) {
        if (deck[i] != i)
            return false;
    }

    return true;
}

int main() {
    scanf("%d %s", &n, type); 

    for (int i = 0; i < n; ++i) {
        deck[i] = i;
    }

    shuffle();
    int moves = 1;
    while (!done()) {
        shuffle();
        ++moves;
    }

    printf("%d\n", moves);

    return 0;
}

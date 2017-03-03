#include <cstdio>

using namespace std;


int grundy[102];

int main() {
    int n;
    scanf("%d", &n);

    printf("%s\n", (n & 1) ? "Alice" : "Bob");

    return 0;
}

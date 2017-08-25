#include <cstdio>
#include <vector>

using namespace std;

constexpr int bad[] = {3, 4, 7};
constexpr int good[] = {0, 1, 2, 5, 6, 8, 9};
constexpr int flip[] = {0, 1, 2, -1, -1, 5, 9, -1, 8, 6};

int main() {
    int x;
    while (scanf("%d", &x) == 1) {
        // convert x to a base 7 string
        vector<int> v;
        while (x) {
            v.push_back(x % 7);
            x /= 7;
        }

        for (auto y : v) {
            printf("%d", flip[good[y]]);
        }
        printf("\n");
    }

    return 0;
}

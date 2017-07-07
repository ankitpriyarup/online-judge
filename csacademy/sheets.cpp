#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;

ll find_p(const ll& n, const ll& x, const ll& y, const ll& stack_size, const ll& pos) {
    printf("find_p(%lld, %lld, %lld, %lld, %lld)\n", n, x, y, stack_size, pos);
    if (x == 0 and y == 0) {
        return 1 + pos;
    }

    const ll m = n / 2LL;
    if (x < m and y < m) {
        return find_p(m, x, y, 4LL * stack_size, pos);
    } else if (x >= m and y < m) {
        long long new_pos = stack_size + stack_size - pos - 1;

        return find_p(m, n - x - 1, y, 4LL * stack_size, new_pos);
    } else if (x >= m and y >= m) {
        long long new_pos = 2 * stack_size + pos;

        return find_p(m, n - x - 1, n - y - 1, 4LL * stack_size, new_pos);
    } else {
        long long new_pos = 3 * stack_size + stack_size - pos - 1;

        return find_p(m, x, n - y - 1, 4LL * stack_size, new_pos);
    }
}

ll find_v(const ll& n, const ll& x, const ll& y, const ll& stack_size, const ll& pos, const ll& goal) {
    printf("find_v(%lld, %lld, %lld, %lld, %lld, %lld)\n", n, x, y, stack_size, pos, goal);
    if (n == goal) {
        return 1LL + n * x + y;
    }

    long long new_stack = stack_size / 4LL; 
    long long quad = pos / new_stack;
    long long new_pos = pos % new_stack;
    if (quad == 0) {
        return find_v(2 * n, x, y, new_stack, pos, goal);
    } else if (quad == 1) {
        new_pos = new_stack - new_pos - 1;

        return find_v(2 * n, 2 * n - x - 1, y, new_stack, new_pos, goal);
    } else if (quad == 2) {
        return find_v(2 * n, 2 * n - x - 1, 2 * n - y - 1, new_stack, new_pos, goal);
    } else {
        new_pos = new_stack - new_pos - 1;

        return find_v(2 * n, x, 2 * n - y - 1, new_stack, new_pos, goal);
    }
}

int main() {
    int q;
    scanf("%d", &q);
    
    int type;
    long long k, v;
    while (q-- > 0) {
        scanf("%d %lld %lld", &type, &k, &v);
        long long n  = (1LL << k);

        if (type == 1) {
            printf("%lld\n", find_p(n, (v - 1) / n, (v - 1) % n, 1, 0));
        } else {
            printf("%lld\n", find_v(1, 0, 0, n * n, v - 1, n));
        }
    }
    return 0;
}

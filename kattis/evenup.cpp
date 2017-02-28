#include <cstdio>
#include <stack>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    stack<int> s;

    int x;
    while (n-- > 0) {
        scanf("%d", &x);
        if (!s.empty() and (s.top() % 2) == (x % 2)) {
            s.pop();
        } else {
            s.push(x);
        }
    }

    printf("%lu\n", s.size());
    return 0;
}

#include <iostream>

using namespace std;

int A, M;
bool seen[100005];
int main() { 
    cin >> A >> M;
    seen[0] = true;
    while (!seen[A]) {
        seen[A] = true;
        A += (A % M);
        A %= M;
    }
    cout << (A == 0 ? "Yes" : "No") << '\n';
    return 0;
}

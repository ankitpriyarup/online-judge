#include <iostream>
 
using namespace std;

int rev(int x) {
    int ret = 0;
    while(x > 0) {
        ret *= 10;
        ret += x % 10;
        x /= 10;
    }
    return ret;
}

int main(){
    int N, a, b;

    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> a >> b;
        cout << rev(rev(a) + rev(b)) << '\n';
    }
    return 0;
}

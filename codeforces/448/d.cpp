#include <iostream>
typedef long long ll;
using namespace std;

ll N, M, K;

ll get_index(ll v) {
    // return number of values less than or equal to v
    ll count = 0;
    for(int i=1;i<=N;i++) {
        count += min(M, (v - 1LL) / i);
    }
    return count;
}

int main() {
    cin >> N >> M >> K;
    ll lo = 1LL;
    ll hi = 1*N*M + 1;
    while(hi - lo > 1) {
        ll mid = (lo + hi) / 2LL;
        ll ind = get_index(mid);
//        cout << "lo: " << lo << " hi: " << hi << '\n';
//        cout << "mid: " << mid << " ind: " << ind << '\n';
        if(ind < K) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    cout << lo << '\n';
    return 0;
}

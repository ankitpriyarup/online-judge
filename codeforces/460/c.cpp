#include <iostream>
#include <cstring>
typedef long long ll;
using namespace std;
int N, M, W;
int a[100010];
int b[100010];

bool valid(ll test) {
    int cbuf = 0;
    int water = 0;
    memset(b, 0, sizeof(b));
    for(int i=0;i<N;i++) {
        if(i-W >= 0) {
            cbuf -= b[i-W];
        }
        if(a[i] + cbuf < test) {
            int diff = test - (a[i] + cbuf);
            cbuf += diff;
            water += diff;
            b[i] = diff;
        }
        if(water > M) {
            return false;
        }
    }
    return water <= M;
}

int main() {
    cin >> N >> M >> W;
    for(int i=0;i<N;i++) {
        cin >> a[i];
    }
    ll l = 0LL;
    ll r = 1000000000 + 100000 + 10;
    ll ans = 0;
    while(l <= r) {
        ll mid = (l + r) >> 1;
        if(valid(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}

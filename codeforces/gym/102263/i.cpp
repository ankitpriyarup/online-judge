#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
 
int main() {
	int n;
	cin >> n;
	vi a(n);
	for (auto& x : a) {
		cin >> x;
	}
	sort(begin(a), end(a));
	ll ans = a.back() - a[0];
	ll pref = a[0];
	ll suff = a[n - 1];
	
	int pref_size = 1;
	int suff_size = 1;
	
	cout << ans;
	for (int i = 1; i < n - 1; ++i) {
	    int idx;
	    if (i % 2 == 1) {
	        idx = (i + 1) / 2;
	        pref += a[idx];
	        ++pref_size;
	    } else {
	        idx = n - 1 - (i / 2);
	        suff += a[idx];
	        ++suff_size;
	    }
	    
	    ans += 1LL * pref_size * a[idx] - pref;
	    ans += suff - 1LL * suff_size * a[idx];
	    
	    cout << ' ' << ans;
	}
	
	return 0;
}

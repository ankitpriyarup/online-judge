#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int N;
    string s;
    int counts[30];
    cin >> N;
    for(int t=0;t<N;t++) {
        for(int i=0;i<30;i++) {
            counts[i] = 0;
        }
        cin >> s;
        int K = s.size();
        int distinct = 0;
        for(int i=0, j=K;i<K;i++, j--) {
            if(counts[s[i] - 'A'] == 0) {
                distinct++;
            }
            counts[s[i] - 'A'] += j;
        }
        string ans;
        while(distinct > 0) {
            int best = 0;
            string out;
            for(int i=0;i<30;i++) {
                if(counts[i] > best) {
                    out = (i + 'A');
                    best = counts[i];
                } else if(counts[i] == best) {
                    out += (i + 'A');
                }
            }
            ans += out;
            distinct -= out.size();
            for(int i=0;i<out.size();i++) {
                counts[out[i] - 'A'] = -1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

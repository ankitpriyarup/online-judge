#include <iostream>
#include <set>

using namespace std;
int N, P;
string s;
int main() {
    cin >> N;
    while(N > 0) {
        cin >> s;
        int L = s.size();
        int occupied = 0;
        set<char> visitors;
        set<char> left;
        for(int i=0;i<L;i++) {
            if(visitors.count(s[i]) != 0) {
                visitors.erase(s[i]);
                occupied--;
            } else if(left.count(s[i]) != 0) {
                continue;
            } else {
                if(occupied == N) {
                    left.insert(s[i]); 
                } else {
                    visitors.insert(s[i]); 
                    occupied++;
                }
            }
        }
        int ans = left.size();
        if(ans == 0) {
            cout << "All customers tanned successfully." << endl;
        } else {
            cout << ans << " customer(s) walked away." << endl;
        }
        cin >> N;
    }
}

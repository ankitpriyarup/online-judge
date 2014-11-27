#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;
int T;
string s;

int main() {
    cin >> T;
    for(int ll=1;ll<=T;ll++) {
        vector<int> ans;
        cin >> s;
        int N = s.size();
        if(s[1] == '1') {
            ans.push_back(1);            
        }
        for(int i=2;i<N;i++) {
            bool shouldBe = 0;
            for(vector<int>::iterator it = ans.begin(); it!=ans.end(); it++) {
                shouldBe = (i % (*it) == 0) ? !shouldBe : shouldBe;
            }
            if((shouldBe && s[i] == '0') || (!shouldBe && s[i] == '1')) {
                ans.push_back(i);
            }
        }
        cout << ans[0];
        for(int i=1;i<ans.size();i++) {
            cout << " " << ans[i];
        }
        cout << '\n';
    }
    return 0;
}

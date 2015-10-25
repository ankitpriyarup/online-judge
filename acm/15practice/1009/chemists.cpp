#include <iostream>
#include <cstring>
#include <sstream>
#include <set>

using namespace std;

set<string> symbols;
string s;
bool dp[50005];

bool solve() {
    memset(dp, 0, sizeof(dp));
    dp[s.size()] = 1;
    for (int i = s.size() - 1; i >= 0; --i) {
        // see if you can do it!
        if (dp[i + 1] && symbols.find(s.substr(i, 1)) != symbols.end()) {
            dp[i] = 1;
        }

        if (dp[i + 2] && symbols.find(s.substr(i, 2)) != symbols.end()) {
            dp[i] = 1;
        }
    }

    return dp[0];
}

int main() {
    string chemicals = "h he li be b c n o f ne na mg al si p s cl ar k ca sc ti v cr mn fe co ni cu zn ga ge as se br kr rb sr y zr nb mo tc ru rh pd ag cd in sn sb te i xe cs ba hf ta w re os ir pt au hg tl pb bi po at rn fr ra rf db sg bh hs mt ds rg cn fl lv la ce pr nd pm sm eu gd tb dy ho er tm yb lu ac th pa u np pu am cm bk cf es fm md no lr";

    istringstream iss(chemicals);
    while (iss) {
        iss >> s;
        symbols.insert(s);
    }

    int T;
    cin >> T;
    while (T-- > 0) {
        cin >> s;
        
        cout << (solve() ? "YES" : "NO") << '\n';
    }
    return 0;
}

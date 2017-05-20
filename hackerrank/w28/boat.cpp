#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, m, c;
    cin >> n >> m >> c;
    int capacity = m * c;
    
    int max_group = 1;
    int group;
    
    while (n-- > 0) {
        cin >> group;
        max_group = max(max_group, group);
    }
    
    cout << (max_group <= capacity ? "Yes" : "No") << '\n';
    
    return 0;
}


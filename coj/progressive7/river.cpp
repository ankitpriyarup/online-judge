#include <iostream>

using namespace std;
int N;
int weights[6];
int main() {
    cin >> N;
    for(int ll=0;ll<N;ll++) {
        int sum = 0;
        for(int i=0;i<6;i++) {
            cin >> weights[i];
            sum += weights[i];
        }
        bool works = false;
        for(int mask=1;mask < (1 << 6); mask++) {
            int boat = 0;
            for(int pos=0, i=1;i<=mask;i*=2, pos++) {
                if(mask & i) {
                    boat += weights[pos];
                }
            }
            if(2*boat == sum) {
                works = true;
                break;
            }
        }
        if(works) {
            cout << "Tobby puede cruzar" << endl;
        } else {
            cout << "Tobby no puede cruzar" << endl;
        }
    }
    return 0;
}

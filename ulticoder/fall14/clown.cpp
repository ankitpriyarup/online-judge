#include <iostream>

using namespace std;

int N;
int main() {
    cin >> N;
    string message;
    for (int i = 0; i < N; i++) {
        int count = 0;
        cin >> message;
        while (message[0] != '.') {
            count++;
            cin >> message;
        }
        
        if (count % 2 == 0) {
            cout << "Gary";
        } else {
            cout << "Larry";
        }
        cout << " won the argument!" << endl;
    }
}

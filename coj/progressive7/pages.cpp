#include <iostream>

using namespace std;
int N, P;
int pages[1010];
int main() {
    cin >> N;
    while(N > 0) {
        cin >> P;
        for(int front=1, back=N, id=0;front < back;front += 2, back -= 2, id++) {
            pages[front] = pages[front + 1] = pages[back] = pages[back - 1] = id;
        }
        int id = pages[P];
        bool already = false;
        for(int i=1;i<=N;i++) {
            if(i != P && pages[i] == id) {
                if(already) {
                    cout << " ";
                }
                cout << i;
                already = true;
            }
        }
        cout << endl;
        cin >> N;
    }
}

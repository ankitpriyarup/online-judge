//Problem        : Excel Wizard
//Language       : C++11
//Compiled Using : g++
//Version        : GCC 4.9.1
//Input for your program will be provided from STDIN
//Print out all output from your program to STDOUT

#include <iostream>
#include <string>
#include <algorithm>
#include <climits> 

using namespace std;

char to_letter(int n) {
    return n + 'A';
}

int main() {
    int N;
    cin >> N;
    string ans = "";
    
    while (N > 0) {
        N--;
        int end = N % 26;
        
        ans = to_letter(end) + ans;
        N /= 26;
    }
    cout << ans << '\n';
    return 0;
}

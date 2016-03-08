#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>

using namespace std;

bool booked[101][33];
int N;

bool available(int room, int start, int len) {
    for (int i = start; i < start + len; ++i) {
        if (booked[room][i]) return false;
    }

    return true;
}

string book(int room, int start, int len) {
    if (available(room, start, len)) {
        for (int i = start; i < start + len; ++i) {
            booked[room][i] = true;
        }

        return "Y";
    } else {
        return "N";
    }
}

string query(int start, int len) {
    vector<int> ans;
    for (int i = 0; i < N; ++i) {
        if (available(i, start, len)) {
            ans.push_back(i); 
        }
    }

    if (ans.size() == 0) {
        return "None";
    }
    
    string out = "" + to_string(ans[0] + 1);
    for (int i = 1; i < (int)ans.size(); ++i) {
        out += " " + to_string(ans[i] + 1);
    }

    return out;
}

void process(string &line) {
    int inp[3];
    istringstream iss(line);
    int l = 0;
    string x;
    while (!iss.eof()) {
        getline(iss, x, '-');
        inp[l++] = stoi(x);
    }

    if (l == 3) {
        inp[0]--;
        inp[1]--;
        cout << book(inp[0], inp[1], inp[2]) << '\n';
    } else {
        inp[0]--;
        cout << query(inp[0], inp[1]) << '\n';
    }
}

int main() {
    cin >> N;
    string line;
    getline(cin, line);
    memset(booked, 0, sizeof(booked));
    while (!cin.eof()) {
        getline(cin, line);
        if (line.size() > 0) {
            process(line);
        }
    }

    return 0;
}

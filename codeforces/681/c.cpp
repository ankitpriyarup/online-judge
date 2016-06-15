#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>

using namespace std;

vector<pair<string, int> > output;

int main() {
  int n, v;
  cin >> n;
  string command;
  priority_queue<int, vector<int>, greater<int> > pq;
  for (int i = 0; i < n; ++i) {
    cin >> command;
    if (command == "insert") {
      cin >> v;
      pq.push(v);
      output.push_back(make_pair("insert", v));
    } else if (command == "getMin") {
      cin >> v;
      while (!pq.empty() and pq.top() < v) {
        pq.pop();
        output.push_back(make_pair("removeMin", 0));
      }
      if (pq.empty() or pq.top() > v) {
        pq.push(v);
        output.push_back(make_pair("insert", v));
      }
      output.push_back(make_pair("getMin", v));
    } else if (command == "removeMin") {
      if (pq.empty()) {
        output.push_back(make_pair("insert", 1));
      } else {
        pq.pop();
      }
      output.push_back(make_pair("removeMin", 0));
    }
  }

  cout << output.size() << '\n';
  for (auto s : output) {
    if (s.first[0] == 'r')
      cout << s.first << '\n';
    else
      cout << s.first << ' ' << s.second << '\n';
  }
  return 0;
}

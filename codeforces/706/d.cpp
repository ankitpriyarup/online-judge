#include <iostream>
#include <cstring>
#define MAXN 6000000

using namespace std;

int trie[MAXN][2];
int trie_count[MAXN];
int trie_size = 1;

void insert(int n) {
  int node = 0;
  for (int i = 30, j = (1 << 30); i >= 0; --i, j >>= 1) {
    bool bit = (n & j);
    if (trie[node][bit] == -1) {
      trie[node][bit] = trie_size++;
    }

    trie_count[node] += 1;
    node = trie[node][bit];
  }
  trie_count[node] += 1;
}

void remove(int n) {
  int node = 0;
  for (int i = 30, j = (1 << 30); i >= 0; --i, j >>= 1) {
    bool bit = (n & j);
    trie_count[node] -= 1;
    node = trie[node][bit];
  }
  trie_count[node] -= 1;
}

int query(int n) {
  int node = 0;
  int ans = 0;
  for (int i = 30, j = (1 << 30); i >= 0; --i, j >>= 1) {
    bool bit = (n & j);
    int next_node = trie[node][1 - bit];
    if (next_node == -1 || trie_count[next_node] == 0) {
      next_node = trie[node][bit];
      if (bit) {
        ans |= j;
      }
    } else if (!bit) {
      ans |= j;
    }

    node = next_node;
  }

  return ans ^ n;
}

int main() {
  char op;
  int n, q;

  cin >> q;
  memset(trie, -1, sizeof(trie));
  insert(0);

  while (q-- > 0) {
    cin >> op >> n;  
    switch(op) {
      case '+':
        insert(n);
        break;
      case '-':
        remove(n);
        break;
      case '?':
        cout << query(n) << '\n';
        break;
    }
  }

  return 0;
}
